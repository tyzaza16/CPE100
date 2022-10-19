#include <stdio.h>
#include <math.h>
int get_int(int min,int max){
	double a;
	char ch;
	while(scanf("%lf%c",&a,&ch) != 2 || a > max || a < min || ch != '\n'){
		rewind(stdin);
		printf("\t=== Invalid Input, please try again ===\n");
	}
	return a;
}
int NR(double a,double b,double c,double err,double Xp,double *Xn){
	double delta = 1;
	int count = 1;
		do{
		 if((2*a*Xp)+b == 0){
		 	Xp = Xp + 0.00001;
		 }
		 else {
		delta = ((a*Xp*Xp)+(b*Xp)+c)/((2*a*Xp)+b);
		*Xn = Xp-delta;
		Xp = *Xn;
	    }
	    count++;
	}while(fabs(delta) > err && count < 1000);
	if(count < 1000)
		return count;
	else
		return 0;
}
int main(){

	double a,b,c,x1,x2;
	int count;
	char ch;
	printf("\t============================================================\n");
	printf("\t===>> Welcome to Newton's Raphson Calculate Program <<===\n");
	printf("\t============================================================\n");
	do{
	printf("\t==-> Enter The Value [a] : ");
	a = get_int(-32768,32767);
	printf("\t==-> Enter The Value [b] : ");
	b = get_int(-32768,32767);
	printf("\t==-> Enter The Value [c] : ");
	c = get_int(-32768,32767);
	printf("\t============================================================\n");
	count = NR(a,b,c,0.00001,120.123,&x1);
	if (count != 0){
		printf("\t==--> Answer of this Quadratic Equation : %lf \n",x1);
		count = NR(a,b,c,0.00001,-120.123,&x2);
		if(fabs(x1-x2) > 0.00001)
			printf("\t==--> And : %lf \n",x2);
	}
	else
	    printf("\t===========-->>    Can't find Answer    <<--=================\n");

	do
	{
		printf("\t*****=====--->> Calculate again ? [y/n] :  ");
		scanf("%c",&ch);
	} while (ch != 'y' && ch != 'n');
  }while(ch == 'y');
  printf("\t***************      END      ***************");
  return 0;
}
	
