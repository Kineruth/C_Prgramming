//
// Created by Kineret Ruth on 5-Jan-18.
//
#include <stdio.h>
#include <stdlib.h>

extern struct Node* head;
extern struct Node* tail;
extern struct Node* middle;
extern int counter;
extern int *arr;
extern int element_num;

void swap(int *x, int *y);
void bubbleSort();
int take2(int num);
int take(int num);
void compare(const void * a, const void * b);