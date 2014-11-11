#include<iostream.h>
#include<conio.h>
#include<math.h>
class octal
{
	int x;
	public:
	octal()
	{
		x=0;
	}
	octal(int n);
	int operator+(int n);
	friend ostream &operator<<(ostream &,octal &);
};
ostream & operator<<(ostream & dout,octal & o)
{
dout<<o.x;
return dout;
}
int octal::operator +(int n)
{
	int a=x;
	int d=0,i=0;
	while(a/10!=0)
	{
		d=d+pow(8,i)*(a%10);
		a=a/10;
		i++;
	}
	d=d+pow(8,i)*a;
	int sum=n+d;
	return sum;
}
octal::octal(int n)
{
	int o=0,i=0;
	while(n>=8)
	{
	o=o+pow(10,i)*(n%8);
	n=n/8;
	i++;
}
o=o+pow(10,i)*n;
x=o;
}
void main()
{
	int n;
	clrscr();
	cout<<"\n\t enter decimal number to convert eevalenttooctal:";
	cin>>n;
	octal o(n);
	cout<<"\n oct enqvelant dec is:"<<n<<"is:"<<o;
	cout<<"\n enter a any num to add:";
	cin>>n;
	int x=o+n;
	cout<<"\n sumof dec"<<n<<"and octal"<<o<<"is:decimal"<<x;
	getch();
}