#include<stdio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0;
int r;
int id;
string usn;
void gotoXY(int,int);
void Cdelay(int);
void border(int, int,int, int);
void borderNoDelay(int, int,int, int);
void loginFrame(int, int, int, int);
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editname(int);
void editcode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void setWindowSize(int,int);
void saverecords();
int getrecords();
bool isFilePresent();
void displayPayslip();
void Emp_login();
void finduser();
void EmpChoice();
void editemp();
void editempmenu();
void  listemp();
void emp_details();
void emp_payslip();
void Designations();


class employee
{
public:
	char name[20];
	int code;
	char department[20];
	char designation[20];
	char pass[20];
	int exp;
	int age;
	int salary;

	int HRA;
	int PF;
	int EPF;
	int ESI;
	int tax;
	int Bonus;
	int TransportAllowance;
	int MedicalAllowance;

	int grosspay;
	int workingdays;
	int DA;
    int OTS;
};
employee emp[max],tempemp[max],em[max];


int getrecords()
{
	FILE *fp;
	fp = fopen("Records1.txt","r");
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].name,&emp[c].pass,&emp[c].code,&emp[c].designation,&emp[c].department,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].ESI,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].Bonus,&emp[c].TransportAllowance,&emp[c].MedicalAllowance,&emp[c].grosspay,&emp[c].workingdays,&emp[c].DA,&emp[c].OTS);
			c++;
		}
		num=c;
	}
	fclose(fp);
	return num;
}
int getemprecords()
{
	FILE *fp;
	fp = fopen("Records1.txt","r");
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&em[c].name,&em[c].pass,&em[c].code,&em[c].designation,&em[c].department,&em[c].exp,&em[c].age,&em[c].salary,&em[c].ESI,&em[c].HRA,&em[c].PF,&em[c].tax,&em[c].Bonus,&em[c].TransportAllowance,&em[c].MedicalAllowance,&em[c].grosspay,&em[c].workingdays,&em[c].DA,&em[c].OTS);
			c++;
		}
		num=c;
	}
	fclose(fp);
	return num;
}
void saverecords()
{
	if(num==0)
	{
		system("del Records1.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records1.txt","w");
		for(int i=0;i<num;i++)
		{
		    if(emp[i].code==0)
                return;
			fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].name,emp[i].pass,emp[i].code,emp[i].designation,emp[i].department,emp[i].exp,emp[i].age,emp[i].salary,emp[i].ESI,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].Bonus,emp[i].TransportAllowance,emp[i].MedicalAllowance,emp[i].grosspay,emp[i].workingdays,emp[i].DA,emp[i].OTS);
		}
		fclose(fp);
	}
}

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records1.txt","r");
	if(fp==NULL)
		return false;
	else
		return true;
}
void loginFrame1(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);

	gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        //Cdelay(0);
        gotoXY(i,yLenS);
        printf("%c",205);
		//puts(style);
        gotoXY(i,yLenE);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        //Cdelay(20);
        gotoXY(xLenS, i);
        printf("%c",186);
		//puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
		//puts(style);
    }
    printf("\n\n");
}
void login()
{

	char UserName[30],Password[30],ch;int i=0;
	gotoXY(20,10);
    printf("Enter UserName : ");

    cin>>UserName;
    gotoXY(20,12);
    cout<<"Enter Password : ";
    while(1)
    {
    	ch = getch();
    	if(ch==13)
    		break;
    	if(ch==32||ch==9)
    		continue;
    	else
    	{
			cout<<"*";
			Password[i]=ch;
			i++;
    	}
	}
	Password[i] = '\0';
    if(strcmp(UserName,"admin")==0 && strcmp(Password,"password")==0)
    {
    	system("cls");
    	loginFrame1();
    	gotoXY(27,10);
    	cout<<"Login Success!!!";
    	gotoXY(21,12);
    	cout<<"Will be redirected in 3 Seconds...";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b2";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b1";
    		gotoXY(56,12);
    	Cdelay(1000);
	}
	else
	{
		system("cls");
    	loginFrame1();
    	gotoXY(27,10);
		printf("Access Denied!!!\a");
    	gotoXY(21,12);
    	cout<<"Will be redirected in 3 Seconds...";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b2";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b1";
    		gotoXY(56,12);
    	Cdelay(1000);
    	system("cls");
    	loginFrame1();
    	login();
	}
}
void setWindowSize(int width=670,int height=445)
{
	//HWND console = GetConsoleWindow();
	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2,int xLenE = 76, int yLenE = 24 )
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);

	gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);
    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void border(int xLenS = 2, int yLenS = 2,int xLenE = 76, int yLenE = 22 )
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);

	gotoXY(xLenS,yLenE);printf("%c",200);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        Cdelay(15);
        gotoXY(i,yLenS);
        printf("%c",205);
		//puts(style);
        gotoXY(i,yLenE);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c",186);
		//puts(style);
        gotoXY(xLenE, i);
        printf("%c",186);
		//puts(style);
    }
    printf("\n\n");
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    border(xLenS,yLenS,xLenE,yLenE);
}

