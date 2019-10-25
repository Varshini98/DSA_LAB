#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3;
int i=0,j=0,num,a,b,count1=0,count2=0;
int *n,*m;
f1=fopen("in1.txt","r");
f2=fopen("in2.txt","r");
f3=fopen("out.txt","w");
while(fscanf(f1,"%d",&a)>0)
{
  count1++;
}
while(fscanf(f2,"%d",&b)>0)
{
   count2++;
}
n=(int*)calloc(count1,sizeof(int));
m=(int*)calloc(count2,sizeof(int));
fclose(f1);
fclose(f2);
f1=fopen("in1.txt","r");
f2=fopen("in2.txt","r");
while(fscanf(f1,"%d",&a)>0)
{
n[i]=a;
i++;
}

while(fscanf(f2,"%d",&b)>0)
{
m[j]=b;
j++;
}

i=0;
j=0;

while(1)
{
if((i==count1) && (j==count2))
break;
else if(i==count1)
{
 fprintf(f3,"%d ",m[j]);
 j=j+1;
}

else if(j==count2)
{
  fprintf(f3,"%d ",n[i]);
i=i+1;
}


else if(n[i]<=m[j])
{
fprintf(f3,"%d ",n[i]);
i=i+1;
}
else
{
fprintf(f3,"%d ",m[j]);
j=j+1;
}
}
fclose(f3);
fclose(f1);
fclose(f2);

}

