#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct heap
{
 int data;
 int priority;
 struct heap *next;
}*rear,*front;

struct heap *insert(struct heap **head,int pp,int qq);
struct heap *extract_min(struct heap **head);
struct heap *get_min(struct heap **head);


int main()
{
 	char ch;
 	scanf("%c",&ch);
 	struct heap *head=NULL;
 	while(ch!='s')
 	{
 	 if(ch=='a')
 	 {
 	  int p,q;
 	  scanf("%d %d",&p,&q);
 	  insert(&head,p,q);
 	 }
 	 if(ch=='e')
 	 {
 	  extract_min(&head);
 	 }
 	 if(ch=='g')
 	 {
 	  get_min(&head);
 	 }
	  //else
	  //printf("Invalid character");
 	 scanf("%c",&ch);
 	}
}	

struct heap *createheap(int num,int priority)
{
 	struct heap *heap=(struct heap *)malloc(sizeof(struct heap));
 	heap->data=num;
 	heap->priority=priority;
 	heap->next=NULL;
 	return(heap);
}

struct heap *insert(struct heap **head,int pp,int qq)
{
 	struct heap *heap=createheap(pp,qq);
 	struct heap *temp=*head;
 	struct heap *prev;
 	if(temp==NULL)
 {
 	 *head=heap;
  
 }
 else if(temp!=NULL && qq<temp->priority)
 {
 	 heap->next=temp;
 	 *head=heap;
  
 }
 else if(temp!=NULL && qq>temp->priority)
 {
  while(temp!=NULL && qq>temp->priority)
  {
  prev=temp;
  temp=temp->next;
  }
  prev->next=heap;
  heap->next=temp;
 }

}

//deleting
struct heap *extract_min(struct heap **head)
{
 	struct heap *front=*head;
 if(front==NULL)
 {
	printf("EMPTY\n");}
 else
 {
	 printf("%d(%d)\n",front->data,front->priority);
	 front=front->next;
	 *head=front;}
}

//insert
struct heap *get_min(struct heap **head)
{
	 struct heap *rear=*head;
 if(rear==NULL)
 {
	printf("EMPTY\n");
}
 else
 {
	 printf("%d(%d)\n",rear->data,rear->priority);
}
}

/* Dequeing the queue 
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}*/
  
