#include <stdio.h>
int main()
{  double a;
    char ch;
    do
    {
        a = 0;
        printf("\nAssignment 1 Program Test specific format of variable\n");
        printf("Enter value of a : ");
        scanf("%lf",&a);
        printf("print format of a\n");
        printf("\nint = %d\nllu = %llu\nfloat = %f\ndouble = %lf\nexponent = %e\n", a, a, a, a, a);
        //printf("long double = l%Lfl\n");
        printf("c = %c\n",a);
        //printf("s =l%sl",a);
        printf("\n\nEnter y to run again or n to exit.");
        scanf(" %c",&ch);
    } while (ch == 'y');
    printf("\nEnd Program\n");
    return 0;
}
