#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node{
  int info;
  struct node *llink;
  struct node *rlink;
};
typedef struct node NODE;
NODE *first,*temp,*cur,*prev,*next;
void main()
{
int ch;
clrscr();
while(1){
  clrscr();
  printf(".....double link list.....");
  printf("\n1.insert front\n2.insert before\n3.delete all occurence\n4.display list\n5.exit\n");
  printf("enter your choice\n");
  scanf("%d",&ch);
  switch(ch){
     case 1:add_front();break;
     case 2:insert_before();break;
     case 3:del();break;
     case 4:display();break;
     case 5:exit(0);
     }
getch();
  }
}
add_front()
{
  temp=(NODE*)malloc(sizeof(NODE));
  printf("\nenter the item");
  scanf("%d",&temp->info);
  temp->llink=NULL;
  temp->rlink=NULL;
  if(first==NULL){
    first=temp;
    return;
  }
temp->rlink=first;
first->llink=temp;
first=temp;
}
display()
{
  if(first==NULL){
    printf("\nlist is empty");
    return;
  }
temp=first;
printf("\n.....list status.....\n");
while(temp!=NULL){
  printf("%d  ",temp->info);
  temp=temp->rlink;
  }
}
insert_before()
{
  int key;
  if(first==NULL){
  printf("\nlist is empty");
  return;
  }
printf("\nenter the key");
scanf("%d",&key);
if(first->info==key){
  add_front();
  return;
  }
cur=first;
while(cur!=NULL){
  if(cur->info==key){
    temp=(NODE*)malloc(sizeof(NODE));
    printf("\nenter item to be inserted");
    scanf("%d",&temp->info);
    prev=cur->llink;
    prev->rlink=temp;
    temp->llink=prev;
    temp->rlink=cur;
    cur->llink=temp;
    return;
    }
cur=cur->rlink;
}
printf("key not found");
}
del()
{
  int x,flag=0;
  if(first==NULL){
  printf("\nlist is empty");
  return;
  }
  printf("\nenter item to be deleted");
  scanf("%d",&x);
  cur=first;
  while(cur!=NULL){
  if(cur->info==x){
  flag=1;
  if(cur==first)
  first=first->rlink;
  prev=cur->llink;
  next=cur->rlink;
  prev->rlink=next;
  next->llink=prev;
  }
  cur=cur->rlink;
}
if(flag==1)
printf("\nitem %d deleted\n",x);
else
printf("\nitem %d not found\n",x);
}