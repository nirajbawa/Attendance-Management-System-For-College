#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define clrscr(); system("cls");

int menu();

// menu fuctions
int admin_pannel();

int sudents_attendance_creator();

int adminDisplay();
// admin display's functions
int diaplayadminoptions();

int All_Account__list(char branch[30]);

int studentCreator();

int today_report(char branch[30]);

int monthly_report(char branch[30], int mo, int year);

int yearly_report(char branch[30], int year);

int search_report(char branch[30], char Roll_no[30]);

int student_account_edit();

// student_account_edit fucntion

int change_details(char branch[30], char filename[30], char rollno[30], int option);

int delete_account();

struct student
{
    char s_name[30];
    char s_rollNo[30];
    char s_whatsappNo[30];
    char s_email[30];
    int s_date;
    int s_mo;
    int s_year;
    char s_branch[30];
};

struct studentAT
{
    char sAT_name[30];
    char sAT_rollNo[30];
    // char sAT_whatsappNo[30];
    // char sAT_email[30];
    int sAT_date;
    int sAT_mo;
    int sAT_year;
    char sAT_branch[30];
};

int main()
{
    for (;;)
    {
        clrscr();
        int functioncall = menu();
        if (functioncall == 1)
        {
            break;
        }
        clrscr();
    }

    return 0;
}

// menu

int menu()
{

    fflush(stdin);

    clrscr();
    system("color 2");
    int option;
    int adminDiscall;
    // home screen
    printf("\n\n              Home Screen           \n\n\n       1.Admin Login\n\n       2.Student's Attendance\n\n       4.Exit\n\n\n       Select Your Option : ");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1:
        // admin login
        adminDiscall = adminDisplay();
        break;

    case 2:
        sudents_attendance_creator();
        break;
    case 3:
        // goto end;
        return 1;
        break;
    default:
        clrscr();
        printf("\n\n\t     Invalid option try again\n\n");
        getchar();
        break;
    }
}

int adminDisplay()
{

    // getting date time
    SYSTEMTIME stime;
    GetSystemTime(&stime);

    int day;
    int mo;

    int funccall;

    clrscr();

    printf("\n\n\n\t\t\tAdmin login\n\n\n");
    printf("\n\n\t\tEnter id : ");
    scanf("%d", &mo);
    printf("\n\n\t\tEnter password : ");
    scanf("%d", &day);
    if (stime.wMonth == mo && stime.wDay == day)
    {
        printf("\n\n\t\tyou are login success fully...!\n\n");
        printf("\n\t\tpress any key to continue\n\n");
        getch();
        clrscr();
        funccall = admin_pannel();
    }
    else
    {

        printf("\n\n\t\tPlease check your id and password and try again...\n\n\t\tEnter Any Key To Go Home : ");
        getch();
    }
    clrscr();
}

// admin pannel

int diaplayadminoptions()
{
    fflush(stdin);
    clrscr();
    printf("\n                   \tAdmin Pannel\n\n\n            1.All Student's Account List\n\n            2.Student's Attendance Reports\n\n            3.Student's Account Creator (Add New Account)\n\n            4.Student's Account Editor(Change Name, Roll_no, WhatsApp, Email)\n\n            5.Delete Student Account\n\n            8.Got back to home\n\n");
    fflush(stdin);
    return 0;
}