void insert()
{
	borderNoDelay();
	int i=num;
	int code,j,no;
	int sal,PF,TAX,ESI,HRA,bonus,MedicalA,TransportA,LoanBal,LoanDeb,h,DA,dailsal,ot,otsal,esi,epf;
	char nm[20];

	//num+=1;
	gotoXY(28,4);
	printf("Insert New Record");
	gotoXY(10,6);
	cout<<"Employee Id : ";
	cin>>code;//emp[i].code;

 for (int k = 0; k < num; k++)
    {
        if (emp[k].code == code)
        {
            gotoXY(10, 8);
            cout << "Employee with the same code already exists!";
            getch();
            return;
        }
    }
    num+=1;
    emp[i].code=code;
	gotoXY(10,8);
	cout<<"Name : ";
	cin>>emp[i].name;
	//emp[i].pass=emp[i].name;
	gotoXY(10,10);
	cout<<"Enter the password ";
	cin>>emp[i].pass;
	gotoXY(10,12);
	cout<<"Designation :";
	cin>>emp[i].designation;
	gotoXY(10,14);
	cout<<"Department : ";
	cin>>emp[i].department;
	gotoXY(10,12);
	//cout<<"Years of Experience : ";
	//cin>>emp[i].exp;
	gotoXY(10,16);
	cout<<"Age : ";
	cin>>emp[i].age;
	gotoXY(10,18);
	cout<<"Enter the daily salary :";
	cin>>dailsal;
	gotoXY(10,20);
	cout<<"Enter Overtime Allowence in hours (if Yes / if No give 0) ";
	cin>>ot;
	gotoXY(10,22);
	cout<<"Enter Working days : ";
	cin>>h;
	otsal=ot*100;
	sal = (h*dailsal) ;
	emp[i].workingdays = h;
	gotoXY(14,26);
	cout<<"Recorded Succesfully...!!!";

	TAX =  0.04 * sal;
	DA = 0.35 * sal;
	PF = 0.12 * sal;
    esi=0.10*sal;
	HRA = sal * 0.27;
	bonus = 0.05*sal;
	MedicalA = 1000;
	TransportA = 1000;

	emp[i].salary = sal;
	emp[i].DA = DA;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].ESI=esi;
	emp[i].HRA = HRA;
	emp[i].Bonus = bonus;
	emp[i].OTS=otsal;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;
	emp[i].grosspay = (sal+bonus+MedicalA+TransportA+HRA+DA+otsal)-(PF+TAX+esi) ;
	getch();
	saverecords();
}

void Designations()
{
    system("cls");
	borderNoDelay();
	gotoXY(8,6);
	cout<<"PLEASE VERIFY THE DESIGNATION AND THIER SALARY ";
	gotoXY(8,10);
	cout<<"---->Masons (800Rs per day)";
	gotoXY(8,12);
	cout<<"---->Carpenters (800Rs per day)";
	gotoXY(8,14);
	cout<<"---->Electricians (600Rs per day)";
	gotoXY(8,16);
	cout<<"---->Painters (600Rs per day)";
	gotoXY(8,18);
	cout<<"---->Heavy Equipment Operator (600Rs per day)";
	gotoXY(8,20);
	cout<<"---->New Designation (Give Respected Salary) ";
	getch();
	insert();
}

