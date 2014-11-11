#include<stdio.h>
#include<conio.h>
#define mrow 20
#define mcol 20
#define srow 50
void main()
{
int mat[mrow][mcol],sparse[srow][3];
int i,j,nzero=0,mr,mc,sr,s,elem;
clrscr();
printf("enter the number of rows\n");
scanf("%d",&mr);
printf("enter the number of coloumns\n");
scanf("%d",&mc);
printf("enter the matrix\n");
for(i=1;i<=mr;i++)
for(j=1;j<=mc;j++)
{
scanf("%d",&mat[i][j]);
if(mat[i][j]!=0)
nzero++;
}
sr=nzero+1;
sparse[1][1]=mr;
sparse[1][2]=mc;
sparse[1][3]=nzero;
s=2;
for(i=1;i<=mr;i++)
for(j=1;j<=mc;j++)
if(mat[i][j]!=0)
{
sparse[s][1]=i;
sparse[s][2]=j;
sparse[s][3]=mat[i][j];
s++;
}
printf("sparse matrix is:\n");
for(i=1;i<s;i++)
{
for(j=1;j<=3;j++)
printf("%5d",sparse[i][j]);
printf("\n");
}
printf("enter the element to be searched\n");
scanf("%d",&elem);
for(i=2;i<=sr;i++)
if(sparse[i][3]==elem)
{
printf("element found at(row,col):(%d,%d)",sparse[i][1],sparse[i][2]);
}
else
printf("element not found\n");
getch();
}
