#include<stdio.h>
#include<stdlib.h>
char *str;
int len;
void reverse(int j,int i)
{
        char temp;
        if(j<len/2)
        {
                temp=str[j];
                str[j]=str[i];
                str[i]=temp;
                reverse(j+1,i-1);
        }

}
void main()
{       int i=0;
        char c;
        str=(char *)malloc(10000000 * sizeof(char));
        scanf("%c",&c);
	for(i=0;c!='\n';i++)
        {
        str[i]=c;
        scanf("%c",&c);
        }
   	str[i]='\0';
        for(len=0;str[len]!='\0';len++);
        reverse(0,len-1);
        for(i=0;str[i]!='\0';i++)
	printf("%c",str[i]);        
}
