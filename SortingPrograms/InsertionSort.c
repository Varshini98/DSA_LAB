//Sorting Elements of an array in ascending order using insertion sort algorithm

#include<stdio.h>

int main() {
   int i, j, num, temp, arr[20];
 
   printf("Enter total elements: ");
   scanf("%d", &num);
 
   printf("Enter %d elements: ", num);
   for (i = 0; i < num; i++) 
   {
      scanf("%d", &arr[i]);
   }
 
   for (i = 1; i < num; i++) 
  {
      temp = arr[i];
      j = i - 1;
      while ((temp < arr[j]) && (j >= 0))  //To sort elements in descending order, change temp<data[j] to temp>data[j
  {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }
 
   printf("After Sorting: ");
   for (i = 0; i < num; i++)
   {
      printf("%d\t", arr[i]);
   }
 
   return 0;
}
