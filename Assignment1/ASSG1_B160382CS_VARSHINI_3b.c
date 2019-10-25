#include <stdio.h>
#include<stdlib.h>
int *a[10000000];
void trans (int i,int n);
int main()
{
int i,n,t,j,temp;


scanf("%d",&n);

for(i=0;i<n;i++)
  a[i]=(int *)malloc(n * sizeof(int));

for (i=0;i<n;i++)
{
for (j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
trans(0,n);
printf("Transposed matrix in spiral form :\n");
{
i=0;j=0;
for (t=0;t<=n/2;t++)
{
for (j=t;j<=n-t-1;j++)
{
printf("%d\t",a[i][j]);}

j--;
for (i=t+1;i<=n-t-1;i++)
{
printf("%d\t",a[i][j]);}
i--;
for (j=n-t-2;j>=t;j--)
{
printf("%d\t",a[i][j]);}
j++;
for (i=n-t-2;i>t;i--)
{printf("%d\t",a[i][j]);
}
i++;

}}}
void trans(int i,int n)
{
int temp[100],j;
for (j=i;j<n;j++)
{
temp[j]=a[i][j];
a[i][j]=a[j][i];
a[j][i]=temp[j];
}
if (i==(n-1))
{return;}
trans (i+1,n);}


