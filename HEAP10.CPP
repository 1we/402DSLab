#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int insert_heap(int item,int a[],int n)
{
int c,p;
if(n==MAX_SIZE)
{
printf("heap is full\n");
return n;
}
c=n;
p=(c-1)/2;
while(c!=0&&item>a[p])
{
a[c]=a[p];
c=p;
p=(c-1)/2;
}
a[c]=item;
return n+1;
}
void display(int a[],int n)
{
int i;
if(n==0)
{printf("heap is empty\n");
return;
}
printf("the array elements are\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
}
void main()
{
int a[MAX_SIZE];
int n=0;
int choice,item;
clrscr();
for(;;)
{
printf("1.insert   2.display  3.exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("enter the item to be inserted\n");
	scanf("%d",&item);
	n=insert_heap(item,a,n);
	break;
case 2: display(a,n);
	break;
	default:exit(0);
}
}
}