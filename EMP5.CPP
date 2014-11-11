#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class EMPLOYEE{
	int Employee_Number,Basic_Salary,All_Allowances,IT,Net_Salary;
	char Employee_Name[20];
	
	public:
		void accept();
		void calc();
		void display();
};

void main()
{   
	int n;
	EMPLOYEE emp[20];
	cout<<"Enter Number Of Employees : ";
	cin>>n;
	for(int i=0 ; i < n; i++)
	{
		clrscr();
		cout<<"\nEnter Details for Emp : "<<i+1<<"\n";
		emp[i].accept();
	}

	cout<<"\n\nNumber\tName\tBasic\tIT\tNet\tAll Allowances\n\n";
	for(i=0;i<n;i++)
	{
		emp[i].display();
	}
	getch();
}
void EMPLOYEE::accept()
{
	cout<<"Number : ";
	cin>>Employee_Number;
	cout<<"Name : ";
	cin>>Employee_Name;
	cout<<"Basic : ";
	cin>>Basic_Salary;
	calc();
}
void EMPLOYEE::display()
{
	cout<<Employee_Number<<"\t"<<Employee_Name<<"\t"<<Basic_Salary;
	cout<<"\t"<<IT<<"\t"<<Net_Salary<<"\t"<<All_Allowances<<"\n";
}
void EMPLOYEE::calc()
{
	All_Allowances=1.23*Basic_Salary;
	IT=0.3*(Basic_Salary+All_Allowances);
	Net_Salary=Basic_Salary+All_Allowances-IT;
}

