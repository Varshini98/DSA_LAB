#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int n;
int a[1000][1000];

void create_graph()
{
int c,m,o,d,w;
scanf("%d",&n);
scanf("%d",&m);

for(c=1;c<=m;c++)
  {scanf("%d %d %d",&o,&d,&w);
   if((o==-1)&&(d==-1))
     break;
   if(o>n||d>n||o<0)
     {printf("invalid\n");
      c--;
     }
   else
      a[o][d]=w;
   }
}

/*void dijkstra(int s)
{
int b[n][n],d[n],p[n];
int v[n],c,md,nextnode,i,j;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(a[i][j]==0)
           b[i][j]=100000;
        else
           b[i][j]=a[i][j];

for(i=0;i<n;i++)
{d[i]=b[s][i];
 p[i]=s;
 v[i]=0;
}
d[s]=0;
v[s]=1;
c=1;

while(c<n-1)
   {
     md=100000;
      for(i=0;i<n;i++)
         if(d[i]<md&&!v[i])
           {md=d[i];
            nextnode=i;
           }
   v[nextnode]=1;
   for(i=0;i<n;i++)
      if(!v[i])
        if(md+b[nextnode][i]<d[i])
          {
            d[i]=md+b[nextnode][i];
             p[i]=nextnode;
          }
   c++;
  }
for(i=0;i<n;i++)
  
     
      printf("%d %d\n",i,d[i]);
      

}*/

int main()
{int s;

//int a[n][n];
create_graph();
scanf("%d",&s);
//dijkstra(s);
int b[n][n],d[n],p[n];
int v[n],c,md,nextnode,i,j;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(a[i][j]==0)
           b[i][j]=100000;
        else
           b[i][j]=a[i][j];

for(i=0;i<n;i++)
{d[i]=b[s][i];
 p[i]=s;
 v[i]=0;
}
d[s]=0;
v[s]=1;
c=1;

while(c<n-1)
   {
     md=100000;
      for(i=0;i<n;i++)
         if(d[i]<md&&!v[i])
           {md=d[i];
            nextnode=i;
           }
   v[nextnode]=1;
   for(i=0;i<n;i++)
      if(!v[i])
        if(md+b[nextnode][i]<d[i])
          {
            d[i]=md+b[nextnode][i];
             p[i]=nextnode;
          }
   c++;
  }
for(i=0;i<n;i++)
  
   printf("%d %d\n",i,d[i]);

return 0;
}


