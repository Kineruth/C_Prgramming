//
// Created by Kineret Ruth on 14-Jan-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern struct Node* top;


struct Node
{
  char data;
  struct Node *next;
};


void push(char value);
const char pop();
bool isEmpty();