int admin_pannel()
{
    fflush(stdin);
    clrscr();
    for (;;)
    {
        fflush(stdin);
        clrscr();
        diaplayadminoptions();
        printf("\n\n\t    Select Your Option : ");
        int option2;

        // AT variables
        char branch[30];
        int branchcode;

        // AR variables
        int option3;
        int branchNO;
        char ARbranch[30];
        int mo;
        int year;
        char roll_No[30];

        int stduentCreatorCall;

        int goback2;

        scanf("%d", &option2);

        clrscr();

        switch (option2)
        {
        case 1:

            printf("\n\n\t\tSelect Your Branch Name : \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\n\t\t:::::: ");
            scanf("%d", &branchcode);
            switch (branchcode)
            {
            case 1:
                strcpy(branch, "co");
                break;

            case 2:
                strcpy(branch, "ce");
                break;

            case 3:
                strcpy(branch, "me");
                break;

            case 4:
                strcpy(branch, "eee");
                break;

            default:
                printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
                break;
            }

            All_Account__list(branch);
            clrscr();
            break;

        case 2:
            clrscr();
            printf("\n\n\n\t\t\tStudent's Attendance Reports : ");
            printf("\n\n\n\t\t1.Today's Report");
            printf("\n\n\t\t2.Monthly Report");
            printf("\n\n\t\t3.Yearly Report");
            printf("\n\n\t\t4.Search Report");
            printf("\n\n\t\t5.Exit");
            printf("\n\n\t\tSelect Your Option : ");
            scanf("%d", &option3);
            clrscr();
            printf("\n\n\t\tSelect Your Branch Name : \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\n\t\t:::::: ");
            scanf("%d", &branchNO);
            switch (branchNO)
            {
            case 1:
                strcpy(ARbranch, "co");
                break;

            case 2:
                strcpy(ARbranch, "ce");
                break;

            case 3:
                strcpy(ARbranch, "me");
                break;

            case 4:
                strcpy(ARbranch, "eee");
                break;

            default:
                printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
                break;
            }

            switch (option3)
            {
            case 1:
                clrscr();
                today_report(ARbranch);
                break;
            case 2:
                printf("\n\n\n\t\tEnter Month : \n\n\t\t1.jan\n\t\t2.feb\n\t\t3.mar\n\t\t4.apr\n\t\t5.may\n\t\t6.jun\n\t\t7.jul\n\t\t8.aug\n\t\t9.sep\n\t\t10.oct\n\t\t11.nov\n\t\t12.dec\n\n\t\tSelect Yout Option : ");
                scanf("%d", &mo);
                printf("\n\t\tEnter Year : ");
                scanf("%d", &year);
                monthly_report(ARbranch, mo, year);
                break;

            case 3:
                printf("\n\n\t\tEnter Year : ");
                scanf("%d", &year);
                yearly_report(ARbranch, year);
                break;

            case 4:
                printf("\n\n\t\tEnter Roll NO : ");
                scanf("%s", &roll_No);
                search_report(ARbranch, roll_No);
                break;

            case 5:
                
                break;

            default:
                printf("\n\n\t\tInvalid Option...!\n\n");
                break;
            }

            break;

        case 3:
            
            printf("\n\n\t\tYou Want to Continue OR Go Back\n\n\t\t1.Exit\n\n\t\t2.Continue\n\n\t\t:::::::: ");
            scanf("%d", &goback2);
            if(goback2==1)
            {

            }
            else{
            studentCreator();
            }
            clrscr();
            break;

        case 4:
            clrscr();

            student_account_edit();

            break;

        case 5:
            delete_account();
            clrscr();
            break;

        case 8:
            return 0;
            break;

        default:
            printf("\n\n\t     Invalid option try again\n\n");
            return 0;
            clrscr();
            break;
        }
    }
    clrscr();

    fflush(stdin);
    return 0;
}

// admin pannels functions

// Student's attended today function

int All_Account__list(char branch[30])
{
    fflush(stdin);
    clrscr();
    char filename[30];
    strcpy(filename, strcat(branch, ".txt"));
    FILE *openstd = NULL;
    openstd = fopen(filename, "rb+");
    struct student data;
    int count = 1;

    printf("\n\n\t\t All Student's Account list : \n\n\n");

    while (fread(&data, sizeof(data), 1, openstd) == 1)
    {

        printf("\t\t Sno : %d\n\n\t\t Name : %s\n\n\t\t Roll No : %s\n\n\t\t Whatsapp No : %s\n\n\t\t Email : %s \n\n\t\t Branch : %s  \n\n\n", count, data.s_name, data.s_rollNo, data.s_whatsappNo, data.s_email, data.s_branch);
        count++;
        printf("\t\t---------------------------------------------------\n\n\n");
    }

    fclose(openstd);
    fflush(stdin);
    getchar();
    clrscr();
}

// student creator

