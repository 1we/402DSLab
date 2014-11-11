#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node{
  int info;
  struct node *left;
  struct node *right;
  };
typedef struct node tree;
tree *root=NULL;
class BIN
{
  int num;
  tree *p,*prev,*temp;
  public:
  void insert();
  void inorder(tree*);
  void postorder(tree*);
  void preorder(tree*);
  void display();
};
void BIN::insert()
{
  p=new(tree);
  cout<<"\nenter number:\n";
  cin>>num;
  p->info=num;
  p->left=p->right=NULL;
  if(root==NULL){
    root=p;
    return;
  }
  temp=root;
  while(temp!=NULL){
  if(num>=temp->info){
  prev=temp;
  temp=temp->right;
  }
  else{
  prev=temp;
  temp=temp->left;
  }}
  if(num>=prev->info)
  prev->right=p;
  else
  prev->left=p;
}
void BIN::preorder(tree *temp)
{
  if(temp!=NULL){
  cout<<"\t"<<temp->info;
  preorder(temp->left);
  preorder(temp->right);
  }
}
void BIN::inorder(tree *temp)
{
  if(temp!=NULL){
  inorder(temp->left);
  cout<<"\t"<<temp->info;
  inorder(temp->right);
  }
}
void BIN::postorder(tree *temp)
  {
  if(temp!=NULL){
  postorder(temp->left);
  postorder(temp->right);
  cout<<"\t"<<temp->info;
  }
}
void BIN::display()
{
  if(root==NULL){
  cout<<"\n***enpty tree***\n";
  return;
  }
  cout<<"\n\nthe preorder display is:";
  preorder(root);
  cout<<"\n\nthe inorder display is:";
  inorder(root);
  cout<<"\n\nthe postorder display is:";
  postorder(root);
}
void main()
{
  BIN o;
  int ch=1;
  int count=0;
  clrscr();
  while(ch){
  cout<<"\n*****Menu*****\n";
  cout<<"1.insert in tree\n2.display\n3.quit\n";
  cout<<"enter your choice\n";
  cin>>ch;
  switch(ch){
  case 1:clrscr();
	 count++;
	 o.insert();
	 break;
  case 2:clrscr();
	 cout<<"the number of nodes in the BST is"<<count;
	 o.display();
	 break;
  case 3:exit(0);
  }
}
getch();
}
