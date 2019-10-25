//C Program To Sort data in ascending order using bubble sort.
#include <stdio.h>
int main()
{
    int data[100],i,n,step,temp;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        
        scanf("%d",&data[i]);
    }

    for(step=0;step<n-1;++step)
    for(i=0;i<n-step-1;++i)
    {
        if(data[i]>data[i+1])   //To sort in descending order, change > to < in this line. 
        {
            temp=data[i];
            data[i]=data[i+1];
            data[i+1]=temp;
        }
    }
    printf("Sorted order(ascending): ");
    for(i=0;i<n;++i)
         printf("%d  ",data[i]);
    return 0;
}
