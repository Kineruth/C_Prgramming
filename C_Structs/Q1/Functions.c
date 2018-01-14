//
// Created by Kineret Ruth on 5-Jan-18.
//
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "LinkedList.h"


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort()
{
   int i, j;
   int size = element_num;
   if(size==1) 
   return;
   for (i = 0; i < size-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < size-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
    

int take2(int n)
{
    element_num++;

     arr = realloc(arr, element_num*sizeof(int));
     if(arr == NULL)
     {
         exit(1);
     }
     
     arr[element_num-1]=n;
     bubbleSort();
     return arr[(element_num-1)/2];
}

int take(int num)
{
    counter++;
    append(num);

     if(counter==1)
     {
         middle=head;
     }
    if (counter % 2 == 0)
    {
        middle = middle->next;
    }
        return (middle->val);
    }