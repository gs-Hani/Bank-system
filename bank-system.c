#include <stdio.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (y),(x))

int main() {

	int i,a,b,choice;
	int passwordlength;

	gotoxy(18,5);

	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    	gotoxy(18, 5);	

	printf("**********************************");
   	gotoxy(25, 7);

    	printf("DEVELOPER-Hani Al Azzawi");

    	gotoxy(20, 10);
    	printf("1.... CREATE A BANK ACCOUNT");

    	gotoxy(20, 12);
    	printf("2.... ALREADY A USER? SIGN IN");

    	gotoxy(20, 14);
    	printf("3.... EXIT\n\n");

    	printf("\n\nENTER YOUR CHOICE..");

}
