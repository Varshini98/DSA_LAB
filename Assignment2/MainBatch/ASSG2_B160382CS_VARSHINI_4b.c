#include<stdlib.h>
#include<stdio.h>
 void merge(int array[], int l, int a, int r)
{
    int i, j, k;
    int n1 = a - l + 1;
    int n2 =  r - a;
 
   
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[a + 1+ j];
 
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
       
        int a = l+(r-l)/2;
 
        mergeSort(array, l, a);
        mergeSort(array, a+1, r);
 
        merge(array, l, a, r);
    }
}


int main()
{

int n,i;
// printf("enter the number of elements in array\n");
 scanf("%d",&n);
 int S[n],T[n];

// printf("Enter the elements\n");
for(i=0;i<n;i++)
{
 scanf("%d",&S[i]);
}
for(i=0;i<n;i++)
{
  scanf("%d",&T[i]);
}

mergeSort(S,0,n-1);

for(i=n;i>0 ;i--);

{
 if(S[i]==T[i])
  {
   printf("%d",1);
   printf("\n");
  }
 else 
 {
   printf("%d",-1);
   printf("\n");
  }
}

}