int studentCreator()
{
    fflush(stdin);
    clrscr();
    FILE *sdatabase = NULL;

    // getting date time
    SYSTEMTIME stime;

    GetSystemTime(&stime);

    struct student data;

    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\tStudent's account creator\n\n");
    char sName[30], sRollNo[30], sWhatsappNo[30], sEmail[30], sbranch[30], branch2[30], filename[30], extantion[30] = ".txt";
    int branchcode;
    printf("\n\n\t\tName : ");
    gets(sName);

    printf("\n\n\t\tRoll No : ");
    scanf("%s", &sRollNo);
    getchar();
    printf("\n\n\t\tWhatsapp No : ");
    gets(sWhatsappNo);

    printf("\n\n\t\tEmail : ");
    gets(sEmail);
branchpath:
    printf("\n\n\t\tBranch \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\t\t:::::: ");
    scanf("%d", &branchcode);

    switch (branchcode)
    {
    case 1:
        strcpy(sbranch, "co");
        break;

    case 2:
        strcpy(sbranch, "ce");
        break;

    case 3:
        strcpy(sbranch, "me");
        break;

    case 4:
        strcpy(sbranch, "eee");
        break;

    default:
        printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
        goto branchpath;
        break;
    }

    strcpy(branch2, sbranch);

    strcpy(filename, strcat(branch2, extantion));

    sdatabase = fopen(filename, "a+");

    fflush(stdin);

    strcpy(data.s_name, sName);
    strcpy(data.s_rollNo, sRollNo);
    strcpy(data.s_whatsappNo, sWhatsappNo);
    strcpy(data.s_email, sEmail);
    strcpy(data.s_branch, sbranch);

    // data.s_date = stime.wDay;
    // data.s_mo = stime.wMonth;
    // data.s_year = stime.wYear;

    data.s_date = 0;
    data.s_mo = 0;
    data.s_year = 0;

    fwrite(&data, sizeof(data), 1, sdatabase);
    fflush(stdin);

    fclose(sdatabase);
    printf("\n\n\t\tpress any key to go home : ");
    getchar();
    clrscr();
    fflush(stdin);
}

int today_report(char branch[30])
{
    clrscr();
    printf("\n\n\n\t\t\tToday's Report\n\n");
    FILE *TADB = NULL;
    char branch2[30], filename[30];

    SYSTEMTIME stime;

    GetSystemTime(&stime);

    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, "_A.txt"));

    TADB = fopen(filename, "rb+");

    struct studentAT AT;

    int count = 1;

    while (fread(&AT, sizeof(AT), 1, TADB) == 1)
    {
        if (strcmp(branch, AT.sAT_branch) == 0 && AT.sAT_date == stime.wDay && AT.sAT_mo == stime.wMonth && AT.sAT_year == stime.wYear)
        {
            printf("\n\n\t\tSno : %d\n\n\t\tName : %s \n\n\t\tBranch : %s\n\n\t\tRoll No : %s\n\n\t\tDate : %d-%d-%d\n\n\n", count, AT.sAT_name, AT.sAT_branch, AT.sAT_rollNo, AT.sAT_date, AT.sAT_mo, AT.sAT_year);
            count++;
        }
    }

    fclose(TADB);
    getch();
    clrscr();
}

int monthly_report(char branch[30], int mo, int year)
{
    clrscr();
    printf("\n\n\n\t\t\tMonthly Report\n\n");
    FILE *TADB = NULL;
    char branch2[30], filename[30];

    SYSTEMTIME stime;

    GetSystemTime(&stime);

    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, "_A.txt"));

    TADB = fopen(filename, "rb+");

    struct studentAT AT;

    int count = 1;

    while (fread(&AT, sizeof(AT), 1, TADB) == 1)
    {
        if (strcmp(branch, AT.sAT_branch) == 0 && AT.sAT_mo == mo && AT.sAT_year == year)
        {
            printf("\n\n\t\tSno : %d\n\n\t\tName : %s \n\n\t\tBranch : %s\n\n\t\tRoll No : %s\n\n\t\tDate : %d-%d-%d\n\n\n", count, AT.sAT_name, AT.sAT_branch, AT.sAT_rollNo, AT.sAT_date, AT.sAT_mo, AT.sAT_year);
            count++;
        }
    }

    fclose(TADB);
    getch();
    clrscr();
}

