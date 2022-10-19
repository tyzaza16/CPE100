#include <stdio.h>
#include <time.h>

int main()
{
	int x,y,count;
    char name[20],End;
    printf("==> Welcome To Random Number Game <==");
    printf("\nPlease Write Your Name Here :  ");
    scanf(" %s",&name);
    printf("\n-- Hi!! %s Have Fun! --",name);
	do{
        srand(time(NULL));
        x = rand()%100+1;
        count = 0;
        printf("\nx =%d",x);
        do{
    	count = count+1;
    	printf("\nEnter the number that you Guess [Round %d]: ",count);
    	scanf("%d",&y);
    	if(x==y){
    		printf("\n==Correct!! You Win==");
    	}
    	else {
    		if(y<x){
    			printf("Your number is less than Random Number");
    		}
    	    else if(y>x){
    			printf("Your Number is More than Random Number");
    		}
    	    if(count ==7 && x!=y)
    	    {
    			printf("\nYour Round is out You Lost");
    			printf("\nThe Random Number is : %d ",x);
    		}
    	}
    	}while(x!=y && count < 7);
    	do{
    		printf("\nPress [y] to play again or Press [n] to leave the game :  ");
    		scanf(" %c",&End);
    	}while(End != 'y' && End != 'n');
    }while(End	== 'y');
    printf("=== Thank You to Play Bye ===");
    return 0;
}