void intro()
{
    gotoXY(26,3); printf("***** WELCOME TO *****");
	gotoXY(14,5); printf("*** CONSTRUCTION EMPLOYEE PAYROLL SYSTEM ***");

	gotoXY(22,7);   cout<<"|.....              ......";
	gotoXY(22,8);   cout<<"|    .         ......     ";
	gotoXY(22,9);   cout<<"|    ......    .    .    .";
	gotoXY(22,10);  cout<<"|    .    .    .    .    .";
	gotoXY(22,11);  cout<<"|    .    ......    .    .";
	gotoXY(22,12);  cout<<"|    .    .    .    .    .";
	gotoXY(22,13);  cout<<"|    .    .    .    .    .";
	gotoXY(22,14);  cout<<"|____.____.____.____.____.____.____.____";
    gotoXY(12,18); printf("** The Road To Success Is Always Under Construction**");
    gotoXY(24,20);printf("Press Any key to continue...");
    //gotoXY()
    getch();

}

void  list()
{
	//system("cls");
	borderNoDelay();
	gotoXY(20,4);
	printf("******** List of the Employees ********");
	gotoXY(6,6);
	cout<<"Name\tCode \tDesignation \tDepartment\t Age\tSalary "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<emp[i].name;
		gotoXY(18,j);
		cout<<emp[i].code;
		gotoXY(24,j);
		cout<<emp[i].designation;
		gotoXY(39,j);
		cout<<emp[i].department;
		gotoXY(58,j);
		cout<<emp[i].age;
		gotoXY(65,j);
		cout<<emp[i].grosspay;
	}
	getch();
}

void loading()
{
	system("cls");
    gotoXY(55,20);
    printf("Loading...");
    gotoXY(50,22);
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}
void menu()
{
	//system("cls");
	borderNoDelay();
	//gotoXY(0,0);
	//cout<<"Number of Records Avaliable : "<<num;
	gotoXY(16,4);
	printf("***** Construction Employee Payroll System ***** ");
	gotoXY(12,6);
	cout<<"Press  1 ----> Insert New Record.";
	gotoXY(12,8);
	cout<<"Press  2 ----> Edit a Record.";
	gotoXY(12,10);
	cout<<"Press  3 ----> Delete a Record.";
	gotoXY(12,12);
	cout<<"Press  4 ----> Search a Record.";
	gotoXY(12,14);
	cout<<"Press  5 ----> List The Employee Table.";
	gotoXY(12,16);
	cout<<"Press  6 ----> Print Employee PaySlip.";
	gotoXY(12,18);
	cout<<"Press  7 ----> Go To Login Page.";
	gotoXY(16,22);
	cout<<"Select Your Option ====> ";
}

void deletes()
{
	for(int i=0;i<num;i++)
	{
		tempemp[i]=emp[i];
	}
	//system("cls");
	borderNoDelay();
	int code;
	int check=-1;
	gotoXY(28,4);
	printf("Delete a Record");
	gotoXY(10,6);
	cout<<"Enter the ID To Delete That Record  :";
	cin>>code;
	int i,j;
	for(i=0;i<=num-1;i++)
	{
	 	if(emp[i].code==code)
		{
			check=i;
		}

	}
	if(check!=-1)
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==check)
			{
				i++;
			}
			emp[j]=tempemp[i];
		}
		gotoXY(10,8);
		cout<<"Record deleted Successfully...!";
		getch();
		num--;
	}
	else{
            gotoXY(10,8);
            cout<<"Employee can not found....! ";
            getch();

		}
}

void search()
{
	//system("cls");
	borderNoDelay();
	int jobcode;
	bool found = false;
	gotoXY(10,4);
	cout<<"You can Search only through the ID of an Employee";
	gotoXY(10,6);
	cout<<"Enter ID Of the Employee : ";
	cin>>jobcode;
	for(int i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			gotoXY(6,8);
			cout<<"Name\tCode\tDesignation\tDepartment \tAge\tSalary "<<endl;
			gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			gotoXY(6,11);
			cout<<emp[i].name;
			gotoXY(19,11);
			cout<<emp[i].code;
			gotoXY(26,11);
			cout<<emp[i].designation;
			gotoXY(39,11);
			cout<<emp[i].department;
			gotoXY(55,11);
			//cout<<emp[i].exp;
			//gotoXY(47,11);
			cout<<emp[i].age;
			gotoXY(65,11);
			cout<<emp[i].grosspay;
			found = true;
		}
		//else
		//
	}
	if(!found)
	{
		gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}



