#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp,*fp1;
	char ch;
	fp=fopen("in.txt","r");
	fp1=fopen("out.txt","w");
	if(fp==NULL)  
	  {
	printf("ERROR");
	exit(0);
	  }
	else  
	  {

	while((ch=getc(fp))!=EOF) 
 	  {
	if((ch==' ' )||( ch=='\t')) 
	  {fputc(' ',fp1);
           ch=getc(fp);
	  while((ch==' ')||(ch=='\t'))
            ch=getc(fp);
            
	  
	  }
	fputc(ch,fp1);
	
	  }
	fclose(fp);}
 return 0;
}
