//
// Created by Kineret Ruth on 5-Jan-18.
//
#include <stdio.h>
#include <stdlib.h>
extern struct Node* head;
extern struct Node* tail;
// A linked list node
struct Node
{
  int val;
  struct Node *next;
};
void append(int new_data);