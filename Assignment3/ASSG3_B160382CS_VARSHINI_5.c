#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct node
{
 int data;
 struct node *next;
};

void delete(struct node **h,int position)
{
 //int i;
 struct node *temp=*h;
 struct node *prev;
 if(temp==NULL)
 {
  return;
 }
 if(position==1)
 {
  *h=temp->next;
  temp->next=NULL;
  return;
 }
 //for(i=1;i<position;i++)
   int i=1;
  while(i<position)
	i++;
  {
  prev=temp;
  temp=temp->next;
 }
 prev->next=temp->next;
}

void insert(struct node **h,int pos)
{
 struct node *last=*h;
 struct node *new_node=(struct node *)malloc(sizeof(struct node));
 new_node->data=pos;
 new_node->next=NULL;
 if(*h==NULL)
 {
 *h=new_node;
  return;
 }
 else
 {
 while(last->next!=NULL)
 {
  last=last->next;
 }
 last->next=new_node;
 }
 return;
}

void print(struct node *n)
{
 //while(n!=NULL)
  if(n!=NULL)
 {
  printf("%d ",n->data);
  n=n->next;
 }
}

int main()
{
 int r=0,position;
 char c='a';
struct node *h=NULL;
while(c!=10)
{
 scanf("%c",&c);
 if(c==45)
 {
  scanf("%c",&c);
  while(1)
  {
  if(c==32)
  {
   insert(&h,-1*r);
   r=0;
   break;
  }
  else if(c==10)
  {
   insert(&h,-1*r);
   break;
  }
  else
  {
   c=c-48;
   r=r*10+c;
  }
  scanf("%c",&c);
  }
 }
 else
 {
  while(1)
  {
   if(c==32)
   {
    insert(&h,r);
    r=0;
    break;
   }
   else if(c==10)
   {
    insert(&h,r);
    break;
   }
   else
   {
    c=c-48;
    r=r*10+c;
   }
  scanf("%c",&c);
  }
 } 
} 

scanf("%d",&position);
delete(&h,position);

print(h);
}


