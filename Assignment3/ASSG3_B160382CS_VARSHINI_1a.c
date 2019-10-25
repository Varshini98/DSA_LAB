#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int front=-1;
int rear=-1;
int n;
long int *queue;
int enqueue(int p)
{
	if(rear==n)
		return (-2);
	else
	{
		if(front==-1)
			front++;
		rear++;
		queue[rear]=p;
		return;
	}
}
int dequeue()
{
	if(front==-1||front==rear+1)
	{
		front=-1;
		rear=-1;
		return -1;
	}
	printf("%ld\n",queue[front]);
	front++;
	}
void print()
{
	if(front==-1||front==rear+1)
	{
		printf("%d",-1);
		return;
	}
	int i=front;
	while(i<=rear)
	{
		printf("%ld ",queue[i]);
		i++;
	}
printf("\n");
}
int main()
{
	scanf("%d",&n);
	queue=(long int *)malloc(n*sizeof(long int));
	char ch,t;
	int k;
	int i=0;
	while(i<1)
	{
	   scanf("%c",&ch);
		{
		  if(ch=='e')
		  {
			scanf("%d",&k);
			t=enqueue(k);
			if(t==-2)
			printf("%d\n",t);
		  }
		 if(ch=='d')
		 {
			t=dequeue();
			if(t==-1)
			printf("%d\n",t);
		 }
		 if(ch=='p')
			print();
		 if(ch=='s')
			exit(0);
		}
	}
	return;
}
	
