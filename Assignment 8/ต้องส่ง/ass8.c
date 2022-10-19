#include <stdio.h>
#include <math.h>
double check(double min,double max){
	double value;
	char ch;
	while(scanf("%lf%c",&value,&ch) != 2 || value < min || value > max || ch != '\n'){
		rewind(stdin);
		printf("\nInvalid Input, Please Try again");
	}
	return value;
}
double get_menu()
{
	double select; // กำหนดตัวแปร
	printf("**************************************************\n");
	printf("                    My Function                   \n");
	printf("**************************************************\n");
	printf("                 1. Add Data                      \n");
	printf("                 2. Delete Data                   \n");
	printf("                 3. Stats Calculate               \n");
	printf("                 0. Exit                          \n");
	printf("**************************************************\n");
	printf("Select The Test Series that You want to test :  "); // ให้ผู้ใช้เลือกฟังก์ชั่น(ถามคำถาม)
	select = check(0,3); //ส่งค่าไปคิดที่ฟังก์ชั่นตรวจสอบค่า
	return select; // return ค่าที่ได้จากฟังก์ชั่นนี้
}
void Add_data(double data[],int *count){
	double value;
	char ch;
	printf("\n*************************************************\n");
	printf("                   Description                   \n");
	printf("*************************************************\n");
	printf("Enter the number Until You want to exit print 'E'\n");
	printf("*************************************************\n");
	printf("Enter the number [%d]: ",*count);
	    while(scanf("%lf",&value)==1||ch == '\n')
	    {
	    	if(value > 0){
	        data[*count] = value;
	    	*count = *count+1;
	    	printf("Enter the number [%d]: ",*count);
	    }
	    	else{
	    		printf("Invalid Input, please try again.\n");
	    		printf("Enter the number [%d]: ",*count);
	    	}
		}
	rewind(stdin);
	printf("=================================================\n");
	}
void Print_data(double data[],int count)
{
	int i;
	printf("*************************************************\n");
	printf("       >>>          Print Data           <<<     \n");
	printf("*************************************************\n");
	if(count>0){
		for(i=0;i<count;i++){
			printf("Data [%d] : %lf\n", i,data[i]);
		}
		printf("=============>>   End OF DATA   <<===============\n");}
	else
		printf("\n----------    Don't have Data.    ---------\n\n");


}
void Calculate_stat(double data[],int count,double *mean,double *sd,double *min,double *max){
	int i;
	double sum=0,sum2=0;
	*min = data[0];
	*max = data[0];
	for(i=0;i<count;i++){
		sum += data[i];
		sum2 += data[i]*data[i];
		if(data[i]<*min){
			*min = data[i];
		}
	    if(data[i]>*max){
			*max = data[i]; 
		}
	}
	*mean = sum/count;
	*sd = sqrt(sum2/count - *mean**mean);
}
void Delete_data(double data[],int *count,int id){
	int i;
		for(i=id;i<*count-1;i++){
			data[i] = data[i+1];
		}
		*count = *count-1;
	}
int search_index(double data[],int count,double del){
	int i;
	for(i=0;i<count;i++){
		if(data[i] == del)
			return i;
	}
	return -1;
}
int main(){
	double select,data[100],mean=0,sd=0,min,max,del;
	int count = 0,id;
	char ch;
	do{
	select = get_menu();
	if(select == 1){
		Add_data(data,&count);
		Print_data(data,count);
		}
	else if(select == 2){
		if(count > 0){
			printf("Enter the value that you want to delete : ");
			scanf("%lf",&del);
			do{
				id = search_index(data,count,del);
				printf("%d\n",id);
				if(id>=0){
					printf("Are you sure to delete %lf[%d]? [y/n] : ",del,id);
					scanf(" %c",&ch);
					if(ch == 'y'){
						Delete_data(data,&count,id);
						Print_data(data,count);
					}
					else
					printf("\n-----------    Cancel Delete.    ----------\n\n");
				}
				id = search_index(data,count,del);//check ซ้ำว่าค่าที่ต้องการลบนั้นยังเหลืออยู่ไหม
			}while(id!=-1 && ch == 'y' && count>1);
		}
		else
			printf("\n==>>> Don't Have data to delete \n");
	}
	else if(select == 3){
		if(count > 1){
			Print_data(data,count);
			Calculate_stat(data,count,&mean,&sd,&min,&max);
			printf("Mean of numbers  = %lf\n",mean);
			printf("S.D. of numbers  = %lf\n",sd);
			printf("Min of numbers = %lf , Max of numbers = %lf\n",min,max);
		}
		else

			printf("\n==>>> Don't Have Data to Calculate (Need 2 Data at least.)\n");
		}
	}while(select != 0);
	printf("\n\n   ===>>>          End Program.           <<<=== \n");
}