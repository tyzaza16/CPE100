#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct grade_info{ // สร้าง structure ในการเก็บค่าของตัวแปรชนิดตัวแปรต่างๆที่เราต้องการใ
	long long id;  // structure นี้เอาไว้เก็บข้อมูลที่เราจะอ่านเข้ามา
	char name[40];
	double mid,final,attn,total,gpoint;
	char grade[3]; } student_type;
typedef struct min_info
	{double mid,final,attn,total;} min_all;// สร้างมาเพื่อเก็บค่า min ของคะแนนช่วงต่างๆ 
typedef struct max_info
	{double mid,final,attn,total;} max_all;// สร้างมาเพื่อเก็บค่า  max ของคะแนนช่วงต่างๆ 
typedef struct mean_info
	{double mid,final,attn,total;} mean_all;// สร้างมาเพื่อเก็บค่าเฉลี่ยของคะแนนต่างๆ 
typedef struct sd_info
	{double mid,final,attn,total;} sd_all;// สร้างมาเพื่อเก็บค่าเบี่ยงเบนมาตรฐานของคะแนนช่วงต่างๆ 
typedef struct count_info
	{int A,Bp,B,Cp,C,Dp,D,F;} count_all;// สร้างมาเพื่อเก็บค่าจำนวนของคนที่ได้เกรดในช่วงต่างๆ

