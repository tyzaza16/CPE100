#include <stdio.h>
#include <math.h>
int getint(int min,int max)
{
	int value;
	char ch;
	while(scanf("%d%c",&value,&ch) != 2 || value < min || value > max || ch != '\n')
	{
		rewind(stdin);
        printf("Invalid input, please try again : ");
	}
	return value;
}
int checkmenu(int min,int max)
{
	int value;
	char ch;
	while(scanf("%d%c",&value,&ch) != 2 || value < min || value > max || ch != '\n')
	{
		rewind(stdin);
        printf("Invalid input, please try again : ");
	}
	return value;
}
int get_menu()
{
	int select;
	printf("==================================================\n");
	printf("                    My Function                   \n");
	printf("==================================================\n");
	printf("                 1. Fibonacci                     \n");
	printf("                 2. Combination                   \n");
	printf("                 3. GCD(x,y)                      \n");
	printf("                 4. Polynomial Function           \n");
	printf("                 0. Exit                          \n");
	printf("==================================================\n");
	printf("Select The Function that You want to calculate :  ");
	select = checkmenu(0,4);
	return select;
}
int fibonacci(int ans)
{
	int t1,t2,nextterm,stop;
	for (t1 = 1,t2 = 1,stop = (2*ans)-1;stop < ans; stop++)
	{
		nextterm = t1+t2;
		t1 = t2;
		t2 = nextterm;
	}
}
	return nextterm;
int factorial(int n)
{
	int ans,i;
	for(ans=1,i=n;i>0;i--)
	{
		ans = ans * i;
	}
	return ans;
}
int Combination(int n,int r)
{
	int ans;
	ans = factorial(n)/(factorial(n-r)*factorial(r));
	return ans;
}
int GCD(int a,int b)
{
	int mod;
	while(a%b!= 0)
	{
		mod = a%b;
		a = b;
		b = mod;
	}
	return b;
}
void poly()
{
    int a, b, c;
    double x, x1, x2, Re, Im;
    char ch;
    do
    {
        a = b = c = 0;
        printf("\n=== Welcome to Program calculate root of Equation ax^2+bx+c = 0 ===\n");
        printf("===> Enter parameter [a] : ");
        a = getint(0,100000);
        printf("===> Enter parameter [b] : ");
        b = getint(0,100000);
        printf("===> Enter parameter [c] : ");
        c = getint(0,100000);
        if(a==0)
        {
            if(b!=0){
                x = (float)-c/b;
                printf(">>> This is linear equation\n");
                printf("*** Answer of %dx%+d=0 is ***\n",b,c);
                printf("==-> x = %g\n",x);
            }
            else{
                printf("== Error! invalid equation ==\n");
            }
        }
    else if((b*b)-(4*a*c)>=0){
                x1 = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
                x2 = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
                printf(">>> root of %dx^2%+dx%+d = 0 is\n",a,b,c);
                printf("==-> x1 = %g\nx2 = %g\n",x1,x2);
        }
        else{
            Re = (float)-b/(2*a);
            Im = sqrt(fabs(b*b-4*a*c)) /(2*a);
            printf("=== root of %dx^2%+dx%+d = 0 is complex number ===\n",a,b,c);
            printf("==-> x1 = %g + %gi\n",Re,Im);
            printf("==-> x2 = %g - %gi\n",Re,Im);
            printf("** i is square root of -1\n");
        }
            do
            {
                printf(" >>> Do you want to calculate Again? \nEnter [y] to calculate again or [n] to exit.");
                scanf(" %c",&ch);
            }
            while(ch!='y'&&ch!='n');
    } while (ch == 'y');
    printf("\nEnd Program\n");
}
int main()
{
	int select, ans, para, r, n, a, b, c;
	do{
		select = get_menu();
		if(select == 1 )
		{
			printf("Welcome to Program Calculate Fibonacci \n");
			printf("Enter the value [term of fibonacci] : ");
			para = getint(0,45);
			ans = fibonacci(para);
			printf("\nThe value of term %d in Fibonacci  is : %d\n", para, ans);
		}
		else if(select == 2)
		{
			printf("Welcome to Program Calculate Combination");
			printf("\nEnter the value of [n] : ");
			n = getint(1,10);
			printf("Enter the value of [r] : ");
			r = getint(1,n);
			ans = Combination(n,r);
			printf("the value of Combination [%d]C[%d] is : %d \n", n, r, ans);
		}
		else if(select == 3){
			printf("Welcome to Program Greatest Common Divisor[a,b]");
			printf("\nEnter The value of a : ");
			r = getint(1,100000);
			printf("Enter The value of b : ");
			n = getint(1,100000);
			ans = GCD(r,n);
			printf("The value of GCD[%d,%d] is : %d\n", r, n, ans);
		}

		else if(select == 4)
			poly();
		else
			printf("===--> End Program <--===");
	}while(select != 0);
	return 0;
}