void editmenu()
{
	//system("cls");
	borderNoDelay();
	gotoXY(28,4);
	printf("Edit An Entry");
	gotoXY(10,6);
	cout<<"What Do You Want To edit";
	gotoXY(12,8);
	cout<<"n ---------> Name ";
	gotoXY(12,9);
	cout<<"c ---------> Code ";
	gotoXY(12,10);
	cout<<"j--------->Designation";
	gotoXY(12,11);
	cout<<"d ---------> Department";
	gotoXY(12,12);
	cout<<"a ---------> Age";
	gotoXY(12,13);
	cout<<"s ---------> Salary";
	gotoXY(12,14);
	cout<<"q ---------> QUIT";
	gotoXY(10,17);
	cout<<"Enter Choice ---->>>  ";
}

void editname(int i)
{
	gotoXY(10,18);
	cout<<"Enter New Name----->  ";
	cin>>emp[i].name;
}

void editcode(int i)
{
	gotoXY(10,18);
	cout<<"Enter New Job Code----->  ";
	cin>>emp[i].code;
}
void editdesignation(int i)
{
    gotoXY(10,20);
    cout<<"Enter New Designation ----->";
    cin>>emp[i].designation;
}
void editdes(int i)
{
	gotoXY(10,18);
	cout<<"enter new department----->  ";
	cin>>emp[i].department;
}

/*void editexp(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Years of Experience";
	cin>>emp[i].exp;
}*/
void editage(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Age ";
	cin>>emp[i].age;
}

void editsalary(int i)
{
	int sal,PF,TAX,HRA,ESI,bonus,MedicalA,TransportA,DA,esi;
	gotoXY(10,18);
	cout<<"Enter new Salary ";
	cin>>sal;
	DA = 0.35 * sal;
	TAX =  0.04 * sal;
	PF = 0.12 * sal;
	esi=0.10*sal;
	HRA = 4000;
	bonus = 0.50*sal;
	MedicalA = 300;
	TransportA = 300;

	emp[i].salary = sal;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].ESI=esi;
	emp[i].HRA = HRA;
	emp[i].Bonus = bonus;
	emp[i].MedicalAllowance = MedicalA;
	emp[i].TransportAllowance = TransportA;

	emp[i].grosspay = (sal+bonus+MedicalA+TransportA+HRA+DA)-(PF+TAX+esi) ;
}

void edit()
{
	//system("cls");
	borderNoDelay();
	int jobcode;
	gotoXY(28,4);
	printf("Edit a Record");
	int i;
	char option;
	gotoXY(10,6);
	cout<<"Enter the jobcode To Edit : ";
	cin>>jobcode;
	editmenu();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{
					case 'n':
						editname(i);
						break;
					case 'c':
						editcode(i);
						break;
                    case 'j' :
                        editdesignation(i);
                        break;
					case 'd':
						editdes(i);
						break;
					case 'a':
						editage(i);
						break;
					case 's':
						editsalary(i);
						break;
				}
   				editmenu();
			}
		}
	}
}


void displayPayslip()
{
	system("cls");
	borderNoDelay();
	gotoXY(10,4);
	int code,i;
	cout<<"Enter Employee ID :";
	cin>>code;
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==code)
		{
			gotoXY(12,6);
			cout<<"Name : "<<emp[i].name;
			gotoXY(45,6);
			cout<<"Working days : "<<emp[i].workingdays<<" days";
			gotoXY(6,8);
			cout<<"Earnings :-";
			gotoXY(8,10);
			cout<<"Basic Pay : "<<emp[i].salary<<endl;
			gotoXY(8,12);
			cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
			gotoXY(8,14);
			cout<<"DA (35% of Basic):"<<emp[i].DA;
			gotoXY(8,16);
			cout<<"Bonus (5% of Basic): "<<emp[i].Bonus<<endl;
			gotoXY(8,18);
			cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
			gotoXY(8,20);
			cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
			gotoXY(8,22);
			cout<<"Overtime salary : "<<emp[i].OTS<<endl;
			gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			gotoXY(42,10);
			cout<<"PF (12% of Basic) : "<<emp[i].PF<<endl;
			gotoXY(42,12);
			cout<<"Tax (4% of Basic) : "<<emp[i].tax<<endl;
			gotoXY(42,14);
			cout<<"ESI (10% of Basic) :"<<emp[i].ESI;
			gotoXY(40,21);
			cout<<"------------------------------";
			gotoXY(42,22);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
			gotoXY(40,23);
			cout<<"------------------------------";
		}
	}
	getch();
}

