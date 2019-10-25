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
   int rank;
   struct node1* parent;
};

struct node2{
   int u,v;
   int wt;
};

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


void heapify(struct node2* arr,int n,int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l].wt > arr[largest].wt)
    {
	largest = l;
    }
    if(r < n && arr[r].wt > arr[largest].wt)
    {
        largest = r;
    }
    if(largest != i)
    {
        struct node2 temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
	heapify(arr,n,largest);
    }
}

void sort(struct node2* arr,int n)
{
    int i;
    for(i = n/2-1;i >= 0;i--)
    {
	heapify(arr,n,i);
    }
    for(i = n - 1;i>= 0;i--)
    {
	struct node2 temp = arr[0];
	arr[0] = arr[i];
	arr[i] = temp;
	heapify(arr,i,0);
    }
}

void make_set(struct node1* arr,int i)
{
    arr[i].data = i;
    arr[i].parent = &arr[i];
    arr[i].rank = 0;
}

struct node1* find(struct node1* arr,int x)
{
    if(arr[x].parent == NULL)
    {
        printf("NOT FOUND\n");
        return NULL;
    }
    else
    {
        struct node1* temp = &arr[x];
        if(temp->parent != temp)
        {
            int c = (*(temp->parent)).data;
            temp->parent = find(arr,c);
        }
        return temp->parent;
    }
}

void link(struct node1* i,struct node1* j)
{
    if(i->rank >= j->rank)
    {
        j->parent = i;

        if(i->rank == j->rank)
        {
            i->rank = i->rank + 1;
        }
    }
    else
    {
        i->parent = j;
    }
    return;
}

void union_edges(struct node1*arr,int x,int y)
{
    struct node1 *i = find(arr,x),*j = find(arr,y);
    if(i == j)
    {
        return;
    }
    if(i != NULL && j != NULL)
    {
        link(i,j);
    }
}

void kruskal(int n,struct node2* wt_arr,int k)
{
    int i;
    struct node1* arr = malloc(n*sizeof(struct node1));
    for(i = 0;i < n;i++)
    {
	make_set(arr,i);
    }
    sort(wt_arr,k);
/*    for(i = 0;i < k;i++)
    {
	printf("%d ",wt_arr[i].wt);
    }
    printf("\n");*/
    for(i = 0;i < k;i += 2)
    {
	int u = wt_arr[i].u;
	int v = wt_arr[i].v;
	if(find(arr,u) != find(arr,v))
	{
	    sum = sum + wt_arr[i].wt;
	    union_edges(arr,u,v);
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
    struct node2* wt_arr = malloc(k * sizeof(struct node2));
    int j = 0;
    for(i = 0;i < n;i++)
    {
	struct node* t = adj[i];
	while(t != NULL)
	{
	    wt_arr[j].u = i;
	    wt_arr[j].v = t->data;
	    wt_arr[j].wt = t->wt;
	    j++;
	    t = t->next;
	}	
    }
/*    for(i = 0;i < k;i++)
    {
	printf("%d ",wt_arr[i].wt);
    } 
    return 0;*/
    kruskal(n,wt_arr,k);
    printf("%d\n",sum);
}