int yearly_report(char branch[30], int year)
{
    clrscr();
    printf("\n\n\n\t\t\tYearly Report\n\n");
    FILE *TADB = NULL;
    char branch2[30], filename[30];

    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, "_A.txt"));

    TADB = fopen(filename, "rb+");

    struct studentAT AT;

    int count = 1;

    while (fread(&AT, sizeof(AT), 1, TADB) == 1)
    {
        if (strcmp(branch, AT.sAT_branch) == 0 && AT.sAT_year == year)
        {
            printf("\n\n\t\tSno : %d\n\n\t\tName : %s \n\n\t\tBranch : %s\n\n\t\tRoll No : %s\n\n\t\tDate : %d-%d-%d\n\n\n", count, AT.sAT_name, AT.sAT_branch, AT.sAT_rollNo, AT.sAT_date, AT.sAT_mo, AT.sAT_year);
            count++;
        }
    }

    fclose(TADB);
    getch();
    clrscr();
}

int search_report(char branch[30], char Roll_no[30])
{
    clrscr();

    printf("\n\n\t\t\tSearch Report\n\n");

    FILE *TADB = NULL;
    char branch2[30], filename[30];

    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, "_A.txt"));

    TADB = fopen(filename, "rb+");

    struct studentAT AT;

    int count = 1;

    while (fread(&AT, sizeof(AT), 1, TADB) == 1)
    {
        if (strcmp(branch, AT.sAT_branch) == 0 && strcmp(Roll_no, AT.sAT_rollNo) == 0)
        {
            printf("\n\n\t\tSno : %d\n\n\t\tName : %s \n\n\t\tBranch : %s\n\n\t\tRoll No : %s\n\n\t\tDate : %d-%d-%d\n\n\n", count, AT.sAT_name, AT.sAT_branch, AT.sAT_rollNo, AT.sAT_date, AT.sAT_mo, AT.sAT_year);
            count++;
        }
    }

    fclose(TADB);
    getch();
    clrscr();
}

// student_account_edit function

int student_account_edit()
{
    clrscr();
    printf("\n\n\t\t\tStudent's account editor\n\n");
    char rollno[30];
    int branchNO;
    char branch[30], branch2[30], filename[30];
    int option3;
    printf("\n\n\n\t\tEnter Roll No : ");
    scanf("%s", &rollno);
    getch();

brepeat:
    printf("\n\t\tSelect Your Branch Name : \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\n\t\t:::::: ");
    scanf("%d", &branchNO);
    switch (branchNO)
    {
    case 1:
        strcpy(branch, "co");
        break;

    case 2:
        strcpy(branch, "ce");
        break;

    case 3:
        strcpy(branch, "me");
        break;

    case 4:
        strcpy(branch, "eee");
        break;

    default:
        printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
        goto brepeat;
        break;
    }

    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, ".txt"));
    FILE *studentDB = NULL;

    studentDB = fopen(filename, "rb+");

    struct student data;

    int count = 1;

    printf("\n\n\t\tOld Details : \n\n\n");
    while (fread(&data, sizeof(data), 1, studentDB) == 1)
    {
        if (strcmp(branch, data.s_branch) == 0 && strcmp(rollno, data.s_rollNo) == 0)
        {
            printf("\t\t Sno : %d\n\n\t\t 1.Name : %s\n\n\t\t 2.Roll No : %s\n\n\t\t 3.Whatsapp No : %s\n\n\t\t 4.Email : %s \n\n\t\t 5.Branch : %s", count, data.s_name, data.s_rollNo, data.s_whatsappNo, data.s_email, data.s_branch);
            count++;
            break;
        }
    }
    fflush(stdin);

    fclose(studentDB);

    fflush(stdin);
    if (count == 1)
    {
        clrscr();
        return 0;
    }

