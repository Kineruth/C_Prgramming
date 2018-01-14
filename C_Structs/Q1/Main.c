//
// Created by Kineret Ruth on 5-Jan-18.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Functions.h"

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* middle = NULL;
int counter;
int *arr;
int element_num;


 void printArr()
{
   int i;
   for(i=0; i<element_num; ++i)
   {
       printf("%d,",arr[i]);
   }
   printf("\n");
}

void main()
{
    /* Part one - Find middle number */
    counter=0;
      printf("Middle number is : %d\n", take(20));
      printf("Middle number is : %d\n", take(10));
      printf("Middle number is : %d\n", take(30));
      printf("Middle number is : %d\n", take(5));  
      printf("Middle number is : %d\n\n", take(40));
        
    /* Part two - Find median number */    
    arr = malloc(sizeof(int));
    element_num = 0;
    
    printf("Median number is: %d\n", take2(20));
    printf("Median number is: %d\n", take2(10));
    printf("Median number is: %d\n", take2(30));
    printf("Median number is: %d\n", take2(5));
    printf("Median number is: %d\n", take2(40));
    
    free(arr);
}