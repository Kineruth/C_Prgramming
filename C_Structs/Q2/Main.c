//Created by Kineret Ruth on 14-Jan-18.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

struct Node* top = NULL;

bool checkClosingBar(char close, const char open)
{
    if(close==')')
    {
        return (open=='(');
    }
    if(close==']')
    {
         return (open=='[');
    }
    if(close=='}')
    {
         return (open=='{');
    }
    return true;
}

bool checkOneString(char *str, int size)
{
      int i;
    char temp;

    for(i=0; i<size; i++)
    {

       temp =  str[i];
       
       if(temp=='('|| temp== '[' || temp=='{')
       {
           printf("pushed: %c\n",temp);
           push(temp);
       }
       if(temp==')' || temp== ']' || temp=='}' )
       {
           if(isEmpty()==false)
           {
             const char s = pop();
              printf("poped: %c\n",s);
            if(checkClosingBar(temp, s)==false)
             return false;
           }
           else
                return false;
       }
    }
    return true;
}

bool isStringBalanced(char** sentence, int size)
{
  int i;
  for(i=0; i<size; i++)
  {
      printf("current string: %s\n",sentence[i]);
      if(checkOneString(sentence[i],strlen(sentence[i]))==false)
        return false;
  }
  return true;
}

int main()
{
    
  char *str[] = {"if (x[i] > x[j) { return;}","if (x[i]) > x[j]() { return;}", "([])"};
 int length = sizeof (str) / sizeof (*str);
  
  if(isStringBalanced(str, length)==false)
     printf("Not Balanced!\n");
  else
     printf("Balanced!\n");
 return 0;
}