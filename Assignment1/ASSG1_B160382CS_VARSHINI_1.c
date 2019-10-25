#include <stdio.h>
#include<stdlib.h>
void main()
{
   int i,j=0, x,k,l,temp;
   char *str,c;
   int count=0; 
   scanf("%d", &x);
   scanf("%d",&l);
   str=(char *)malloc(l * sizeof(char));
   for(i=0;i<=l;i++)
   {
   scanf("%c",&c);
   str[i]=c;
   }
   str[i]='\0';
   scanf("%d", &k);
  
   if(x==1)
      {
	for(i = 0; i<=l; i++)
		{
		 if(str[i] >= 97 && str[i] <= 122)
			{
       		  	if( str[i]+k>122)
                  	str[i]=96+(str[i]+k)%122;
                  	else
                  	str[i]=str[i]+k;
			}
		 if(str[i] >= 65 && str[i] <= 90)
	 		{
		 	if( str[i]+k>90)
                        str[i]=64+(str[i]+k)%90;
                        else
                        str[i]=str[i]+k;
			}
		}
	  printf("%s",str);
	}

   if(x==2)
	{
	 for(i = 0; i<=l; i++)
		{
	 	 if(str[i] >= 97 && str[i] <= 122)
			{
       	 	 	 if( str[i]-k<97)
                  	 str[i]=123-(97-(str[i]-k));
			 else
                 	 str[i]=str[i]-k; 
			}
	 	 if(str[i] >= 65 && str[i] <= 90)
			{
		 	 if(str[i]-k<65)
                         str[i]=91-(65-(str[i]-k));
                         else
                         str[i]=str[i]-k;
			}
	 	 }
	 printf("%s",str);
 	}
return;
}

