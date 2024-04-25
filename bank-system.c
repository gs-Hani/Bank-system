#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (y),(x))

// Declaring all the functions
void account(void);
void initTermios(int echo);
void resetTermios(void);
void accountCreated(void);
void login(void);

// Creating a structure to store data of the user
struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};

struct userpass {
    char password[50];
};
// This struct is used to change the i/o settings 
static struct termios old, current;

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

	scanf("%d", &choice);

	switch(choice) {
		case 1:
			system("clear");
			printf("\n\n USERNAME 50 CHARACTERS MAX!!");
       		 	printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        		account();
        		break;		
	}

}

// Function to create accounts of users
void account (void) {
	char password[20];
	int passwordLength, i ,seek = 0;
	int c,ch;
	FILE *fp, *fu;

	struct pass u1;
	struct userpass p1;
   	struct userpass u2;

	// Opening file to write data of a user
	fp = fopen("username.txt", "ab");

	// Inputs
    	system("clear");
    	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
 
    	printf("\n\nFIRST NAME..");
    	scanf("%s", &u1.fname);
 
    	printf("\n\n\nLAST NAME..");
    	scanf("%s", &u1.lname);
 
    	printf("\n\nFATHER's NAME..");
    	scanf("%s", &u1.fathname);
 
    	printf("\n\nMOTHER's NAME..");
    	scanf("%s", &u1.mothname);
 
    	printf("\n\nADDRESS..");
    	scanf("%s", &u1.address);
 
    	printf("\n\nACCOUNT TYPE..");
    	scanf("%s", &u1.typeaccount);
 
    	printf("\n\nDATE OF BIRTH..");
    	printf("\nDAY-");
    	scanf("%d", &u1.date);
    	printf("\nMONTH-");
    	scanf("%d", &u1.month);
    	printf("\nYEAR-");
    	scanf("%d", &u1.year);
 
    	printf("\n\nADHAR NUMBER..");
    	scanf("%s", u1.adharnum);
 
    	printf("\n\nPHONE NUMBER..");
    	scanf("%s", u1.pnumber);
 
    	printf("\n\nUSERNAME.. ");
    	scanf("%s", &u1.username);
 
    	printf("\n\nPASSWORD..");
	
	//clear the input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }

	// Taking password in the form of stars
	initTermios(0);	
    	for (i = 0; i < 50; i++) {
        	ch = getchar();
        	if (ch != 10) {
           		password[i] = ch;
            		ch = '*';
            		printf("%c", ch);
        	}
        	else break;
	}	
	resetTermios();
	// Writing to the file
    	fwrite(&u1, sizeof(u1), 1, fp);
	// Closing file
    	fclose(fp);

	accountCreated();
}


/* Initialize new terminal i/o settings */
void initTermios(int echo) {
	tcgetattr(0, &old);	/* grab old terminal i/o settings */
	current = old; 		/* make new settings same as old settings */
  	current.c_lflag &= ~ICANON;	/* disable buffered i/o */
  	if (echo) {
      		current.c_lflag |= ECHO; 	/* set echo mode */
  	} else {
      		current.c_lflag &= ~ECHO; 	/* set no echo mode */
  	}
  		tcsetattr(0, TCSANOW, &current); 	/* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
  	tcsetattr(0, TCSANOW, &old);
}

//successful account creation
void accountCreated(void) {
	int i;
	char ch;

	system("clear");
	printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING...." );

	for ( i = 0; i < 200000000; i++ ) {
		i++;
		i--;
	}

	gotoxy(30,10);
	printf("ACCOUNT CREATED SUCCESSFULY....");

	gotoxy(0,20);
	printf("Press enter to login\n");

	initTermios(0);
	getchar();
	resetTermios();

	login();
}

void login(void) {
	system("clear");

	char username[50];
	char password[50];
	int i,j,k;
	char ch;
	FILE *fp,*fu;
	struct pass u1;
	struct userpass u2;

	//opening file of user data
	fp = fopen("username.txt","rb");
	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}

	gotoxy(34,2);
	printf("ACCOUNT LOGIN");

	gotoxy(7, 5);
    	printf("***********************************************""********************************");
	gotoxy(35, 10);

    	printf("==== LOG IN ====");

	gotoxy(35, 12);
    	printf("USERNAME.. ");
    	scanf("%s", &username);

    	gotoxy(35, 14);
    	printf("PASSWORD..");
	initTermios(0);	
    	for (i = 0; i < 50; i++) {
        	ch = getchar();
        	if (ch != 10) {
           		password[i] = ch;
            		ch = '*';
            		printf("%c", ch);
        	}
        	else break;
	}	
	resetTermios();

	// Checking if username exists in the file or not
	while (fread(&u1, sizeof(u1), 1, fp)) {
        	if (strcmp(username,u1.username) == 0) {
            		printf("login successful\n");
			//loginsu();
            		//display(username);
        	}
    	}
 
    	// Closing the file
    	fclose(fp);
}

// Redirect after successful login
void loginsu(void) {
	int i;
	FILE *fp;
	struct pass u1;

	system("clear");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
    	printf("LOGIN SUCCESSFUL....");

    	gotoxy(0, 20);
    	printf("Press enter to continue");
	initTermios(0);
	getchar();
	resetTermios();
}