startloop:

    printf("\n\n\n\t\t1.Name\n\t\t2.Roll No\n\t\t3.Whatsapp No\n\t\t4.Email\n\t\t5.Branch\n\t\t6.Exit\n");

    printf("\n\n\t\tSelect Option To Edit : ");
    scanf("%d", &option3);

    char name[30];
    switch (option3)
    {
    case 1:
        change_details(branch, filename, rollno, option3);
        clrscr();
        printf("\n\t\tDetails Update Successfully.....!\n\t\tPress Any Key To Continue : ");
        getch();
        clrscr();
        goto startloop;
        break;

    case 2:
        change_details(branch, filename, rollno, option3);
        clrscr();
        printf("\n\t\tDetails Update Successfully.....!\n\t\tPress Any Key To Continue : ");
        getch();
        clrscr();
        goto endloop;
        break;

    case 3:
        change_details(branch, filename, rollno, option3);
        clrscr();
        printf("\n\t\tDetails Update Successfully.....!\n\t\tPress Any Key To Continue : ");
        getch();
        clrscr();
        goto startloop;
        break;

    case 4:
        change_details(branch, filename, rollno, option3);
        clrscr();
        printf("\n\t\tDetails Update Successfully.....!\n\t\tPress Any Key To Continue : ");
        getch();
        clrscr();
        goto startloop;
        break;

    case 5:
        change_details(branch, filename, rollno, option3);
        clrscr();
        printf("\n\t\tDetails Update Successfully.....!\n\t\tPress Any Key To Continue : ");
        getch();
        clrscr();
        goto endloop;
        break;

    case 6:
        goto endloop;
        break;

    default:
        printf("\n\t\tPlease Try Again.........!\n\n");
        break;
    }

endloop:

    getch();
    clrscr();
}

int change_details(char branch[30], char filename[30], char rollno[30], int option)
{
    FILE *studentDB = NULL;

    studentDB = fopen(filename, "rb+");

    struct student data;

    int count = 1;
    rewind(studentDB);
    printf("\n\n\t\tEnter New Details : \n");
    fflush(stdin);
    while (fread(&data, sizeof(data), 1, studentDB) == 1)
    {
        if (strcmp(branch, data.s_branch) == 0 && strcmp(rollno, data.s_rollNo) == 0)
        {
            switch (option)
            {
            case 1:
                printf("\n\n\t\tEnter name : ");
                gets(data.s_name);
                break;

            case 2:
                printf("\n\n\t\tEnter Roll No : ");
                gets(data.s_rollNo);
                break;

            case 3:
                printf("\n\n\t\tEnter Whatsapp No : ");
                gets(data.s_whatsappNo);
                break;

            case 4:
                printf("\n\n\t\tEnter Email : ");
                gets(data.s_email);
                break;

            case 5:
                printf("\n\n\t\tEnter Branch : ");
                gets(data.s_branch);
                break;
            default:
                break;
            }

            fseek(studentDB, -sizeof(data), SEEK_CUR);
            fwrite(&data, sizeof(data), 1, studentDB);
            break;
        }
    }
    fclose(studentDB);
}

// delete_account functions

int delete_account()
{

    int branchcode;
    char rollno[30], branch[30], branch2[30], filename[30];
    clrscr();
    printf("\n\n\t\t\t\tStudent Account Remover\n");
    printf("\n\n\t\tEnter Roll No : ");
    scanf("%s", &rollno);

brepeatd:
    printf("\n\t\tSelect Your Branch Name : \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\n\t\t:::::: ");
    scanf("%d", &branchcode);
    switch (branchcode)
    {
    case 1:
        strcpy(branch, "co");
        break;

    case 2:
        strcpy(branch, "ce");
        break;

    case 3:
        strcpy(branch, "me");
        break;

    case 4:
        strcpy(branch, "eee");
        break;

    default:
        printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
        goto brepeatd;
        break;
    }



    strcpy(branch2, branch);
    strcpy(filename, strcat(branch2, ".txt"));

    FILE *studentDB = NULL;

    studentDB = fopen(filename, "rb+");

    struct student data;

    int count = 1;

    printf("\n\n\t\tAccount Details : \n\n\n");
    while (fread(&data, sizeof(data), 1, studentDB) == 1)
    {
        if (strcmp(branch, data.s_branch) == 0 && strcmp(rollno, data.s_rollNo) == 0)
        {
            printf("\t\t Sno : %d\n\n\t\t 1.Name : %s\n\n\t\t 2.Roll No : %s\n\n\t\t 3.Whatsapp No : %s\n\n\t\t 4.Email : %s \n\n\t\t 5.Branch : %s", count, data.s_name, data.s_rollNo, data.s_whatsappNo, data.s_email, data.s_branch);
            count++;
            break;
        }
    }

    fclose(studentDB);

    if (count == 1)
    {
        clrscr();
        return 0;
    }

    printf("\n\n\n\t\tYou Want To Delete This Account : \n\n\t\t1.Exit\n\n\t\t2.Continue\n\n\t\t::::: ");
    int goback;
    scanf("%d", &goback);
    if (goback == 1)
    {
        return 0;
    }
    else
    {
        FILE *StudentDDB = NULL;
        FILE *TEMPDDB = NULL;
        // struct student data;
        StudentDDB = fopen(filename, "rb+");
        TEMPDDB = fopen("temp.txt", "wb+");
        while (fread(&data, sizeof(data), 1, StudentDDB) == 1)
        {
            if (strcmp(rollno, data.s_rollNo) != 0)
            {
                fwrite(&data, sizeof(data), 1, TEMPDDB);
            }
        }
        fclose(StudentDDB);
        fclose(TEMPDDB);

        remove(filename);
        rename("temp.txt", filename);
        printf("\n\n\t\tFile Delete Successfully.....!\n\n");
        getch();
    }
}

