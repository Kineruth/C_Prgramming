//
// Created by Kineret Ruth on 14-Jan-18.
//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

void push(char value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   // strcpy(newNode->data, value);
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
}

const char pop()
{
      struct Node *temp = top;
      char c = temp->data;
      // strcpy(s, temp->data);
      top = temp->next;
      free(temp);
      return c;
   
}
bool isEmpty()
{
    bool ans =  false;
   if(top == NULL)
   {
        ans = true;
   }
      
   else
   ans = false;
   return ans;
}    