#include<stdio.h>
#include<stdlib.h>
struct node
{
	long int info;
	struct node *next;
};
struct node *front=NULL;
struct node* rear=NULL;

//enqueue......
void enqueue(int p)
{
	struct node* t=(struct node*)malloc(sizeof(struct node));
	t->info=p;
	t->next=NULL;
	if(front==NULL &&rear==NULL)
	{
		front=rear=t;
		return;
	}
	rear->next=t;
	rear=t;
	
}
//dequeue
int dequeue()
{
	if(front==NULL)
	{
		rear=NULL;
		return -1;
	}
	printf("%ld\n",front->info);
	front=front->next;
}
void print_queue()
{
	struct node* t=front;
	if(t==NULL)
		printf("%d",-1);
	while(t!=NULL)
	{
		printf("%ld ",t->info);
		t=t->next;
	}
printf("\n");
} 
int main()
{
	char c,t;
	long int n;
	int i=0;
		while(i<1)
	{
		scanf("%c",&c);
		{
			if(c=='e')
		     {
			  scanf("%ld",&n);
			  enqueue(n);
			}
		    if(c=='d')
			{
			 t= dequeue();
			 if(t==-1)
				 printf("%d\n",-1);
				
			}
		    if(c=='p')
			  print_queue();
		    if(c=='s')
			  exit(0);
		}
	}
	return;
}
		
	
