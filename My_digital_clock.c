#include <stdio.h>
#include <time.h> 
#include<stdlib.h>
#include<windows.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
int main()
{
	system("color 0A");
    int i,j,r, q, hour, minute, second;
    printf("\nEnter current hour which is less than 24:");
    scanf("%d",&hour);
    printf("\nEnter current minutes which is less than 60:");
    scanf("%d",&minute);
    printf("\nEnter current seconds which is less than 60:");
    scanf("%d",&second);
	system("cls");
 	gotoxy(32,06);
 	printf("\nInitializing your clock....");
 	gotoxy(32,07);
	for(r=1;r<=20;r++)
	{
		for(q=0;q<=10000000;q++);
		printf("%c",177);
	}
    while(1)
    {
        //clear output screen
        system("cls");
        for(i=1; i<=17; ++i)
    	{
        for(j=1; j<=i; ++j)
        {
            printf(" * ");
        }
        printf("\n");
		}
        //print time in HH : MM : SS format
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%02d : %02d : %02d ",hour,minute,second);
         
         //clear output buffer in gcc
        fflush(stdout);
        printf("\n");
        time_t now = time(NULL);
   		struct tm *t = localtime(&now);
   		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%02d//%02d//%02d",t->tm_mday,t->tm_mon+1,t->tm_year+1900 );
        printf("\n\n\n\n");
        for(i=17; i>=1; --i)
    {
        for(j=1; j<=i; ++j)
        {
            printf(" * ");
        }
        printf("\n");
    } 
         //increase second
        second++;
 
        //update hour, minute and second
        if(second==60){
            minute+=1;
            second=0;
        }
        if(minute==60){
            hour+=1;
            minute=0;
        }
        if(hour==24){
            hour=0;
            minute=0;
            second=0;
        }
         
       sleep(1);   //wait till 1 second
    }
 
    return 0;
}
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
		coord.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

