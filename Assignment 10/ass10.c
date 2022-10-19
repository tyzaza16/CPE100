#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int read_normal(char *filename,int data[],int *count){
	FILE *fp;
	int a;
	*count=0;
	if( (fp = fopen(filename,"r")) !=NULL ){
		while(feof(fp)==0){
			while(fscanf(fp,"%d",&a) ==1 ){
			data[*count] = a;
			*count = *count +1;
			}
		}
		fclose(fp);
		printf("Read test file %s %d records complete\n",filename,*count);
		return *count;
	}else{
		printf("Error\n");
		return 0;
	}
}
int read_binary(char *filename,int data[],int *count){
	FILE *fp;
	int a;
	*count=0;
	int size;
	if( (fp = fopen(filename,"rb"))!= NULL ){
		size = 100050;
		*count = fread(data,sizeof(int),size,fp);
		fclose(fp);
		printf("Read test file %s %d records complete\n",filename,*count);
		return *count;
	}else{
		printf("Error\n");
		return 0;
	}
}

void Compare_scan(int data1[],int count1,int data2[],int count2)
{	int i=0,j=0,k=0;
		for(i=0;i<count1;i++)
			for(j=0;j<count2;j++)
				if(data1[i] == data2[j])
				{	k++;
					printf("Found [%d] = %d\n",k,data1[i]);
				}	
}

int comparator(const void *a,const void *b)
{	
	return( *(int*)a - *(int*)b );
}

void Compare_binsearch(int data1[],int count1,int data2[],int count2)
{	int i,k;
		for(i=0,k=0;i<count1;i++)
			if((int*)bsearch(&data1[i],data2,count2,sizeof(int),comparator)!=NULL)
			{	k++;
				printf("Found [%d] = %d\n",k,data1[i]);
			}
}

void Compare_Reference(int data1[],int count1,int data2[],int count2)
{	int i=0,j=0,k=0;
	do
	{	if(data1[i]<data2[j])
			i++;
		else if (data1[i]>data2[j])
			j++;
		else
		{	k++;
			printf("Found [%d] = %d\n",k,data1[i]);
			i++; j++;
		}
	}while(i<count1 && j<count2);
}

int main(){
	int data1[100010],data2[100010],count1,count2;
	double sec;
	clock_t start, end;

	read_normal("txt100000.txt",data1,&count1);
	read_binary("bin100000.bin",data2,&count2);
	start = clock();//เริ่มจับเวลา
	Compare_scan(data1,count1,data2,count2);
	end = clock();
	sec = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Compare_basicscan is use %g sec \n",sec);

    read_normal("txt100000.txt",data1,&count1);
	read_binary("bin100000.bin",data2,&count2);
	start = clock();
	qsort(data2,count2,sizeof(int),comparator);
	Compare_binsearch(data1,count1,data2,count2);
	end = clock();
	sec = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Compare_binarysearch is use %g sec \n",sec);

    read_normal("txt100000.txt",data1,&count1);
	read_binary("bin100000.bin",data2,&count2);
	start = clock();
	qsort(data1,count1,sizeof(int),comparator);
	qsort(data2,count2,sizeof(int),comparator);
	Compare_Reference(data1,count1,data2,count2);
	end = clock();
	sec = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Compare_Reference is use %g sec \n",sec);
	return 0;
}