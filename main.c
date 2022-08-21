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

// Function definition of Main Menu..
void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record.\n");
    printf("\n\t\t\t\t2. List Patients Record.\n");
    printf("\n\t\t\t\t3. Search Patients Record.\n");
    printf("\n\t\t\t\t4. Edit Patients Record.\n");
    printf("\n\t\t\t\t5. Delete Patients Record.\n");
    printf("\n\t\t\t\t6. Exit. \n");
    printf("\n\n\n\n\t\t\t\tChoose from 1 to 6: ");
    scanf("%i",&choose);
    switch(choose)
    {
        case 1:
        Add_rec();
        break;
        case 2:
        func_list();
        break;
        case 3:
        Search_rec();
        break;
        case 4:
        Edit_rec();
        break;
        case 5:
        Dlt_rec();
        break;
        case 6:
        ex_it();
        break;
        default:
        printf("\t\t\tInvalid Entry, Please enter right Choice..!");
        getch();
    }
}

void ex_it(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\tThank You For Visiting...!");
    getch();
}

// log_in...
void LoginScreen(void)
{

    int e=0;
    char Username[15];
    char Password[15];
    char original_Username[25]="Govind";
    char original_Password[15]="252325";

    