#include <stdio.h>
int gcd(int a,int b);
void swap(int *a,int *b);
int main()
{
int p;
struct ratio
{
int a,b;
}x[100000];
int n,c,d,i,j;
scanf("%d", &n);


if(n==1)
{

scanf("%d %d",&x[0].a,&x[0].b);
 if(x[0].b==0) {printf("Error! Denominator cannot be zero");}
  else
  printf("%d/%d",x[0].a,x[0].b);
}

if (n==2)
{

scanf("%d %d",&x[0].a,&x[0].b);
if(x[0].b==0) {printf("Error! Denominator cannot be zero");}
scanf("%d %d",&x[1].a,&x[1].b);
if(x[1].b==0) {printf("Error! Denominator cannot be zero"); }
x[0].a=x[0].a*x[1].b+x[0].b*x[1].a;
x[0].b=x[0].b*x[1].b;
x[1].a=gcd(x[0].a,x[0].b);
x[0].a=x[0].a/x[1].a;
x[0].b=x[0].b/x[1].a;
printf("%d/%d",x[0].a,x[0].b);
}

if(n==3)
{

scanf("%d %d",&x[0].a,&x[0].b);
if(x[0].b==0) {printf("Error! Denominator cannot be zero");}
scanf("%d %d",&x[1].a,&x[1].b);
if(x[1].b==0) {printf("Error! Denominator cannot be zero"); }
else
{
x[0].a=x[0].a*x[1].a;
x[0].b=x[0].b*x[1].b;
x[1].a=gcd(x[0].a,x[0].b);
x[0].a=x[0].a/x[1].a;
x[0].b=x[0].b/x[1].a;
printf("%d/%d",x[0].a,x[0].b);
}
}

if (n==4)
{
  scanf("%d",&p);
struct ratio s[p];
  for (i=0;i<p;i++)
  {
  scanf("%d %d",&s[i].a,&s[i].b);
    }
    for(j=0;j<p;j++)
    {
  for (i=0;i<p-j;i++)
  {
    if ((s[i].a*s[i+1].b)>(s[i+1].a*s[i].b))
    {swap (&s[i].a,&s[i+1].a);
    swap (&s[i].b,&s[i+1].b);
  }}}
  for(i=0;i<p;i++)
  {
    printf("%d/%d\t",s[i].a,s[i].b);
  }}

if (n==5)
{

scanf("%d %d",&x[0].a,&x[0].b);
x[1].a=gcd(x[0].a,x[0].b);
x[0].a=(x[0].a/x[1].a);
x[0].b=(x[0].b/x[1].a);
printf("%d/%d",x[0].a,x[0].b);
}
}

int gcd(int a,int b)
{
  int c,i;
  for(i=1;((i<=a)&&(i<=b));i++)
  {if (((a%i)==0)&&((b%i)==0))
  c=i;
  }
  return c;
}

void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
return ;
}





