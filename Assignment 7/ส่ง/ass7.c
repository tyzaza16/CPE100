#include <stdio.h>
int checkmenu(int min, int max){ // ฟังก์ชั่นเช็คค่าที่รับมาว่าตรงตามที่ต้องการหรือไม่
	int value; // กำหนดตัวแปลเก็บค่า 1 ตัวชื่อ value เป็น integer
	char ch; // กำหนดตัวแปรเก็บอักษร 1 ตัวเพื่ออ่านค่า enter 
	while(scanf("%d%c",&value,&ch) != 2 || value < min || value > max || ch != '\n'){ // เงื่อนไขในการรีข้อมูลที่คีบอร์ดใหม่ว่าต้องอ่านไม่ได้ 2 ตัว และค่าที่รับมาต้องน้อยกว่าค่า min หรือ มากกว่าค่า max และ ch ไม่เท่ากับ enter ถึงจะทำในฟังก์ชั่น
		rewind(stdin); // รีเซ็ตข้อมูลบนคีย์บอร์ด
		printf("\nInvalid Input, Try Again."); //แสดงข้อความว่าค่าที่กรอกมาผิดพลาด
	}
	return value; // รีเทิร์นค่าที่รับมาได้ถูกต้องกลับไป
}
int fibonacci(int n){
	int i,t1,t2,nextterm=1; //กำหนดตัวแปร
	for(i=2,t1=1,t2=1;i<n;i++){ //ให้ t1 เป็นเทอมที่ 1 t2 เป็นเทอมที่ 2 และให้ i = 2 และทำเมื่อ i น้อยกว่า n และเพิ่มค่า ร เมื่อทำเสร็จ
		nextterm = t1 + t2; // หาค่าเทอมต่อไป
		t1 = t2; //กำหนดให้เทอมแรกเป็นเทอมสองของการทำครั้งก่อน
		t2 = nextterm; //ให้เทอม 2 ครั้งก่อนเป็นเทอม 2 ครั้งใหม่
	}
	return nextterm;//รีเทรินค่ากลับไปให้ฟังก์ชั่น
}
int factorial(int n){
	int i,ans=1; //กำหนดตัวแปร
	for(i=1;i<=n;i++){//ทำเมื่อ i<n และให้ i = 1 และเพิ่มค่า i เมื่อทำเสร็จ
		ans *= i; //ให้คำตอบเท่ากับ คำตอบคูณกับค่าของ i ในแต่ละรอบ
	}
	return ans; // รีเทิร์นค่าของคำตอบกลับไป
}
int prime(int n){ // หา จน. เฉพาะ
	int i; // กำหนดตัวแปร i จน.เต็ม
	if (n<=1) // จำนวนเฉพาะเริ่มที่ 2 ถ้าน้อยกว่าจึงไม่เป็น
		return 0; //รีเทิร์นค่า 0 กลับไปให้รู้ว่าไม่เป็น จน. เฉพาะ
	else{ // ถ้า n >= 2 ให้ทำในนี้
		for(i=2;i<n;i++) // ให้ i = 2 ทำเมื่อ i < n เพิ่มค่า i หลังจากทำเสร็จ
			if(n%i ==0) //ถ้าจำนวน i ตั้งแต่ 2 ก่อนถึงตัวมันเองหารมันไม่ลงตัว ให้มันไม่เป็น จน. เฉพาะ
			return 0;
	}
	return 1; // ถ้าไม่ให้เป็นจำนวนเฉพาะ
}
void Test_Series3(int n,int fi[],int fibo[],int *count) // test 3 รับค่าของเทอมมา และค่าที่อยู่ array มา 2 ตัว และพอยเตอร์ชี้ไปที่ address ของ count 
{
	int i,sum; // กำหนดตัวแแปรเป็น จน. เต็ม
	for(i=1,*count=0,sum=0;*count<10;i++){//ให้ i = 1 ค่าของ count = 0(เปลี่ยนฟังก์ชัน main เลย) และ sum = 0 ทำงานเมื่อค่าของ count < 10 และเพิ่มค่า i ไปที่ละหนึ่ง
		if( prime(i) !=0){ //ส่งค่าไปหา จน.เฉพาะ
			sum = sum+i; // ผลรวมของค่าแต่ละเทอม
			*count = *count + 1; // นับจำนวนของรอบที่ตรงตามกับเงื่อนไขจึงนับเพิ่มไป 1 
			fi[*count] = i; // เอาจำนวนรอบที่ทำทั้งหมดแบบไม่ต้องตรงกับเงื่อนไขไปเก็บที่ array fi ไปเรื่อยๆจนครบ
			fibo[*count] = sum;// เอาค่าของผลบวกของแต่ละเทอม ที่ทำทั้งหมดไปเก็บที่ array fibo ไปเรื่อยๆจนครบ
		}
	}
}
void Print_Series3(int fi[],int fibo[],int count){ // ฟังก์ชั่นแสดงค่าของ test3 โดยรับ array มาแสดง
	int i; // กำหนดตัวแแปรเป็น จน. เต็ม
	printf("               #Test 3 \n"); // แสดงผลให้รู้ว่าเป็น test 3
	printf("***********************************\n");
	printf("*   count   *    i    *     sum   *\n");
	printf("***********************************\n");
	for(i=1;i<=count;i++)
		printf("*    %2d     *   %2d    *    %4d   *\n",i,fi[i],fibo[i]); // สั่งวนรอบเพิ่มแสดงค่าใน array ที่รับมา count รอบ
	printf("***********************************\n");
	printf("count is : %d\nAns is : %d\n",count,fibo[count]); // แสดงค่ารอบทั้งหมดและคำตอบสุดท้าย

}
void Test_Series2(int n,int fi[],int fibo[],int *count)// test 2 รับค่าของเทอมมา และค่าที่อยู่ array มา 2 ตัว และพอยเตอร์ชี้ไปที่ address ของ count 
{
	int i,ans;// กำหนดตัวแแปรเป็น จน. เต็ม
	for(i=1,*count=0;*count<n;i++){//ให้ i = 1 ค่าของ count = 0(เปลี่ยนฟังก์ชัน main เลย) ทำงานเมื่อค่าของ count < n และเพิ่มค่า i ไปที่ละหนึ่ง
		ans = fibonacci(i); // ส่งค่าไปคิดที่ฟังก์ชั่น fibonacci
		if(ans%2==0){ // หาเศษว่าเป็นเลขคู่
			*count = *count + 1; // นับจำนวนของรอบที่ตรงตามกับเงื่อนไขจึงนับเพิ่มไป 1 
			fi[*count] = i;// เอาจำนวนรอบที่ทำทั้งหมดแบบไม่ต้องตรงกับเงื่อนไขไปเก็บที่ array fi ไปเรื่อยๆจนครบ
			fibo[*count] = ans; // เอาค่าของผลบวกของแต่ละเทอม ที่ทำทั้งหมดไปเก็บที่ array fibo ไปเรื่อยๆจนครบ
		}
	}
}
void Print_Series2(int fi[],int fibo[],int count){ // ฟังก์ชั่นแสดงค่าของ test3 โดยรับ array มาแสดง
	int i;
	printf("               #Test 2 \n"); // แสดงผลให้รู้ว่าเป็น test 3
	printf("***********************************\n");
	printf("* count *    f[i]     *    fibo   *\n");
	printf("***********************************\n");
	for(i=1;i<=count;i++)
		printf("* %5d *     %2d      *  %7d  *\n",i,fi[i],fibo[i]); // สั่งวนรอบเพิ่มแสดงค่าใน array ที่รับมา count รอบ
	printf("***********************************\n");
	printf("count is : %d\nAns is : %d\n",count,fibo[count]);// แสดงค่ารอบทั้งหมดและคำตอบสุดท้าย

}
void Test_Series1(int n,double term[],double sum[],int *count){
	double terms1,sums1=0; // กำหนดตัวแแปรเป็น จน. เต็ม
	int i;
	for(i=1;i<=n;i++){ //วนรอบ
			terms1 = (double)((i*i)+i)/(factorial(i)); //ความสัมพันธ์
			sums1 = sums1+terms1; //หาผลบวกแต่ละเทอม
			term[i] = terms1; // เอาค่าแต่เทอมไปเก็บใน array
			sum[i] = sums1; // เอาค่าของ sum แต่ละรอบไปเก็บใน array 
			*count = i; //เก็บค่าจำนวนรอบ
		}
}
void Print_Series1(double term[],double sum[],int count)
{
	int i;
	printf("               #Test 1 \n");
	printf("***********************************\n");
	printf("*  i  *    fi       *     sum     *\n");
	printf("***********************************\n");      // เหมือนกันกับ2
	for(i=1;i<=count;i++)
		printf("* %2d  * %10.6lf  *  %10.6lf *\n",i,term[i],sum[i]);
	printf("***********************************\n");
	printf("Ans is %lf\n",sum[count]);
}
void Test_Series4(int n,int intterm[],int intdata[],int *count){
	int i,sum,term; 
	for(i=1,sum=0;i<=n;i++){ //วนรอบ
		term = (2*i-1)*(42-(2*i)); // ค่าของแต่ละเทอมในการวนรอบ
		sum = sum + term; // ผลรวมของแต่ละเทอม
		intterm[i] = term; // เก็บค่าแต่ละเทอมใน array
		intdata[i] = sum; // เอาค่าของ sum แต่ละรอบไปเก็บใน array
		*count = i; //เก็บค่าจำนวนรอบ
	}
}
void Print_Series4(int intterm[],int intdata[],int count){
	int i;
	printf("               #Test 4 \n");
	printf("***********************************\n");
	printf("*   count   *    i    *    sum    *\n"); //เหมือนกันกับ 2,3,4
	printf("***********************************\n");
	for(i=1;i<=count;i++)
		printf("*    %3d    *  %4d   *   %5d   *\n",i,intterm[i],intdata[i]);
	printf("***********************************\n");
	printf("count is : %d\nAns is : %d\n",count,intdata[count]);
}
void Test_Series5(int n,int intterm[],int *count){
	int i,term;
	for (i=1;i<=n;i++) //วนรอบ
	{
		term = (15*i)-14; //ความสัมพันธ์ของอนุกรม
		intterm[i] = term;  // เก็บค่าแต่ละเทอมใน array
		*count = i; //เก็บค่าจำนวนรอบ
	}
}
void Print_Series5(int intterm[],int count){
	int i;
	printf("               #Test 5 \n");
	printf("***********************************\n");
	printf("*      count      *      term     *\n");
	printf("***********************************\n"); // เหมือนกันกับ 2,3,4
	for(i=1;i<=count;i++)
		printf("*       %3d       *     %4d      *\n",i,intterm[i]);
	printf("***********************************\n");
	printf("count is : %d\n",count);
}
int get_menu()
{
	int select; // กำหนดตัวแปร
	printf("==================================================\n");
	printf("                    My Function                   \n");
	printf("==================================================\n");
	printf("                 1. Test Series 1                 \n");
	printf("                 2. Test Series 2                 \n");
	printf("                 3. Test Series 3                 \n");   // แสดงผลให้ผู้ใช้ทราบ
	printf("                 4. Test Series 4                 \n");
	printf("                 5. Test Series 5                 \n");
	printf("                 0. Exit                          \n");
	printf("==================================================\n");
	printf("Select The Test Series that You want to test :  "); // ให้ผู้ใช้เลือกฟังก์ชั่น(ถามคำถาม)
	select = checkmenu(0,5); //ส่งค่าไปคิดที่ฟังก์ชั่นตรวจสอบค่า
	return select; // return ค่าที่ได้จากฟังก์ชั่นนี้
}
int main(){
	int select,count,i,intterm[20],intdata[20]; // กำหนดตัวแปรเป็นจน.เต็มโดยมีarray ความยาว 20 กล่องด้วย
	double term[20],sum[20];// กำหนดตัวแปรเป็นจน.จริงโดยมีarray ความยาว 20 กล่องด้วย
	do{ // ทำซ้ำ
	select = get_menu();
	if(select == 1){ // เท่ากับ 1 ให้ทำ
		Test_Series1(10,term,sum,&count); // ส่งตัวแปรไปคิดค่า + กับเก็บค่ามาไว้ใน array และตัวแปรที่ต้องการ
		Print_Series1(term,sum,count); 
	}
	else if (select == 2){// เท่ากับ 4 ให้ทำ
		Test_Series2(10,intterm,intdata,&count); // ส่งตัวแปรไปคิดค่า + กับเก็บค่ามาไว้ใน array และตัวแปรที่ต้องการ
		Print_Series2(intterm,intdata,count);
	}
	else if (select == 3){// เท่ากับ 3 ให้ทำ
		Test_Series3(10,intterm,intdata,&count);// ส่งตัวแปรไปคิดค่า + กับเก็บค่ามาไว้ใน array และตัวแปรที่ต้องการ
		Print_Series3(intterm,intdata,count);

	}
	else if (select == 4){// เท่ากับ 4 ให้ทำ
		Test_Series4(15,intterm,intdata,&count);// ส่งตัวแปรไปคิดค่า + กับเก็บค่ามาไว้ใน array และตัวแปรที่ต้องการ
		Print_Series4(intterm,intdata,count);
	}
	else if (select == 5){// เท่ากับ 5 ให้ทำ
		Test_Series5(15,intterm,&count);// ส่งตัวแปรไปคิดค่า + กับเก็บค่ามาไว้ใน array และตัวแปรที่ต้องการ
		Print_Series5(intterm,count);
	}
	}while(select != 0);// ทำซ้ำเมื่อ ไม่เท่ากับ 0
	printf("\n================  End Program  ========================="); // เมื่อทำกับ 0 แสดงข้อความจบโปรแกรม
}