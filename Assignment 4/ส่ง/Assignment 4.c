#include <stdio.h>
#include <math.h>
int main()
{
	double Smax, Sgoal, Hgoal, theta, rad, u, timemax, timegoal;
    char ch,er;
	do
	{
	printf("==> Welcome to Program Calculate [Ball In Goal?] <==");
	printf("\n>>> Enter the value of [Velocity] : ");
    while(scanf("%lf%c",&u,&er)==0 || er!='\n') {
    rewind(stdin);
    printf("Invalid input, please try again ");
	printf("\n>>> Enter the value of [Velocity] : ");
}
	printf(">>> Enter the value of [Angle] : ");
    while(scanf("%lf%c",&theta,&er)==0 || er!='\n') {
    rewind(stdin);
    printf("Invalid input, please try again ");
	printf("\n>>> Enter the value of [Angle] : ");
}
	printf(">>> Enter the value of [Distance form the Goal] : ");
    while(scanf("%lf%c",&Sgoal,&er)==0 || er!='\n') {
    rewind(stdin);
    printf("Invalid input, please try again ");
	printf("\n>>> Enter the value of [Distance form the Goal] : ");
}
	rad = (M_PI/180)*theta;
	timegoal = Sgoal/(u*cos(rad));
	timemax = (u*sin(rad))/4.905;
    Smax = ((u*cos(rad))*timemax);
    Hgoal = (u*sin(rad)*timegoal)-(4.905*timegoal*timegoal);
    if(Smax<Sgoal){
    	printf("\n==-[ Fail Ball ]-==");
    	printf("\n=- The ball is Away from the line of Goal : %.2lf -=",Sgoal-Smax);
    	printf("\n[time : %.2lf]",timemax);
    }
    else if(Hgoal >= 2.44){
    	printf("\n==-[ Over Shoot ]-==");
    	printf("\n=- the ball is High from the line of Goal : %.2lf -=",Hgoal);
    	printf("\n[time : %.2lf]",timegoal);
        }
    else if(timegoal>0.5){
    	printf("\n==-[ Save ball ]-==");
    	printf("\n=- the ball is high form the line of Goal : %.2lf -=",Hgoal);
    	printf("\n[time : %.2lf]",timegoal);
    }
    else {
    	printf("\n==-[ OH Goal!! ]-==");
    	printf("\n=- the ball is high form the line of Goal : %.2lf -=",Hgoal);
    	printf("\n[time : %.2lf]",timegoal);
    }
    do{
    	printf("\nDo you want to Calculate Again ?");
    	printf("\nEnter [y] to ealculate or enter [n] to exit the program :  ");
    	scanf(" %c",&ch);
    }while(ch != 'y' & ch != 'n');
  }while(ch == 'y');
  printf("\nThe Program is End");
  return 0;
}