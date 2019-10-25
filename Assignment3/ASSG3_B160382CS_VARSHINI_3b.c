#include<stdio.h>


struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

void main()
{
	int n;	
	scanf("%d",n);
	char c;
	int i=0,value;
	while(i<1)
	{
	   scanf("%c",&c);
		{
		  if(c=='a')
		  {
		scanf("%d",&value);
		 push(value);	
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


void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   
}
void pop()
{
   if(top == NULL)
      printf("EMPTY\n");
   else{
      struct Node *temp = top;
      printf("%d\n", temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
   if(top == NULL)
      printf("\nEMPTY\n");
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
	 printf("%d ",temp->data);
	 temp = temp -> next;
      }
      printf("%d ",temp->data);
   }
printf("\n");
}    
    
