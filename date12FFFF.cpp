#include<iostream.h>
#include<conio.h>

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{
	int dd,mm,yy;
	public:
	void read();
	void operator +(int n);
	int operator -(date d2);
	firend ostream & operator <<(ostream & cout,date d);
};
void date::read()
{
	cin>>dd>>mm>>yy;
}
void date::operator+(int n)
{
int d,i;
for(i=0;i<n;i++)
{
d=days[mm];
if(mm==2 && yy%4==0)
d=29;
dd=dd+1;
if(dd>d)
{
	dd=1;
	mm=mm+1;
	if(mm>12)
	{	mm=1;
	yy=yy+1;
	}
}
}
}
int date::operator-(date d2)
{
	int cnt=0;
	while(1)
	{
		if(dd=d2.dd&&mm==d2.mm&&yy==d2.yy)
		break;
		d2+1;
		cnt++;
	}
	return cnt;
}
ostream & operator<<(ostream & count.date d)
{
	count<<d.dd<<"-"<<d.mm<<"-"<<d.yy;
	return count;
}
void main()
{
	date d1,d2;
	int n,d;
	clrscr();
	cout<<"enter date 1:";
	d1.read();
	cout<<d1;
	cout<<"enter date 2:";
	d2.read();
	cout<<d2;
	d=d1-d2;
	cout<<"\n no of days is:"<<d;
	cout<<"enter the nos dats to add:";
	cin>>n;
	d1+n;
	cout<<d1;
	getch();
}