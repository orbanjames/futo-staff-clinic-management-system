#include<stdio.h>
#include<stdlib.h>
#include<windows.h> // gotoxy()...
#include<conio.h>   // used for delay(), getch()..
#include<ctype.h>   // used for to-upper(),to-lower() etc...
#include<string.h>  // used for strcpy(),strlen()  etc...
char ans=0;
int ok;
int b,valid=0;
// Function Declaration...
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x,short y)
{
    COORD pos ={x ,y}; // sets co-ordinates in (x,y)....
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

// List of Globar Variable...

struct patient
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Address[30];
    char Contact_no[15];
    char Email[30];
    char Staff_Id[20];
    char Doctor[20];
    char Problem[20];
};
struct patient p,temp_c;
void main(void)
{
    WelcomeScreen();
    Title();
    LoginScreen();
}
// Welcome Screen...
void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#              WELCOME TO         \t#");
    printf("\n\t\t\t\t#      FUTO STAFF CLINIC MANAGEMENT SYSTEM  \t#");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\n\n Press any Key.......\n");
    getch();
    system("cls"); // used to clear screen...  or use clsscr();
}

// Title screen..
void Title(void)
{
    printf("\n\n\t\t------------------------------------------------------------------------");
    printf("\n\t\t\t\t         FUTO STAFF CLINIC           ");
    printf("\n\t\t------------------------------------------------------------------------");
}