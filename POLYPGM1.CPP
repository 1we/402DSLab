#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#include<string.h>
#define MALLOC(p,n,type)  \
p=(type*)malloc(n*sizeof(type));  \
if(p==NULL){  \
printf("insufficient memory");  \
exit(0);   \
}
struct node
{
  int coeff;
  int expon;
  struct node *link;
};
typedef struct node *NODE;
int compare(int exp1,int exp2)
{
if(exp1==exp2)
return 0;
else if(exp1>exp2)
return 1;
else
return 2;
}
void display(NODE head)
{
  NODE temp;
  if(head->link==head){
  printf("polynomial does not exist");
  return;
  }
  temp=head->link;
  while(temp!=head){
  if(temp->coeff<0)
  printf("%2dx^%2d",temp->coeff,temp->expon);
  else
  printf("+%2dx^%2d",temp->coeff,temp->expon);
  temp=temp->link;
  }
}
NODE attach(int coeff,int expon,NODE head)
{
  NODE temp,cur;
  MALLOC(temp,1,struct node);
  temp->coeff=coeff;
  temp->expon=expon;
  cur=head->link;
  while(cur->link!=head){
  cur=cur->link;
  }
  cur->link=temp;
  temp->link=head;
  return head;
}
NODE read_polynomial(NODE head)
{
  int i=1,coeff,expon;
  printf("enter the coefficient as -999 to end the polynomial\n");
  while(1){
  printf("enter the %d term\n",i++);
  printf("coeff=");
  scanf("%d",&coeff);
  if(coeff==-999)
  return head;
  printf("pow x=");
  scanf("%d",&expon);
  head=attach(coeff,expon,head);
  }
}
NODE poly_add(NODE head1,NODE head2,NODE head3)
{
  NODE a,b;
  int coeff;
  a=head1->link;
  b=head2->link;
  while(a!=head1  && b!=head2){
  switch(compare(a->expon,b->expon)){
  case 0 : coeff=a->coeff+b->coeff;
	   if(coeff!=0)head3=attach(coeff,a->expon,head3);
	   a=a->link;
	   b=b->link;
	   break;
  case 1 : head3=attach(a->coeff,a->expon,head3);
	   a=a->link;
	   break;
  default : head3=attach(b->coeff,b->expon,head3);
	    b=b->link;
  }
}
while(a!=head1){
head3=attach(b->coeff,b->expon,head3);
a=a->link;
}
while(b!=head2){
head3=attach(b->coeff,b->expon,head3);
b=b->link;
}
return head3;
}

void main()
{
  NODE head1,head2,head3;
  MALLOC(head1,1,struct node);
  MALLOC(head2,1,struct node);
  MALLOC(head3,1,struct node);
  head1->link=head1;
  head2->link=head2;
  head3->link=head3;
  printf("enter the first polynomial\n");
  head1=read_polynomial(head1);
  printf("enter the second polynomial\n");
  head2=read_polynomial(head2);
  head3=poly_add(head1,head2,head3);
  printf("polynomial 1:");
  display(head1);
  printf("\npolynomial 2:");
  display(head2);
  printf("\npolynomial 3:");
  display(head3);
  getch();
}