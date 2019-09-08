#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

void returnfunc(void);
void mainmenu(void);
void addquest(void);
void viewuser(void);
void adduser(void);
void searchans(void);
void giveans(void);
void viewquest(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findques;
char password[10]={"astsat"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct que
{
int id;
char title[20];
char s[500];

};

struct user
{
    int uid;
    char name[30];
    int score;
    char college[30];
};

struct que a;
struct user u;

int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{
system("cls");
int i;
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add Questions   ");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. View Users");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Search Answer");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. Give Solution");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. View Questions");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. Add Users");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
gotoxy(20,19);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,20);

gotoxy(20,21);
printf("Enter your choice:");
switch(getch())
{
case '1':
addquest();
break;
case '2':
viewuser();
break;
case '3':
searchans();
break;
case '4':
giveans();
break;
case '5':
viewquest();
break;
case '6':
adduser();
break;
case '7':
{
system("cls");
gotoxy(16,3);
printf("\tPROJECT CHEFF");
gotoxy(16,4);
printf("\tMADE BY");
gotoxy(16,5);
printf("\t ABHISHEK SUNIL TIWARI");
gotoxy(16,7);
printf("\t ROHIL VARMA");
gotoxy(16,8);
printf("******************************************");
gotoxy(16,10);
printf("*******************************************");
gotoxy(16,11);
printf("*******************************************");
gotoxy(16,13);
printf("********************************************");
gotoxy(10,17);
printf("Exiting in 3 second...........>");
//flushall();
Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
void addquest(void)    //funtion that add question
{
    system("cls");
    printf("give the id : ");
    scanf("%d",&a.id);

    system("cls");
    printf("whats the title : ");
    scanf("%s",a.title);

    system("cls");
    printf("write the question \n");
    scanf("%s",a.s);

    fp=fopen("questions.dat","ab+");
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);

    int x;
    printf("\n\n\npress 1 for main menu : ");
    scanf("%d",&x);
    if(x)
        mainmenu();

}
void viewuser()
{

    int i=0;
system("cls");
int j=4;
printf("*******************************USERS LIST*******************************\n");
gotoxy(2,2);
printf("USER ID   USER NAME    COLLEGE    SCORE");

fs=fopen("users.dat","rb+");
rewind(fs); //open file for reading propose
while(fread(&u,sizeof(u),1,fs)==1)
{

gotoxy(2,j);
printf("%d",u.uid);
gotoxy(13,j);
printf("%s",u.name);
gotoxy(25,j);
printf("%s",u.college);
gotoxy(36,j);
printf("%s",u.score);

j++;
}
    int x;
    printf("\n\n\npress 1 for main menu : ");
    scanf("%d",&x);
    if(x)
        mainmenu();
}
void searchans()
{

}
void giveans(void)  //function that issue books from library
{

}
void adduser(void)
{
    system("cls");
    printf("give the user id : ");
    scanf("%d",&u.uid);

    system("cls");
    printf("Enter your name : ");
    scanf("%s",u.name);

    system("cls");
    printf("Enter your college \n");
    scanf("%s",u.college);

    u.score=0;

    fs=fopen("users.dat","ab+");
    fseek(fs,0,SEEK_END);
    fwrite(&u,sizeof(u),1,fs);
    fclose(fs);

    int x;
    printf("\n\n\npress 1 for main menu : ");
    scanf("%d",&x);
    if(x)
        mainmenu();

}

void viewquest()
{

int i=0;
system("cls");
int j=4;
printf("*******************************Questions list*******************************\n");
gotoxy(2,2);
printf("Qusetion ID   Qusetion Title    Question ");

fs=fopen("questions.dat","rb+");
rewind(fs); //open file for reading propose
while(fread(&a,sizeof(a),1,fs)==1)
{

gotoxy(2,j);
printf("%d",a.id);
gotoxy(18,j);
printf("%s",a.title);
gotoxy(30,j);
printf("%s",a.s);
gotoxy(36,j);

j++;

}

    int x;
    printf("\n\n\npress 1 for main menu : ");
    scanf("%d",&x);
    if(x)
        mainmenu();
}

void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;

gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
