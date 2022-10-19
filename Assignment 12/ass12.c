#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct grade_info{
	long long id;
	char name[40];
	double mid,final,attn,total,gpoint;
	char grade[3];
}student_type;

int get_int(int min,int max){//ฟังก์ชันสำหรับตรวจสอบความผิดพลาดในการป้อนข้อมูล
	int check;
	char ch;
	while(scanf("%d%c",&check,&ch)==0 || check>max || check<min){
		rewind(stdin);
		printf("Invalid input, please try again\n");
	}
	return check;
}
int get_menu(){
	int select;
	printf("***This is program calculate score****\n");
	printf("*1.Show information \n");//แสดงข้อมูลทั้งหมด
	printf("*2.Show score from much to less\n");//แสดงคะแนนจากมากไปน้อย
	printf("*3.Show order ID number\n");//แสดงลำดับรหัสบัตรประจำตัว
	printf("*4.Search and show score range\n");//หาและแสดงคะแนนช่วงที่ต้องการ
	printf("*5.Show grade that requirement\n");//แสดงคนที่ได้เกรดตามที่กำหนด
	printf("*6.Search and show some part of name\n");//ค้นหาและแสดงบางส่วนของชื่อ
	printf("Please select number : ");
	select = get_int(0,6);
	return select;
}
int Read_File(char *name,student_type st[]){
	int count;
	student_type x;
	FILE *fp;
	fp = fopen(name,"r");
	if(fp!=NULL){
		while( fscanf(fp,"%llu,%[^,],%lf,%lf,%lf%*c",&x.id,x.name,&x.mid,&x.final,&x.attn)==5 ){
		//%*c = อ่านทิ้งไปไม่เก็บ
			x.total = x.mid + x.final +x.attn;
			st[count++] = x; 
		}
		fclose(fp);
		return count;
	}else{
		return 0;
	}
}
void Set_grade(student_type st[],int stcount,double A,double Bp,double B,double Cp,double C,
											double Dp,double D)
{
	for(int i=0;i<stcount;i++){
		if(st[i].total >= A){ st[i].gpoint = 4.0;   strcpy(st[i].grade,"A");}
		else if(st[i].total >= Bp){ st[i].gpoint = 3.5;   strcpy(st[i].grade,"B+");}
		else if(st[i].total >= B){ st[i].gpoint = 3.0;   strcpy(st[i].grade,"B");}
		else if(st[i].total >= Cp){ st[i].gpoint = 2.5;   strcpy(st[i].grade,"C+");}
		else if(st[i].total >= C){ st[i].gpoint = 2.0;   strcpy(st[i].grade,"C");}
		else if(st[i].total >= Dp){ st[i].gpoint = 1.5;   strcpy(st[i].grade,"D+");}
		else if(st[i].total >= D){ st[i].gpoint = 0.5;   strcpy(st[i].grade,"D");}
		else { st[i].gpoint = 0.0;   strcpy(st[i].grade,"F");}
		 
	}
}
void Print_1_student(int i,student_type x){
	printf("%2d) %llu %-40s %7.1lf %7.1lf %7.1lf %7.1lf %5.1lf     %s\n",i ,x.id, x.name, 
		x.mid, x.final, x.attn, x.total, x.gpoint, x.grade);
}
void Print_all_student(student_type st[],int count){
	printf("        id                          Name                     mid   fianl    attn   total  gpoint grade\n\n");
	for(int i=0;i<count;i++){
		Print_1_student(i+1,st[i]);
	}
}
void Find_Statistic_mid(student_type st[],int stcount,double *min_mid,double *max_mid,double *mean_mid,double *sd_mid){
	int i;
	double sum =0,sumsqr=0;
	*min_mid = *max_mid = st[0].mid;
	for(i=0;i<stcount;i++){
		if(st[i].mid < *min_mid){
			*min_mid = st[i].mid;
		}
		if(st[i].mid > *max_mid){
			*max_mid = st[i].mid;
		}
		sum = sum + st[i].mid;
		sumsqr = sumsqr + pow(st[i].mid,2);
	}
	*mean_mid = sum/stcount;
	*sd_mid = sqrt(sumsqr/stcount - pow(*mean_mid,2));
}
void Find_Statistic_final(student_type st[],int stcount,double *min_final,double *max_final,double *mean_final,double *sd_final){
	int i;
	double sum =0,sumsqr=0;
	*min_final = *max_final = st[0].final;
	for(i=0;i<stcount;i++){
		if(st[i].final < *min_final){
			*min_final = st[i].final;
		}
		if(st[i].final > *max_final){
			*max_final = st[i].final;
		}
		sum = sum + st[i].final;
		sumsqr = sumsqr + pow(st[i].final,2);
	}
	*mean_final = sum/stcount;
	*sd_final = sqrt(sumsqr/stcount - pow(*mean_final,2));
}
void Find_Statistic_attn(student_type st[],int stcount,double *min_attn,double *max_attn,double *mean_attn,double *sd_attn){
	int i;
	double sum =0,sumsqr=0;
	*min_attn = *max_attn = st[0].attn;
	for(i=0;i<stcount;i++){
		if(st[i].attn < *min_attn){
			*min_attn = st[i].attn;
		}
		if(st[i].attn > *max_attn){
			*max_attn = st[i].attn;
		}
		sum = sum + st[i].attn;
		sumsqr = sumsqr + pow(st[i].attn,2);
	}
	*mean_attn = sum/stcount;
	*sd_attn = sqrt(sumsqr/stcount - pow(*mean_attn,2));
}
void Find_Statistic_total(student_type st[],int stcount,double *min_total,double *max_total,double *mean_total,double *sd_total){
	int i;
	double sum =0,sumsqr=0;
	*min_total = *max_total = st[0].total;
	for(i=0;i<stcount;i++){
		if(st[i].total < *min_total){
			*min_total = st[i].total;
		}
		if(st[i].total > *max_total){
			*max_total = st[i].total;
		}
		sum = sum + st[i].total;
		sumsqr = sumsqr + pow(st[i].total,2);
	}
	*mean_total = sum/stcount;
	*sd_total = sqrt(sumsqr/stcount - pow(*mean_total,2));
}
void Print_Statistic(double min_mid,double min_final,double min_attn,double min_total,
					double max_mid,double max_final,double max_attn,double max_total,
					double mean_mid,double mean_final,double mean_attn,double mean_total,
					double sd_mid,double sd_final,double sd_attn,double sd_total)
{
	printf("score   mid   final  attn  total\n");
	printf("min  %7.2lf %7.2lf %7.2lf %7.2lf\n",min_mid,min_final,min_attn,min_total);
	printf("max  %7.2lf %7.2lf %7.2lf %7.2lf\n",max_mid,max_final,max_attn,max_total);
	printf("mean %7.2lf %7.2lf %7.2lf %7.2lf\n",mean_mid,mean_final,mean_attn,mean_total);
	printf("sd   %7.2lf %7.2lf %7.2lf %7.2lf\n",sd_mid,sd_final,sd_attn,sd_total);
}
void Find_Number_Get_Grade(student_type st[],int stcount,double *num_A,double *num_Bp,
									double *num_B,double *num_Cp,double *num_C,
									double *num_Dp,double *num_D,double *num_F,double *grade_average)
{
	double a;
	for(int i=0;i<stcount;i++){
		if(strcmp(st[i].grade,"A")==0){   *num_A = *num_A + 1;    }
		else if(strcmp(st[i].grade,"B+")==0){  *num_Bp = *num_Bp + 1;  }
		else if(strcmp(st[i].grade,"B")==0){   *num_B = *num_B + 1;  }
		else if(strcmp(st[i].grade,"C+")==0){  *num_Cp = *num_Cp + 1;  }
		else if(strcmp(st[i].grade,"C")==0){   *num_C = *num_C + 1;  }
		else if(strcmp(st[i].grade,"D+")==0){  *num_Dp = *num_Dp + 1;  }
		else if(strcmp(st[i].grade,"D")==0){   *num_D = *num_D + 1;  }
		else{   *num_F = *num_F + 1;  }
		a = a + st[i].gpoint;
	}*grade_average = a/stcount;
}
void Print_Number_Get_Grade(double num_A,double num_Bp,double num_B,double num_Cp,double num_C,double num_Dp,double num_D,double num_F){
	printf("\n          A      B+     B      C+     C      D+     D     F\n");
	printf("Count  %5.1lf  %5.1lf  %5.1lf  %5.1lf  %5.1lf  %5.1lf  %5.1lf  %5.1lf\n",
	 		num_A,num_Bp,num_B,num_Cp,num_C,num_Dp,num_D,num_F);
}
void Sort_Much_To_Less (student_type st[], int stcount)
{ 
	int i, j ;
	student_type x;
	for(i = 0; i < stcount-1; i++){
		for (j = i+1; j < stcount; j++){ // j = scan index
			if (st[j].total > st[i].total){ //เรียงจากมากไปน้อย 
					x = st[i]; //swap data
					st[i] = st[j];
					st[j] = x; 
			}
		}
	} // i = reference index
		
}
void Sort_Id (student_type st[], int stcount)
{ 
	int i, j ;
	student_type x;
	for (i = 0; i < stcount-1; i++){ // i = reference index
		for (j = i+1; j < stcount; j++){ // j = scan index
			if (st[j].id < st[i].id){ //Ascending Sort
			 	x = st[i]; // swap data
				st[i] = st[j];
				st[j] = x; 
			}
		}
	}
}
void Search_Score (student_type st[], int stcount)
{ 
	double min, max;
	int i , count;
	char ch ;
	do{ 
		printf("\nEnter Range of min score and max score :");
		scanf("%lf %lf", &min , &max); // อ่านค่า min max
		count = 0;
		for(i=0; i<stcount; i++){ 
			if (st[i].total >= min && st[i].total <= max){ 
				count = count + 1;
				Print_1_student(count,st[i]);
			}
		}
			printf("\n\n Do you want to search again ? ");
		scanf(" %c",&ch);
	}while (ch == 'y');
}
void Search_Grade(student_type st[], int stcount){ 
	char key[3];
	int i , count ;
	do {printf("\nSearch Grade (A, B+, B, ... F or 0 = Exit) ");
		scanf("%2s", key); // อ่านสตริงไม่เกิน 2 ตัวอักษร
		count = 0;
		if (strcmp(key,"0") != 0){
			for (i = 0; i<stcount; i++){
				if (strcmp(st[i].grade,key)==0){
					count = count + 1;
					Print_1_student(count,st[i]);
				}
			}	
		}
	}while (strcmp(key, "0") !=0);
}
void Search_Name (student_type st[], int stcount){ 
	char key[16];
	int i, count;
	do{
		printf("\nEnter Search key (0 = Exit) ");
		scanf("%15s", key); // อ่านสตริงไม่เกิน 15 ตัวอักษร
		count = 0;
		if (strcmp(key,"0") != 0){
			for (i = 0; i<stcount; i++){
				if (strstr(st[i].name, key) != NULL){ //ถา้คน้ บางสว่ นเจอ
				count = count + 1;
				Print_1_student(count,st[i]);
				}
			}
		}
	}while(strcmp(key,"0")!=0);
}
int main(){
	student_type st[100];
	char ch;
	int stcount ,i, select, A,Bp,B,C,Cp,Dp,D;
	double grade_average; 
	double min_mid,min_final,min_attn,min_total; 
	double max_mid,max_final,max_attn,max_total;
	double mean_mid,mean_final,mean_attn,mean_total;
	double sd_mid,sd_final,sd_attn,sd_total;
	double num_A,num_Bp,num_B,num_Cp,num_C,num_Dp,num_D,num_F;
	stcount = Read_File("score.csv",st);//เช็คว่าอ่านได้มั้ย
	printf("***This is program calculate score****\n");
	printf("Put Grading A B+ B C+ C D+ D : ");
	scanf("%d %d %d %d %d %d %d",&A,&Bp,&B,&Cp,&C,&Dp,&D);
	Set_grade(st,stcount,A,Bp,B,Cp,C,Dp,D);
	printf("total read %d records\n",stcount);
	Find_Statistic_mid(st,stcount,&min_mid,&max_mid,&mean_mid,&sd_mid);
	Find_Statistic_final(st,stcount,&min_final,&max_final,&mean_final,&sd_final);
	Find_Statistic_attn(st,stcount,&min_attn,&max_attn,&mean_attn,&sd_attn);
	Find_Statistic_total(st,stcount,&min_total,&max_total,&mean_total,&sd_total);
	Print_Statistic(min_mid,min_final,min_attn,min_total,max_mid,max_final,max_attn,
					max_total,mean_mid,mean_final,mean_attn,mean_total,sd_mid,sd_final,
					sd_attn,sd_total);
	Find_Number_Get_Grade(st,stcount,&num_A,&num_Bp,&num_B,&num_Cp,&num_C,&num_Dp,&num_D,&num_F,&grade_average);
	Print_Number_Get_Grade(num_A,num_Bp,num_B,num_Cp,num_C,num_Dp,num_D,num_F);
	printf("Average GPA = %lf\n",grade_average);
	do{ select = get_menu();
		if(select!=0){
			if(select == 1){//แสดงข้อมูลทั้งหมด
				Print_all_student(st,stcount);
			}else if(select == 2){//แสดงคะแนนจากมากไปน้อย
				Sort_Much_To_Less(st,stcount);
				Print_all_student(st,stcount);
			}else if(select == 3){//แสดงลำดับรหัสบัตรประจำตัว
				Sort_Id(st,stcount);
				Print_all_student(st,stcount);
			}else if(select == 4){//หาและแสดงคะแนนช่วงที่ต้องการ
				Search_Score(st,stcount);
			}else if(select == 5){//แสดงคนที่ได้เกรดตามที่กำหนด
				Search_Grade(st,stcount);
			}else{//ค้นหาและแสดงบางส่วนของชื่อ
				Search_Name(st,stcount);
			}
		}
	}while(select!=0);
	
	return 0;
}