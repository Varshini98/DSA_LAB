#include<stdio.h>
#include<stdlib.h>


#define SIZE 10000000


int *stack,top = -1;

void push(int value,int n){
   if(top == n-1)
      printf("OVERFLOW\n");
	else if(top==-1)
{
	stack=(int*)malloc(sizeof(int));
	top++;
	stack[top]=value;
}
   else{
      top++;
	stack=(int *)realloc(stack,(top+1)*sizeof(int));
      stack[top] = value;
   }
}
void pop(){
   if(top == -1)
      printf("Empty\n");
   else{
      printf("%d\n", stack[top]);
      top--;
   }
}
void display(){
   if(top == -1)
      printf("Empty\n");
   else{
      int i;
      
      for(i=top; i>=0; i--)
	 printf("%d ",stack[i]);
printf("\n");
   }
}
void main()
{
int n;
	scanf("%d",&n);
	char c;
	int i=0,value;
	while(i<1)
	{
	   scanf("%c",&c);
		{
		  if(c=='a')
		  {
		scanf("%d",&value);
		 push(value,n);	
		  }
		 if(c=='r')
		 {
			pop();
		 }
		 if(c=='p')
			display();
		 if(c=='s')
			exit(0);
		}
	}

	return;
}
	