int Read_File(char *name,student_type st[]){ //ฟังก์ชั่นอ่านไฟล์
	FILE *fp; //กำหนด pointer เพื่อจะเปิดไฟล์
	int count=0;
	student_type x; // ให้ x เป็น structure ที่เรากำหนดเพื่ออ่านค่าจากไฟล์มาใส่ใน array ที่เรากำหนด
	fp = fopen(name,"r"); // เปิดไฟล์ในโหมด read คืออ่านไฟล์
	if(fp != NULL){ //เช็คว่าไฟล์อ่านได้
		while(fscanf(fp,"%llu,%[^,],%lf,%lf,%lf",&x.id,x.name,&x.mid,&x.final,&x.attn) == 5){ //อ่านค่าจากไฟล์ให้ได้ 5 ตัวถึงจะทำคำสั่งใน loop
			x.total = x.mid+x.final+x.attn; // หาคะแนนรวม
			st[count++] = x; // ให้ไปเก็บ ใน array ที่เรากำหนดเพื่อจะนำไปคิดต่อ
		}
		fclose(fp); // ปิดไฟล์เมื่ออ่านเสร็จ
		return count; // ส่งค่าจำนวนที่อานได้จากไฟล์กลับไป function main
	}
	else // ถ้าไม่สามารถอ่านไฟล์ได้ในตอนแรก
		return 0; // ส่งค่า 0 กลับไปใน main

}
void Print_1_student(student_type st,int i){ // ฟังก์ชั่นแยกเพื่อปริ้นข้อมูลของแต่ละคน จะใช้บ่อยตอนแสดงผลรูปแบบต่างๆ
	printf("\t\t%d) %llu %-40s %7.1lf %7.1lf %7.1lf %7.1lf %2.1lf %3s\n",i,st.id,st.name,st.mid,st.final,st.attn,st.total,st.gpoint,st.grade);
    // แสดงผลค่าต่างๆ
}
void Print_all_student(student_type st[],int stcount){//ฟังก์ชั่นแสดงผลข้อมูลของทุกคน
	int i;
	for(i=0;i<stcount;i++) // วนรอบเพื่อส่งข้อมูลแต่ละคนไป print
		Print_1_student(st[i],i+1); // ส่งข้อมูลไปปริ้น
	printf("\t\tEnd of Data\n"); // แสดงข้อความบอกว่าจบข้อมูล
}
void Set_grade(student_type st[],int stcount,int A,int Bp,int B,int Cp,int C,int Dp,int D,count_all *count){ // ฟังก์ชั่นตัดเกรด
	int i;   // กำหนดตัวแปร
	for(i=0;i<stcount;i++){ //วนรอบเพื่อตัดเกรดให้ครบทุกคน
		if(st[i].total >= A){ // คะแนนมากกว่า ค่า A ซึ่งจะให้ผู้ใช้กำหนดในอีกฟังก์ชั่น
			st[i].gpoint = 4.0; // ให้ได้เกรด  4
			strcpy(st[i].grade,"A"); // กอป A ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).A = (*count).A + 1; // เพิ่มค่าคนที่ได้ A ไป 1 คน
		}
		else if(st[i].total >= Bp){// คะแนนมากกว่า ค่า B+ ซึ่งจะให้ผู้ใช้กำหนดในอีกฟังก์ชั่น
			st[i].gpoint = 3.5;// ให้ได้เกรด  3.5
			strcpy(st[i].grade,"B+");// กอป B+ ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).Bp = (*count).Bp + 1;// เพิ่มค่าคนที่ได้ B+ ไป 1 คน
		}
		else if(st[i].total >= B){
			st[i].gpoint = 3.0;// ให้ได้เกรด  3
			strcpy(st[i].grade,"B");// กอป B ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).B = (*count).B + 1;// เพิ่มค่าคนที่ได้ B ไป 1 คน
		}
		else if(st[i].total >= Cp){
			st[i].gpoint = 2.5;// ให้ได้เกรด  2.5
			strcpy(st[i].grade,"C+");// กอป C+ ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).Cp = (*count).Cp + 1;// เพิ่มค่าคนที่ได้ C+ ไป 1 คน
		}
		else if(st[i].total >= C){
			st[i].gpoint = 2.0;// ให้ได้เกรด  2
			strcpy(st[i].grade,"C");// กอป C ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).C = (*count).C + 1;// เพิ่มค่าคนที่ได้ C ไป 1 คน
		}
		else if(st[i].total >= Dp){
			st[i].gpoint = 1.5;// ให้ได้เกรด  1.5
			strcpy(st[i].grade,"D+");// กอป D+ ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).Dp = (*count).Dp + 1;// เพิ่มค่าคนที่ได้ D+ ไป 1 คน
		}
		else if(st[i].total >= D){
			st[i].gpoint = 1.0;// ให้ได้เกรด  1
			strcpy(st[i].grade,"D");// กอป D ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).D = (*count).D + 1;// เพิ่มค่าคนที่ได้ D ไป 1 คน
		}
		else{
			st[i].gpoint = 0;// ให้ได้เกรด  0
			strcpy(st[i].grade,"F");// กอป F ลงใน ตัวแปร grade เพื่อจะนำไปแสดงผล
			(*count).F = (*count).F + 1;// เพิ่มค่าคนที่ได้ F ไป 1 คน
		}

	}

}
void Ask_grade(int *A,int *Bp,int *B,int *Cp,int *C,int *Dp,int *D){ // ฟังก์ชั่นถามช่วงคะแนนที่จะตัดเกรด
	printf("Enter the point of Grade [A] : "); // ถามว่าจะตัดเกรด A ที่เท่าไหร่
	scanf("%d",A);
	printf("Enter the point of Grade [Bp] : ");// ถามว่าจะตัดเกรด B+ ที่เท่าไหร่
	scanf("%d",Bp);
	printf("Enter the point of Grade [B] : ");// ถามว่าจะตัดเกรด B ที่เท่าไหร่
	scanf("%d",B);
	printf("Enter the point of Grade [Cp] : ");// ถามว่าจะตัดเกรด C+ ที่เท่าไหร่
	scanf("%d",Cp);
	printf("Enter the point of Grade [C] : ");// ถามว่าจะตัดเกรด C ที่เท่าไหร่
	scanf("%d",C);
	printf("Enter the point of Grade [Dp] : ");// ถามว่าจะตัดเกรด D+ ที่เท่าไหร่
	scanf("%d",Dp);
	printf("Enter the point of Grade [D] : ");// ถามว่าจะตัดเกรด Dที่เท่าไหร่
	scanf("%d",D);
}
void Calculate_Statistic_Mid(student_type st[],int stcount,min_all *min,max_all *max,mean_all *mean,sd_all *sd){ // ฟังก์ชั่นคำนวณค่าทางสถิติของคะแนน midterm
	int i;
	double sum=0,sum2=0; 
	(*min).mid =st[0].mid;// ให้ค่าน้อยสุดของมิดเทอมเท่ากับคะแนน midterm ตัวแรก
	(*max).mid =st[0].mid;// ให้ค่ามากสุดของมิดเทอมเท่ากับคะแนน midterm ตัวแรก
	for(i=0;i<stcount;i++){ //วนรอบเพื่อหาค่ามากสุด น้อยสุด ค่าเฉลี่ย ค่าเบี่บงเบน
		if(st[i].mid > (*max).mid) //ถ้าเจอตัวที่มากกว่าค่าที่มากที่สุด
			(*max).mid = st[i].mid; // ให้ตัวนั้นเป็นค่ามากสุดแทน
		if(st[i].mid < (*min).mid) //ถ้าเจอตัวที่น้อยกว่าค่าที่น้อยที่สุด
			(*min).mid = st[i].mid;// ให้ตัวนั้นเป็นค่าน้อยสุดแทนน
		sum += st[i].mid; // หาผลรวมของค่า mid แต่ตัวละ
		sum2 += pow(st[i].mid,2); // หาผลรวมกำลัง 2
	} 
	(*mean).mid = (double)(sum/stcount); // หาค่าเฉลี่ย
	(*sd).mid = (double)(sqrt(sum2/stcount - (*mean).mid*(*mean).mid)); // หาค่าเบี่ยงเบน

}
void Calculate_Statistic_Final(student_type st[],int stcount,min_all *min,max_all *max,mean_all *mean,sd_all *sd){
	int i;
	double sum=0,sum2=0;
	(*max).final = (*min).final = st[0].final;
	for(i=0;i<stcount;i++){
		if(st[i].final > (*max).final)
			(*max).final = st[i].final;   // เหมือนฟังก์ชั่นคำนวณของมิดเทอมต่างที่ใช้เป็นค่าของ final
		if(st[i].final < (*min).final)
			(*min).final = st[i].final;
		sum += st[i].final;
		sum2 += pow(st[i].final,2);
	}
	(*mean).final = (double)(sum/stcount);
	(*sd).final = (double)(sqrt(sum2/stcount - (*mean).final*(*mean).final));

}
void Calculate_Statistic_atten(student_type st[],int stcount,min_all *min,max_all *max,mean_all *mean,sd_all *sd){
	int i;
	double sum=0,sum2=0;
	(*max).attn = (*min).attn = st[0].attn;
	for(i=0;i<stcount;i++){
		if(st[i].attn > (*max).attn)
			(*max).attn = st[i].attn;
		if(st[i].attn < (*min).attn)   // เหมือนฟังก์ชั่นคำนวณของมิดเทอมต่างที่ใช้เป็นค่าของ attn(คะแนนเก็บ)
			(*min).attn = st[i].attn;
		sum += st[i].attn;
		sum2 += pow(st[i].attn,2);
	}
	(*mean).attn = (double)(sum/stcount);
	(*sd).attn = (double)(sqrt(sum2/stcount - (*mean).attn*(*mean).attn));

}
void Calculate_Statistic_total(student_type st[],int stcount,min_all *min,max_all *max,mean_all *mean,sd_all *sd){
	int i;
	double sum=0,sum2=0;
	(*max).total = (*min).total = st[0].total;
	for(i=0;i<stcount;i++){
		if(st[i].total > (*max).total)
			(*max).total = st[i].total;//  เหมือนฟังก์ชั่นคำนวณของมิดเทอมต่างที่ใช้เป็นค่าของ total(คะแนนรวม)
		if(st[i].total < (*min).total)
			(*min).total = st[i].total;
		sum += st[i].total;
		sum2 += pow(st[i].total,2);
	}
	(*mean).total = (double)(sum/stcount);
	(*sd).total = (double)(sqrt(sum2/stcount - (*mean).total*(*mean).total));

}
void Print_stats(min_all min,max_all max,mean_all mean,sd_all sd,count_all count,double GPA){ // ฟังก์ชั่นปริ้นข้อมูลทางสถิติ
	printf("\t\t\t\t\t========================================================\n");
	printf("\t\t\t\t\t==============     Point Statistic of student     ==============\n");
	printf("\t\t\t\t\t================================================================\n\n");
	printf("\t\t\t\t\t****************************************************************\n");
	printf("\t\t\t\t\t**   score   **   mid   **   final   **   attn   **   total   **\n");
	printf("\t\t\t\t\t****************************************************************\n");
	printf("\t\t\t\t\t**    min    **  %3.2lf   **   %3.2lf    **   %3.2lf  **   %3.2lf   **\n",min.mid,min.final,min.attn,min.total);
	printf("\t\t\t\t\t**    max    **  %3.2lf  **   %3.2lf   **   %3.2lf  **   %3.2lf   **\n",max.mid,max.final,max.attn,max.total);
	printf("\t\t\t\t\t**   mean    **  %3.2lf  **   %3.2lf   **   %3.2lf  **   %3.2lf   **\n",mean.mid,mean.final,mean.attn,mean.total);
	printf("\t\t\t\t\t**    sd     **  %3.2lf   **   %3.2lf    **   %3.2lf   **   %3.2lf   **\n\n\n",sd.mid,sd.final,sd.attn,sd.total);

	printf("\t\t\t\t\t****************************************************************\n");
	printf("\t\t\t\t\t***  A  **  B+  **  B  **  C+  **  C  **  D+  **  D  **   F  ***\n");
	printf("\t\t\t\t\t****************************************************************\n");
	printf("\t\t\t\t\t** %3d  ** %3d  ** %3d ** %3d  **%3d  **%3d   **%3d  ** %3d   **\n",count.A,count.Bp,count.B,count.Cp,count.C,count.Dp,count.D,count.F); //แสดงผลข้อมูลที่อยู่ใน structure
	printf("\t\t\t\t\t****************************************************************\n");
	printf("\t\t\t\t\tGPA = %.2lf\n",GPA);
}
void Calculate_GPA(double *GPA,int stcount,student_type st[]){ //ฟังก์ชั่นคำนวรหาเกรดเฉลี่ย
	double totalGpoint;
	int i;
	for(i=0;i<stcount;i++){           // วนรอบ
		totalGpoint += st[i].gpoint; // หาผลรวมของคะแนนรวม

	}
	*GPA = (double)(totalGpoint/stcount); // คำนวณเกรดเฉลี่ย
}
void Sort_by_total (student_type st[], int stcount) // ฟังก์ชั่นเรียงจากคะแนนรวมมากไปน้อย
{ 	int i, j ;
	student_type x;
	for (i = 0; i < stcount-1; i++) 
		for (j = i+1; j < stcount; j++) 
			if (st[j].total > st[i].total) 
				{ x = st[i]; 
				st[i] = st[j];
				st[j] = x; }
}
void  Sort_by_id (student_type st[], int stcount)// ฟังก์ชั่นเรียงจากรหัสนศ.มากไปน้อย
{ 	int i, j ;
	student_type x;
	for (i = 0; i < stcount-1; i++) 
		for (j = i+1; j < stcount; j++) 
			if (st[j].id < st[i].id) 
				{ x = st[i]; 
				st[i] = st[j];
				st[j] = x; }
}
void Search_Score (student_type st[], int stcount) // ฟังก์ชั่นแสดงผลข้อมูลตามช่วงคะแนนที่กำหนด
{ 	double min, max;
	int i , count;
	char ch ;
	do { 
		printf("\n Enter Range of min score and max score ");
		scanf("%lf %lf", &min , &max); 
		count = 0;
		for (i = 0; i<stcount; i++){
			 if (st[i].total >= min && st[i].total <= max)
				{ 
				count = count + 1;
				Print_1_student(st[i],count);
				}
			}
		printf("\n\n Do you want to search again ? ");
		scanf(" %c",&ch);
		} while (ch == 'y');
}
void Search_Grade(student_type st[], int stcount){  // ฟังก์ชั่นแสดงผลตามเกรดที่ต้องการ
	char key[3];
	int i , count ;
	do {printf("\nSearch Grade (A, B+, B, ... F or 0 = Exit) ");
		scanf("%2s", key); // อ่านสตริงไม่เกิน 2 ตัวอักษร
		count = 0;
		if (strcmp(key,"0") != 0){
			for (i = 0; i<stcount; i++){
				if (strcmp(st[i].grade,key)==0){
					count = count + 1;
					Print_1_student(st[i],count);
				}
			}	
		}
	}while (strcmp(key, "0") !=0);
}
void Search_Name (student_type st[],int stcount) // ฟังก์ชั่นแสดงผลจากการหาตาม keyword บางส่วน
{ 	char key[16];
	int i, count;
	do {
		printf("\n Enter Search keyword (0 = Exit) ");
		scanf("%15s", key); // อ่านสตริงไม่เกิน 15 ตัวอักษร
		count = 0;
		if (strcmp(key,"0") != 0)
			for (i = 0; i<stcount; i++)
				if (strstr(st[i].name, key) != NULL) 
					{ 	count = count + 1;
						Print_1_student(st[i],count);
					}
	} while (strcmp(key,"0")!=0);
}
int checkmenu(int min, int max){ // ฟังก์ชั่นเช็คค่าที่รับมาว่าตรงตามที่ต้องการหรือไม่
	int value; // กำหนดตัวแปลเก็บค่า 1 ตัวชื่อ value เป็น integer
	char ch; // กำหนดตัวแปรเก็บอักษร 1 ตัวเพื่ออ่านค่า enter 
	while(scanf("%d%c",&value,&ch) != 2 || value < min || value > max || ch != '\n'){ // เงื่อนไขในการรีข้อมูลที่คีบอร์ดใหม่ว่าต้องอ่านไม่ได้ 2 ตัว และค่าที่รับมาต้องน้อยกว่าค่า min หรือ มากกว่าค่า max และ ch ไม่เท่ากับ enter ถึงจะทำในฟังก์ชั่น
		rewind(stdin); // รีเซ็ตข้อมูลบนคีย์บอร์ด
		printf("\nInvalid Input, Try Again."); //แสดงข้อความว่าค่าที่กรอกมาผิดพลาด
	}
	return value; // รีเทิร์นค่าที่รับมาได้ถูกต้องกลับไป
}
int get_menu()
{
	int select; // กำหนดตัวแปร
	printf("\t\t\t\t\t\t==================================================\n");
	printf("\t\t\t\t\t\t                    My Function                   \n");
	printf("\t\t\t\t\t\t==================================================\n");
	printf("\t\t\t\t\t\t          1. Show Individual information          \n");
	printf("\t\t\t\t\t\t          2. Calculate Grade & Show Statistic     \n");
	printf("\t\t\t\t\t\t          3. Sort by total Max to Min             \n");   // แสดงผลให้ผู้ใช้ทราบ
	printf("\t\t\t\t\t\t          4. Sort by id                           \n");
	printf("\t\t\t\t\t\t          5. Sort by Range of Score               \n");
	printf("\t\t\t\t\t\t          6. Sort by Grade                        \n");
    printf("\t\t\t\t\t\t          7. Sort by keyword                      \n");
	printf("\t\t\t\t\t\t          0. Exit                          		  \n");
	printf("\t\t\t\t\t\t==================================================\n");
	printf("\t\t\t\tSelect The Test Series that You want to test :  "); // ให้ผู้ใช้เลือกฟังก์ชั่น(ถามคำถาม)
	select = checkmenu(0,7); //ส่งค่าไปคิดที่ฟังก์ชั่นตรวจสอบค่า
	return select; // return ค่าที่ได้จากฟังก์ชั่นนี้
}
int main(){
	student_type  x,st[100]; // structure เก็บคะแนน รหัส นศ. ชื่อ
	int stcount,i,A,Bp,B,Cp,C,Dp,D,select;
	double GPA;
	min_all min; // structure เก็บค่าของคะแนน mid final attn total 
	max_all max;// structure เก็บค่าของคะแนน mid final attn total
	mean_all mean;// structure เก็บค่าของคะแนน mid final attn total
	sd_all sd;// structure เก็บค่าของคะแนน mid final attn total
	count_all count;  // structure เก็บจำนวนคนได้เกรดต่างๆ
	count.A = count.Bp= count.B = count.C = count.Cp = count.D = count.Dp = count.F = 0; //กำหนดให้มันเป็น 0
	stcount = Read_File("SCORE.csv",st); // ส่งชื่อไฟล์ไปให้ฟังก์ชั่นอ่านไฟล์
	do{
	select = get_menu(); // เข้าฟังก์ชั่นเมนู
	if(select == 1){  // ค่า select เท่ากับ 1
		if(stcount > 0){
			Print_all_student(st,stcount); // แสดงผลข้อมูล
		}
	}
	else if(select == 2){// ค่า select เท่ากับ 2
		if(stcount > 0){
			Ask_grade(&A,&Bp,&B,&Cp,&C,&Dp,&D);
	    	Set_grade(st,stcount,A,Bp,B,Cp,C,Dp,D,&count);
			Calculate_Statistic_Mid(st,stcount,&min,&max,&mean,&sd);
			Calculate_Statistic_Final(st,stcount,&min,&max,&mean,&sd);  // ให้คำนวณข้อมูลทางสถิติต่างๆทั้งหมด
			Calculate_Statistic_atten(st,stcount,&min,&max,&mean,&sd);
			Calculate_Statistic_total(st,stcount,&min,&max,&mean,&sd);
			Calculate_GPA(&GPA,stcount,st);
			Print_stats(min,max,mean,sd,count,GPA); // และแสดงผลข้อมูลที่คำนวณมา
		}
	}	
	else if(select == 3){// ค่า select เท่ากับ 3
		if (stcount > 0)
			{ 	Sort_by_total(st,stcount); // เรียงข้อมูลจากคะแนนมากไปน้อย
				Print_all_student(st,stcount);// และแสดงผลข้อมูล
			}
	}
	else if(select == 4){// ค่า select เท่ากับ 4
		if (stcount > 0)
			{ 	Sort_by_id (st,stcount);
				Print_all_student(st,stcount);
			}
	}
	else if(select == 5){// ค่า select เท่ากับ 5
		if (stcount > 0)
			{ 	Search_Score(st,stcount);
			}

	}
	else if(select == 6){// ค่า select เท่ากับ 6
		if (stcount > 0 && count.A > 0 && count.Bp > 0 && count.B > 0 && count.Cp > 0 && count.C > 0 && count.Dp > 0 
			&& count.D > 0 & count.F > 0)
			Search_Grade(st,stcount);
		else
			printf("\t\t\t\t\tDon't Have data that you want to Show. please Calculate Grade\n");
			

	}
	else if(select == 7)
		if(stcount > 0)
			Search_Name(st,stcount);
		
	else
		printf("\t\t******   End of Program   ******");
	}while(select != 0);
	return 0;
}