void finduser()
{
     int ch;
     system("cls");
     loginFrame();
     gotoXY(20,9);
     cout<<"1---->Admin Login ";
     gotoXY(20,11);
     cout<<"2---->Employee Login ";
     gotoXY(20,13);
     cout<<"3---->Quit ";
     gotoXY(20,14);
     cin>>ch;
        switch(ch)
        {
            case 1: loginFrame();
                    login();
                    break;
            case 2: Emp_login();
                    break;
            case 3: exit(0);
                    break;
            default:cout<<"Enter Correct Choice \n";

        }

}

void Emp_login()
{
    system("cls");
    char usname[20],pwd[20];
    int i;
    char ch;
    borderNoDelay();
    gotoXY(12,10);
    cout<<"Enter the Username :";
    cin>>usname;
    gotoXY(12,12);
    cout<<"Enter the Password ";
    gotoXY(12,13);
    cout<<"(Enter your Name as password if your new login) : ";
    cin>>pwd;
    system("cls");
    for(i=0;i<=num-1;i++)
	{
		if(strcmp(emp[i].name,usname)==0 && strcmp(emp[i].pass,pwd)==0)
		{
		    borderNoDelay();
		    id=emp[i].code;
			gotoXY(12,6);
			cout<<"Logged In Successfully \n";
			gotoXY(12,8);
			cout<<"Do you want to change the password (press y/n) : ";
			cin>>ch;
			system("cls");
			if(ch=='y')
            {
                gotoXY(12,6);
                cout<<"Enter New Password: ";
                cin>>emp[i].pass;
                gotoXY(12,10);
                cout<<"Your Password Updated Successfully \n";
                saverecords();
                getch();
                Emp_login();
                return;
			}
			else{
                 EmpChoice();
                 return;
			}

		}
		/*else
        {
            cout<<"Please Give correct UserName and Password";
            getch();
        }*/
	}
	if(i==num)
    {
        //loginFrame();
        //gotoXY(20,14);
        //cout<<"Please Give correct UserName and Password";
        system("cls");
    	loginFrame1();
    	gotoXY(27,10);
		printf("Access Denied!!!\a");
    	gotoXY(21,12);
    	cout<<"Will be redirected in 3 Seconds...";
        gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b2";
        gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b1";
        gotoXY(56,12);
    	Cdelay(1000);
        //getch();
        system("cls");
        finduser();
    }
	//finduser();
    return;
}

void  listemp()
{
	//system("cls");
	borderNoDelay();
	gotoXY(20,4);
	printf("******** List of the Employees ********");
	gotoXY(6,6);
	cout<<"Name\tCode \tDesignation \tDepartment\t Age\tSalary "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<emp[i].name;
		gotoXY(18,j);
		cout<<emp[i].code;
		gotoXY(24,j);
		cout<<emp[i].designation;
		gotoXY(39,j);
		cout<<emp[i].department;
		gotoXY(58,j);
		cout<<emp[i].age;
		gotoXY(65,j);
		cout<<emp[i].grosspay;
	}
	getch();
    EmpChoice();
}

