#include<stdio.h>
#include<stdlib.h>

long int count;
struct node
{
  	long int data;
	struct node *left,*right;
}*bst=NULL,*ptr,*pt,*lastpar,*par,*q,*p;

struct node* makenode(long int d)
{       pt=(struct node *)malloc(sizeof(struct node));
	pt->data=d;
	pt->left=NULL;
	pt->right=NULL;
	return pt;
}

struct node* insert(struct node *b,struct node *p)
{
	if(b==NULL)
	{
		return p;
	}
     	
	else if((b->data)<(p->data))
	{ 
		b->right=insert(b->right,p);
		return b;			
	}
	else
	{
		b->left=insert(b->left,p);
		return b;
	}
}
	
void search(struct node *b,long int d)
{
	if(b==NULL)
	{
		printf("NOT FOUND\n");
		return;
	}	
	if((b->data)==d)
	{
		printf("FOUND\n");
		return;
	}
	if((b->data)<d)
	{ 
		search(b->right,d);			
	}
	else
	{   
		search(b->left,d);
	}
}

	
int sear(struct node *b,long int d)
{
	if(b==NULL)
	{
		return 0;
	}	
	if((b->data)==d)
        {
		return 1;
	}
	if((b->data)<d)
	{ 
		sear(b->right,d);			
	}
	else
	{   
		sear(b->left,d);
	}
}	
void minimum(struct node* bt)
{
	if(bt==NULL)
	{
		printf("NIL\n");
 		return;
	}
 	else 
	{
		if((bt->left)==NULL)
			{
			printf("%ld\n",bt->data);
			return;
			}
		else
			minimum(bt->left);
	}
}
long int mini(struct node* bt)
{
 	 
		if((bt->left)==NULL)
			{
			return(bt->data);
		
			}
		else
			mini(bt->left);
	
}
void maximum(struct node* bt)
{
	if(bt==NULL)
	{
		printf("NIL\n");
 		return;
	}
 	else 
	{
		if((bt->right)==NULL)
			{
			printf("%ld\n",bt->data);
			return;
			}
		else
			maximum(bt->right);
	}
}
long int maxi(struct node* bt)
{
		if((bt->right)==NULL)
			{
			return(bt->data);
			}
		else
			maxi(bt->right);
	
}
struct node* root(struct node *b,int d)
{       
	if((b->data)==d)
        {
		return b;
	}
	if((b->data)<d)
	{ 
		root(b->right,d);			
	}
	else
	{   
		root(b->left,d);
	}  
}

void pred(struct node *bt,int d)
{
        ptr=root(bt,d);	
	if((ptr->left)!=NULL)
        {
		maximum(ptr->left);
		return;
	}
	else
	{
		lastpar=NULL;
		par=bt;
		if((par->data)<d)
		{
			lastpar=par;
			q=par->right;
		}
		else
			q=par->left;
		while(q->data!=d)
                {
			if(d<=q->data)
			{
				par=q;
				q=q->left;		
			}
			else
			{
				lastpar=q;
				par=q;
				q=q->right;
			}
                }
 	if(lastpar==NULL)
		printf("NIL\n");
	else
		printf("%ld\n",lastpar->data);
	}

}

void succ(struct node *bt,int d)
{
        ptr=root(bt,d);	
	if((ptr->right)!=NULL)
        {
		minimum(ptr->right);
		return;
	}
	else
	{
		lastpar=NULL;
		par=bt;
		if((par->data)>d)
		{
			lastpar=par;
			q=par->left;
		}
		else
			q=par->right;
		while(q->data!=d)
                {
			if(d<=q->data)
			{
				lastpar=q;
				par=q;
				q=q->left;		
			}
			else
			{
				par=q;
				q=q->right;
			}
                }
 	if(lastpar==NULL)
		printf("NIL\n");
	else
		printf("%ld\n",lastpar->data);
	}

}

struct node* delete(struct node *b,struct node* p)
{
       // p=root(bst,d);
	if(b->data==p->data)
	{
		if(b->right==NULL)		
			return (b->left);
		else if(b->left==NULL)
			return (b->right);
		else
		{
			q=b->right;
			if(q->left==NULL)
			{
               			ptr=b->left;
				q->left=ptr;
				return q;
			}
			else
			{
				ptr=q->left;
				while((ptr->left)!=NULL)
				{
					q=ptr;
					ptr=ptr->left;
				}
				ptr->left=p->left;
				q->left=ptr->right;
			ptr->right=b->right;	
			return ptr;				
			}
 			
		}
					
	}
	else
	{
		if((p->data)<(b->data))
			{
			b->left=delete(b->left,p);
			return b;
			}
		else
			{
			b->right=delete(b->right,p);
			return b;
			}
	}

}
void inorder(struct node* b)
{
	if(b!=NULL)
	{
		inorder(b->left);
		printf("%ld ",b->data);
		inorder(b->right);
	}
}
void preorder(struct node* b)
{
	if(b!=NULL)
	{
		
		printf("%ld ",b->data);
		preorder(b->left);
		preorder(b->right);
	}
}
void postorder(struct node* b)
{
	if(b!=NULL)
	{
		postorder(b->left);
		postorder(b->right);
		printf("%ld ",b->data);
		
	}
}
void main()
{
	long int d;
	char s[4],temp;
	int i,k;
	label:
	for(i=0;i<5;i++)
		scanf("%c",&s[i]);
	
	switch(s[0])
	{
		case 's':switch(s[1])
			 {
				case 't':
  			    		 return;
			 		 exit(0);
				case 'r':
					 scanf("%ld%c",&d,&temp);
					 search(bst,d);
			 		 goto loop;
				case 'u':
					 scanf("%ld%c",&d,&temp);
					 k=sear(bst,d);
			 		 if(k==0)
			 		 {
						printf("NOT FOUND\n");
					 goto loop;				
		  			 }
			 		 else if(d==maxi(bst))
					 {
						printf("NIL\n");
						goto loop;
					 }
					 else
			 		 {
						succ(bst,d);
						goto loop;
			 		 }
	
                          }
		case 'm':switch(s[1])
			 {
				case 'i':
  			    		 minimum(bst);
					 goto loop;
				case 'a':
					 maximum(bst);
			 		 goto loop;	
                         }
		case 'i':switch(s[2])
			 {
			 case 's':
			 scanf("%ld%c",&d,&temp);
			 ptr=makenode(d);	
			 bst=insert(bst,ptr);
			 goto loop;
			
			 case 'o':
			 inorder(bst);
			 printf("\n");
			 goto loop;
			 }
		case 'd':
			 scanf("%ld%c",&d,&temp);
			 p=root(bst,d);
			 bst=delete(bst,p);
			 goto loop;
		case 'p':
			 switch(s[3])
			 {
			 case 'd':
			 {
			 scanf("%ld%c",&d,&temp);
			 k=sear(bst,d);
			 if(k==0)
			 {
				printf("NOT FOUND\n");
				goto loop;				
			 }
			 else if(d==mini(bst))
			 {
				printf("NIL\n");
				goto loop;
			 }
			 else
			 {
				pred(bst,d);
				goto loop;
			 }
			 }
			 case 'r':
			 {
                         preorder(bst);
			 printf("\n");
			 goto loop;
			 }
			 case 't':
			 {
			 postorder(bst);
			 printf("\n");
			 goto loop;
			 }
			 }						
	loop:
	goto label;
	}
return;
}

