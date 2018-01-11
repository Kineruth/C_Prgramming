// A complete working C program to demonstrate all insertion methods
// on Linked List
//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(int new_data);

void append(int new_data) {
    /* allocate node
     * and put value in it
     */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->val = new_data;
    new_node->next = NULL;

    /* Linked List is empty, make the new node as the head & tail*/
    if (head == NULL)
    {
        head = new_node;
        tail=new_node;
        return;
    }
        /* add new node to the tail */
        tail->next = new_node;
        tail = tail->next;
        return;

}
 

 
