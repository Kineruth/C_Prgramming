#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* middle = NULL;
int counter;

int take(int num){
    counter++;
    append(num);

     if(counter==1)
     {
         middle=head;
     }
    if (!(counter % 2 == 0) && !(1 == counter))
    {
        middle = middle->next;
    }
        return (middle->val);
    }
 
void main()
{
    int num, ex;
    counter=0;
    bool flag = true;

    while(flag){
        printf("Enter a number\n");
        scanf("%d",&num);
        printf("Middle number is : %d\n", take(num) );
        printf("To exit enter 0, to continue enter 1 \n");
        scanf("%d",&ex);
        if(ex==0)
        {
            exit(0);
        }

    }

}