#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class stack
{
int items[100],top,size;
public:
stack(int n)
{
top=-1;
size=n;
}
friend stack operator+(stack,int);
friend stack operator--(stack);
friend ostream&operator<<(ostream&,stack);
};
stack operator+(stack s,int num)
{
if(s.top==s.size-1)
cout<<"stack overflow"<<endl;
else
s.items[++s.top]=num;
return s;
}
stack operator--(stack s)
{
if(s.top==-1)
cout<<"stack empty"<<endl;
else
cout<<"\n the deleted element is:"<<s.items[s.top--];
return s;
}
ostream & operator<<(ostream&print,stack s)
{
if(s.top==-1)
print<<"\n the stack is empty";
else
{
print<<"\n the element in stack are:\n";
for(int i=s.top;i>=0;i--)
print<<s.items[i]<<endl;
}
return print;
}
void main()
{
int num,ch=1,n;
cout<<"\n enter the size of stack:";
cin>>n;
stack s(n);
clrscr();
while(ch)
{
cout<<"\n\n\n******stack******\n";
cout<<"\n-------menu------\n";
cout<<"\n enter 1 to pushed";
cout<<"\n enter 2 to popped";
cout<<"\n enter 3 to display";
cout<<"\n enter 4 to exit";
cout<<"\n enter your choice:";
cin>>ch;
switch(ch)
{
case 1:clrscr();
cout<<"\n enter the number to be inserted:";
cin>>num;
s=s+num;
cout<<s;
break;
case 2:clrscr();
s=--s;
cout<<s;
break;
case 3:clrscr();
cout<<s;
break;
case 4:exit(0);
default:cout<<"\n invalid choice";
}}
getch();
}