#include<iostream.h>
#include<conio.h>
#include<string.h>
class string
{
char name[11];
public:string()
{
	name[11]='\0';
}
string(char s[])
{
strcpy(name,s);
}
string(string &s)
{
strcpy(name,s.name);
}
friend string operator+(string s1,string s2);
friend ostream &operator <<(ostream &out,string &s);
};

ostream &operator<<(ostream &out,string &s)
{
out<<s.name<<endl;
return(out);
}
string operator +(string s1,string s2)
{
string temp(s1);
strcat(temp.name,s2.name);
return(temp);
}
void main()
{
string s1=("vtu");
string s2=("belgaum");
string s3=s1+s2;
cout<<s1<<s2<<s3;
getch();
}