// sudents attendance creator function

int sudents_attendance_creator()
{
    clrscr();
    char rollNo[30], branch[30], branch1[30], branch2[30], filenameA[30], filenameD[30];
    int branchcode;
    printf("\n\n\t\t\tStudents Attendance \n\n");
    printf("\t\t\tEnter Your Details To Add Attendance\n");
    printf("\n\n\t\t Roll No : ");
    scanf("%s", &rollNo);
    printf("\n\n\t\tBranch \n\n\t\t1.Co\n\t\t2.Ce\n\t\t3.Me\n\t\t4.Eee:\n\t\t:::::: ");
    scanf("%d", &branchcode);

    switch (branchcode)
    {
    case 1:
        strcpy(branch, "co");
        break;

    case 2:
        strcpy(branch, "ce");
        break;

    case 3:
        strcpy(branch, "me");
        break;

    case 4:
        strcpy(branch, "eee");
        break;

    default:
        printf("\n\n\t\tPlease Choose Valid Option....!\n\n");
        clrscr();
        break;
    }

    strcpy(branch1, branch);
    strcpy(branch2, branch);

    strcpy(filenameA, strcat(branch1, "_A.txt"));
    strcpy(filenameD, strcat(branch2, ".txt"));

    FILE *studentAR = NULL;

    FILE *studnetDB = NULL;

    studnetDB = fopen(filenameD, "rb+");

    struct student data;
    struct studentAT AT;

    // getting date time
    SYSTEMTIME stime;

    GetSystemTime(&stime);

    studentAR = fopen(filenameA, "a+");

    // rewind(studentAR);

    int count = 0;

    rewind(studnetDB);
    fflush(stdin);
    while (fread(&data, sizeof(data), 1, studnetDB) == 1)
    {
        if (strcmp(rollNo, data.s_rollNo) == 0 && strcmp(branch, data.s_branch) == 0 && stime.wDay != data.s_date)
        {
            data.s_date = stime.wDay;
            data.s_mo = stime.wMonth;
            data.s_year = stime.wYear;
            fseek(studnetDB, -sizeof(data), SEEK_CUR);
            fwrite(&data, sizeof(data), 1, studnetDB);
            strcpy(AT.sAT_name, data.s_name);
            count++;
            break;
        }
    }

    if (count > 0)
    {
        strcpy(AT.sAT_rollNo, rollNo);
        strcpy(AT.sAT_branch, branch);
        AT.sAT_date = stime.wDay;
        AT.sAT_mo = stime.wMonth;
        AT.sAT_year = stime.wYear;

        // AT.sAT_date = 03;
        // AT.sAT_mo = 05;

        // AT.sAT_year = 2022;

        fwrite(&AT, sizeof(AT), 1, studentAR);
    }

    fclose(studentAR);
    fclose(studnetDB);
    printf("\n\n\t\tAttendance Added Successfully...!");
    getch();
    clrscr();
}
