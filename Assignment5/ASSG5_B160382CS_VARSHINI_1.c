#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int m,n,count=0;
int a[10000][10000];
void search(int,int);
int main() 
{  
 int i,j,max=0,temp;
 scanf("%d",&m);
 scanf("%d",&n);
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   if(a[i][j]==1)
   {
    count=0;
    search(i,j);
    if(max<count)
      max=count;
   }
  }
 }
 printf("%d\n",max);
 return 0;
}

void search(int i,int j)
{
    count++;
    a[i][j]=-2;
    if(i+1<m&&a[i+1][j]==1)
        search(i+1,j);
    if(i-1>=0&&a[i-1][j]==1)
        search(i-1,j);
    if(j+1<n&&a[i][j+1]==1)
        search(i,j+1);
    if(j-1>=0&&a[i][j-1]==1)
        search(i,j-1);
    if(i+1<m&&j+1<n&&a[i+1][j+1]==1)
        search(i+1,j+1);
    if(i+1<m&&j-1>=0&&a[i+1][j-1]==1)
        search(i+1,j-1);
    if(i-1>=0&&j-1>=0&&a[i-1][j-1]==1)
        search(i-1,j-1);
    if(i-1>=0&&j+1<n&&a[i-1][j+1]==1)
        search(i-1,j+1);      
}

