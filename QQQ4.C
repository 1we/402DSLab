#include<stdio.h>
#include<conio.h>
#define maxsize 104
int q[maxsize];
int front=-1,rear=-1;
void main()
{
	int ch;
	while(1)
	{
		clrscr();
		puts("\n Quee operations\n");
		puts("1.add\n2.del\n3.display\n4.exit\nenter you choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add();
				break;
			case 2:del();
				break;
			case 3:display();
				break;
			default:return;
		}
	getch();
	}
}
add()
	{
	int x;
	if(rear==maxsize-1)
	{
	puts("\nhooo Quuu is full");
	return;
	}
	puts("enter element");
	scanf("%d",&x);
	q[++rear]=x;
	if(front==-1)
	front++;
	return;
}
del()
{
	if(front==-1)
	{
		puts("\nQU is enmpty");
		return;
	}
	printf("\nelements del from quee is %d\n",q[front]);
	front++;
	if(front>rear)front=rear=-1;
	return;
}
display()
{
	int i;
	printf("\n QU status......\n");
	if(front==-1)
	puts("\n Qu is empty");
	else
	for(i=front;i<=rear;i++)
	printf("%d\t",q[i]);
	return;
}