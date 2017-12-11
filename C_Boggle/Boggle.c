#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funcs.h"
#define SIZE 4


int main()
{
    printf("We've got 25 words to find, 5 of them have 2 different ways to reach for them.\nLets search:\n") ;

   char boggle[SIZE][SIZE] = {{'C','A','R','T'},{'E','T','A','K'},{'E','S','M','E'},{'L','L','P','N'}}; 
   int countWords = printWords(boggle);
  
   printf("\nWords found: %d",countWords ) ;
   return 0;
}