void EmpChoice()
{
	borderNoDelay();
	gotoXY(16,4);
	printf("*****  Payroll Management System 1.0 ***** ");
	gotoXY(12,6);
	cout<<"Press  1 ----> View Details";
	gotoXY(12,8);
	cout<<"Press  2 ----> Edit a Record.";
	gotoXY(12,10);
	cout<<"Press  3 ----> Generate Payslip";
	gotoXY(12,12);
	cout<<"Press  4 ----> Logout\n";
	int c;
	gotoXY(12,14);
	cout<<"Enter your Choice ";
	cin>>c;
	switch(c)
	{
        case 1:emp_details();
                break;
        case 2:editemp();
                break;
        case 3:emp_payslip();
				break;
        default:
                finduser();
	}
	EmpChoice();
	return;

}
void emp_details()
{
    system("cls");
    borderNoDelay();
	gotoXY(20,4);
	gotoXY(6,6);
    cout<<"Name\tCode \tDesignation \tDepartment\t Age\tSalary "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
	    if(emp[i].code==id)
        {
            gotoXY(6,j);
            cout<<emp[i].name;
            gotoXY(18,j);
            cout<<emp[i].code;
            gotoXY(24,j);
            cout<<emp[i].designation;
            gotoXY(39,j);
            cout<<emp[i].department;
            gotoXY(58,j);
            cout<<emp[i].age;
            gotoXY(65,j);
            cout<<emp[i].grosspay;
        }
	}
	getch();
}
void editempmenu()
{
    borderNoDelay();
	gotoXY(28,4);
	printf("Edit An Entry");
	gotoXY(10,6);
	cout<<"What Do You Want To edit";
	gotoXY(12,8);
	cout<<"n ---------> Name ";
	//gotoXY(12,9);
	//cout<<"c ---------> Code ";
	gotoXY(12,10);
	cout<<"j--------->Designation";
	gotoXY(12,12);
	cout<<"d ---------> Department";
	//gotoXY(12,12);
	//cout<<"e ---------> Experience ";
	gotoXY(12,14);
	cout<<"a ---------> Age";
	//gotoXY(12,14);
	//cout<<"s ---------> Salary";
	gotoXY(12,16);
	cout<<"q ---------> QUIT";
	gotoXY(10,17);
	cout<<"Enter Choice ---->>>  ";

}
void emp_payslip()
{
    system("cls");
	borderNoDelay();
	gotoXY(10,4);
	int i;
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==id)
		{
			gotoXY(12,6);
			cout<<"Name : "<<emp[i].name;
			gotoXY(45,6);
			cout<<"Working days : "<<emp[i].workingdays<<" days";
			gotoXY(6,8);
			cout<<"Earnings :-";
			gotoXY(8,10);
			cout<<"Basic Pay : "<<emp[i].salary<<endl;
			gotoXY(8,12);
			cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
			gotoXY(8,14);
			cout<<"DA (35% of Basic):"<<emp[i].DA;
			gotoXY(8,16);
			cout<<"Bonus (5% of Basic): "<<emp[i].Bonus<<endl;
			gotoXY(8,18);
			cout<<"Medical Alowance : "<<emp[i].MedicalAllowance<<endl;
			gotoXY(8,20);
			cout<<"Transport Allowance : "<<emp[i].TransportAllowance<<endl;
			gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			gotoXY(42,10);
			cout<<"PF (12% of Basic) : "<<emp[i].PF<<endl;
			gotoXY(42,12);
			cout<<"Tax (4% of Basic) : "<<emp[i].tax<<endl;
			gotoXY(42,14);
			cout<<"ESI (10% of Basic) :"<<emp[i].ESI;
			gotoXY(40,21);
			cout<<"------------------------------";
			gotoXY(42,22);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
			gotoXY(40,23);
			cout<<"------------------------------";
		}
	}
	getch();
}


void editemp()
{
    borderNoDelay();
	int jobcode;
	gotoXY(28,4);
	printf("Edit a Record");
	int i;
	char option;
	gotoXY(10,6);
	editempmenu();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==id)
		{
			while((option=cin.get())!='q')
			{
				switch(option)
				{
					case 'n':
						editname(i);
						break;
					//case 'c':
						//editcode(i);
						//break;
                    case 'j' :
                        editdesignation(i);
                        break;
					case 'd':
						editdes(i);
						break;
					case 'a':
						editage(i);
						break;
					//case 's':
						//editsalary(i);
						//break;
				}
   				editempmenu();
			}
		}
	}

}





int main()
{
	setWindowSize();
	border();
	intro();
	getrecords();
	loading();
	finduser();
	//loginFrame();
    //login();
    menu();
    getrecords();
    int option;
    if(emp[0].code==0 && isFilePresent())
    	num--;
	while(1)
	{
		cin>>option;
		switch(option)
		{
			case 5:
				list();
				break;
			case 1:
				Designations();
				break;
			case 3:
				deletes();
				break;
			case 2:
				edit();
				break;
			case 4:
				search();
				break;
			case 6:
				displayPayslip();
				break;
			case 7:
				saverecords();
				finduser();
		}
		menu();
	}


	return 0;
}

