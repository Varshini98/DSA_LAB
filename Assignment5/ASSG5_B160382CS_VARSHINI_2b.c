#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

struct node{
   int data;
   int wt;
   struct node* next;
} *adj[1000];

struct node1{
   int data;
   int key;
   struct node1* next;
} *pq;
int sum = 0;

struct node* insert(struct node* head,int key)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = key;
    new->next = NULL;
    if(head == NULL)
    {
	head = new;
    }
    else
    {
	struct node* temp = head;
	while(temp->next != NULL)
	{
	   temp = temp->next;
	}
	temp->next = new;
    }
    return head;
}

struct node1* insert_queue(int i,int key)
{
    struct node1* new = malloc(sizeof(struct node1));
    new->data = i;
    new->key = key;
    new->next = NULL;
    if(pq == NULL)
    {
	pq = new;
	return pq;
    }
    else if(pq->key > key)
    {
	new->next = pq;
	pq = new;
	return pq;
    }
    else
    {
	struct node1* temp = pq,*prev;
	while(temp != NULL && temp->key <= key)
	{
	    prev = temp;
	    temp = temp->next;
	}
	prev->next = new;
	new->next = temp;
	return pq;
    }
}

int extract_min()
{
    int k = pq->data;
    pq = pq->next;
    return k;
}

int check(int v)
{
    struct node1* t = pq;
    while(t != NULL)
    {
	if(t->data == v)
	{
	    return 1;
	}
	t = t->next;
    }
    return 0;
}

int key(int v)
{
    struct node1* t = pq;
    while(t != NULL)
    {
	if(t->data == v)
	{
	    return t->key;
	}
	t = t->next;
    }
    return -1;
}

struct node1* change_key(int v,int new_key)
{
    struct node1* temp = pq,*prev;
    if(temp->data == v)
    {
	pq = pq->next;
    }
    else
    {
        while(temp != NULL && temp->data != v)
        {
	    prev = temp;
	    temp = temp->next;
        }
        prev->next = temp->next;
    }
    pq = insert_queue(v,new_key);
    return pq;
}

void prims(int n)
{
    int i;
    for(i = 1;i < n;i++)
    {
	pq = insert_queue(i,INT_MAX);
    }
    pq = insert_queue(0,0);
    while(pq != NULL)
    {
/*	struct node1* r = pq;
	while(r != NULL)
	{
	    printf("%d-%d ",r->data,r->key);
	    r = r->next;
	}
     	printf("\n");
*/
	sum = sum + pq->key;
	int u = extract_min();
	struct node* t = adj[u];
	while(t != NULL)
	{
	    int v = t->data;
	    if(check(v) && t->wt < key(v))
	    {
		pq = change_key(v,t->wt);
	    }
	    t = t->next;
	}
    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int num = 0,k=0;
    char ch;
    pq = NULL;
    scanf("%c",&ch);
    for(i = 0;i < n;i++)
    {
	char s[100];
	scanf("%c",&ch);
	int j = 0,p = 0;
	adj[i] = NULL;
	while(ch != '\n')
	{
	    s[p] = ch;
	    p++;  
	    scanf("%c",&ch);
	}
	s[p] = '\0';
	if(p == 0 && s[p] == '\0')
	{
	    continue;
	}
	j = 0;
	while(1)
	{
	    if(s[j] == ' ' || s[j] == '\0')
	    {
		k++;
		adj[i] = insert(adj[i],num);
		num = 0;
		if(s[j] == '\0')
		break;
 	    }
	    else
	    {
		num = num * 10 + (s[j] - 48);
	    }
	    j++;
	}
    }
    for(i = 0;i < n;i++)
    {
        char s[100];
        scanf("%c",&ch);
        int j = 0,k = 0;
        while(ch != '\n')
        {
            s[k] = ch;
            k++;
            scanf("%c",&ch);
        }
        s[k] = '\0';
        if(k == 0 && s[k] == '\0')
        {
            continue;
        }
        j = 0;
	struct node* t = adj[i];
        while(1)
        {
            if(s[j] == ' ' || s[j] == '\0')
            {
		t->wt = num;
		t = t->next;
                num = 0;
                if(s[j] == '\0')
                break;
            }
            else
            {
                num = num * 10 + (s[j] - 48);
            }
            j++;
        }
    }
/*    for(i = 0;i < n;i++)
    {
	struct node* t = adj[i];
	while(t != NULL)
	{
	    printf("%d ",t->wt);
	    t = t->next;
	}
	printf("\n");
    }*/
    prims(n);
    printf("%d\n",sum);
}
