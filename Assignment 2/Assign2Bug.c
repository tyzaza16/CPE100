#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, d;
    double x, x1, x2, Re, Im;
    char ch;
    do
    {
        a = b = c = 0;
        printf("\nProgram calculate root of Equation ax^2+bx+c = 0\n");
        printf("Enter parameter a : ");
        scanf("%d",&a);
        printf("Enter parameter b : ");
        scanf("%f",&b);
        printf("Enter parameter c : ");
        scanf("%If",c);
        if(a==0)
        {
            if(b!=0)
                X = -c/b;
                printf("This is linear equation\n");
                printf("Answer of %gx%+g=0 is\n",b,c);
                printf("x = %g\n,x");
            else
                printf("Error! invalid equation\n");
	else if(b^2-4ac>=0)
                X1 = b+sqrt (b*b-4*a*c/2*a);
                X2 = -b-sqrt(b*b-4*a*c)/2*a;
                printf("root of %gx^2 %+gx %+g = 0 is\n",a,b,c)
                printf("x1 = %g\nx2 = %g\n",x1,x2);
        }
        else
            Re = -b/2*a
                 Im = sqrt(fabs(b*b-4*a*c)) /(2*a));
            printf("root of %gx^2 %+gx %+g = 0 is complex number\n",&a,b);
            printf("x1 = %g + %gi\n",Re,Im);
            printf("x2 = %g - %gi\n",Re,Im);
            printf("i is square root of -1\n");
            do
            {
                printf("Enter y to calculate again or n to exit.)
                       scanf("%c",&ch);
            }
            while(ch!='y'&&ch!='n');
        }
    while (ch == "y");
    printf("\nEnd Program\n");
    return 0;
}

