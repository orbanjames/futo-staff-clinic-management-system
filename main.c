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

    do
    {
        printf("\n\n\n\n\t\t\t\t\tEnter Username & Password : ");
        printf("\n\n\n\t\t\t\t\tUsername : ");
        scanf("%s",&Username);
        printf("\n\n\t\t\t\t\tPassword : ");
        scanf("%s",&Password);
        if(strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
        {
            printf("\n\n\n\t\t\t\t.......Login Successfull....!!");
            getch();  // Used to hold screen..
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword is incorrect..: (Try Again..");
            e++;
            getch();
        }
    }while(e<=2);
    if(e>2)
    {
        printf("You have cross the limit . You cannot Login.  :):)");
        getch();
        ex_it();
    }
    system("cls");
}

//  ADD RECORD
void Add_rec(void)
{
    system("cls");
    Title();
    //List OF Variables..
    char ans;
    FILE *ek; // file pointer
    ek=fopen("Record2.dat","a"); //open file in write mode..
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!  Add Patients Record  !!!!!!!!!!!!!!!!!!\n");
    
// FIRST NAME..
    A:
    printf("\n\t\t\t First Name : ");
    scanf("%s",p.First_Name);
    p.First_Name[0]=toupper(p.First_Name[0]);  // First word change to UPPERCASE..
    if(strlen(p.First_Name)>20 || strlen(p.First_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
        goto A;
    }
    else
    {
        for(b=0;b<strlen(p.First_Name);b++)
        {
            if(isalpha(p.First_Name[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid Character :(Enter Again :)");
            goto A;
        }
    }

//  LAST NAME.....
    B:
    printf("\n\t\t\t Last Name  : ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0] = toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20 || strlen(p.Last_Name)<2)
    {
        printf("\n\t Invalid :(\t The max rangge for last name is 20 and min range is 2 :");
        goto B;
    }
    else
    {
        for(b=0;b<strlen(p.Last_Name);b++)
        {
            if(isalpha(p.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid Character : ( Enter again :)");
            goto B;
        }
    }
  