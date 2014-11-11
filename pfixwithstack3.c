#include<stdio.h>
#include<conio.h>
#include<math.h>

int stack[20],top=-1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return(stack[top--]);
}
void main()
{
	char s[20];
	int x,i,y;
	clrscr();
	printf("\n evelation of post fix exp\n");
	printf("\n enter a postfix expression");
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(isdigit(s[i]))
		push(s[i]-'0');
		else
		{
			y=pop();
			x=pop();
			switch(s[i])
		{
			case'+':push(x+y);
			break;
			case'-':push(x+y);
			break;
			case'*':push(x*y);
			break;
			case'/':push(x/y);
			break;
			case'^':
			case'$':push(pow(x,y));
			break;
		}
	}
}
printf("\n resulr is: %d",pop());
getch();
}