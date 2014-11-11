#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct NOD
{
  int info;
  struct NOD *next;
};
typedef struct NOD node;
class linklist
{
  node *f;
  public:
  linklist()
  {
  f=NULL;
  }
  void insert(int);
  void del();
  void disp();
};
void linklist::insert(int num)
   {
   node *p=new node;
   p->info=num;
   p->next=f;
   f=p;
   }
void linklist::del()
{
  clrscr();
  node *temp=f;
  if(f==NULL)
  cout<<"\nthe list is empty";
  else
  {
  cout<<"\nthe deleted element is:"<<f->info;
  f=f->next;
  delete temp;
  cout<<"\ndeletion successful";
  }
return;
}
void linklist::disp()
{
  node *temp=f;
  if(f==NULL)
  cout<<"\nlist is empty";
  else
  {
  cout<<"\nthe elements in list are:";
  while(temp!=NULL){
  cout<<" "<<temp->info;
  temp=temp->next;
  }
}
}
void main()
{
  int num,ch=1;
  linklist ob;
  clrscr();
  while(ch)
  {
  cout<<"\n\n\n*****linked list*****\n"
  <<"\n-----menu-----"
  <<"\nenter 1 to insert"
  <<"\nenter 2 to delete"
  <<"\nenter 3 to display"
  <<"\nenter 4 to exit"
  <<"\nenter your choice:";
  cin>>ch;
  switch(ch)
  {
  case 1 : clrscr();
	   cout<<"\nenter the number to be inserted";
	   cin>>num;
	   ob.insert(num);
	   ob.disp();
	   break;
  case 2 : clrscr();
	   ob.del();
	   ob.disp();
	   break;
 case 3 : clrscr();
	  ob.disp();
	  break;
 case 4 : exit(0);
 default : cout<<"\ninvalid choice";
 }
 }
 getch();
 }
