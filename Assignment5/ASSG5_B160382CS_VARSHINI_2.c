#include<stdio.h>
#include<stdlib.h>

int n;
int a[10000][10000];
int s[10000];

int q[10000];
int b[10000];
int f=-1,r=-1;
int bfs(int );

int enqueue(int vertex)
{if(r==99)
   printf("overflow\n");
  else
   {
      if(f==-1)
         f=0;
         r=r+1;
         q[r]=vertex;
   }
return 0;
}

int emptyq()
{
if(f==-1||f>r)
  return 1;
else
return 0;
}

int dequeue()
{int  d;
if(f==-1||f>r)
 {printf("underflow\n");
  exit(1);
 }
d=q[f];
f=f+1;
return d;
}

void create_graph()
{
int c,m,o,d;
scanf("%d %d",&n,&m);

for(c=1;c<=m;c++)
  {scanf("%d %d",&o,&d);
   if((o==-1)&&(d==-1))
     break;
   if(o>n||d>n||o<0)
     {printf("invalid\n");
      c--;
     }
   else
      a[o][d]=1;
   }
}



int bf_traversal(int v)
{
 int i;
 for(i=0;i<n;i++)
    s[i]=1;
 
 bfs(v);
return 0;
}

void dfs(int i)
{
int j;
printf("%d ",i);
b[i]=1;
for(j=0;j<n;j++)
  if(!b[j]&&a[i][j]==1)
     dfs(j);
}


int main()
{int i,v;
create_graph();
scanf("%d",&v);
 bf_traversal(v);

 for(i=0;i<n;i++)
     b[i]=0;
 dfs(v);
return 0;
}

int bfs(int v)
{
int i;
enqueue(v);
s[v]=2;
while(!emptyq())
     {
       v=dequeue();
       printf("%d ",v);
       s[v]=3;
        for(i=0;i<n;i++)
        {
          if(a[v][i]==1&&s[i]==1)
           {
             enqueue(i);
             s[i]=2;
           }
         }
       }
  printf("\n");
return 0;
}

