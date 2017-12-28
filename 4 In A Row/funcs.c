#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcs.h"

#define SPACE ' '
#define COLUMNS 7
#define ROWS 6

void print_Board(char board[ROWS][COLUMNS])
{
int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
           printf("|%c",board[i][j]);
           if(j==COLUMNS-1)
            printf("|\n");
        }
    }
    printf(" 1 2 3 4 5 6 7\n");
}

int check_Input(char *input, bool *double_input)
{
   int count_dots=0,i,number=0;
   int input_length;
   char *value;
   bool flag = true;
   
   while(flag)
   {
       scanf("%s",input);
       input_length = strlen(input);
       
      for(i=0; i<input_length; i++)
   {
  
       if(isdigit(input[i])==0)
       { //char is not a digit
            
           if(input[i]!='.')
           {//not digit nor dot
             printf("Invalid input, bye-bye!\n");
             exit(0); 
           }
           
           if(input[i]=='.' && i!=0 && i!=input_length-1)
           {//char is a dot and in acceptable place
               count_dots++;
           }
           if(input[i]=='.' && (i==0 || i==input_length-1))
           { //dot not in an acceptable place
              printf("Invalid input, bye-bye!\n");
              exit(0);
           }
           
           if(count_dots>1)
           {//more than 1 dot
             printf("Invalid input, bye-bye!\n");
             exit(0);  
           }
          
       }
   }
    if(count_dots==1)
     {
        *double_input = true;
        value = strtok(input,".");
        number = atoi(value); 
     }
    if(count_dots==0)
        number = atoi(input);
    
    if(number<0 || number>7)
     {//is number not between 1-7 (columns' number)
        printf("Invalid input, the number must be between 1 to 7:\n");
     }
     else //got correct number
        flag=false;
   }
   
  return number;
}


bool check_Same_Mark(char board[ROWS][COLUMNS],int i, int j, char mark)
{ //check borderlines
   if(i>=0 && i<ROWS && j>=0 && j<COLUMNS)
   {
       if(board[i][j]==mark)
          return true; 
   }
   return false;
}


bool check_row(char board[ROWS][COLUMNS],int i, int j, char mark)
{
    int count =0;
    if(check_Same_Mark(board,i,j,mark)==true) count++;
    if(check_Same_Mark(board,i,j+1,mark)==true) count++;
    if(check_Same_Mark(board,i,j+2,mark)==true) count++;
    if(check_Same_Mark(board,i,j+3,mark)==true) count++;
    if(count==4) return true;
    return false;
}

bool check_column(char board[ROWS][COLUMNS],int i, int j, char mark)
{
    int count =0;
    if(check_Same_Mark(board,i,j,mark)==true) count++;
    if(check_Same_Mark(board,i+1,j,mark)==true) count++;
    if(check_Same_Mark(board,i+2,j,mark)==true) count++;
    if(check_Same_Mark(board,i+3,j,mark)==true) count++;
    if(count==4) return true;
    return false;

}

bool check_Left_diagonal(char board[ROWS][COLUMNS],int i, int j, char mark)
{
    int count =0;
    if(check_Same_Mark(board,i,j,mark)==true) count++;
    if(check_Same_Mark(board,i+1,j+1,mark)==true) count++;
    if(check_Same_Mark(board,i+2,j+2,mark)==true) count++;
    if(check_Same_Mark(board,i+3,j+3,mark)==true) count++;
    if(count==4) return true;
    return false;
}

bool check_Right_diagonal(char board[ROWS][COLUMNS],int i, int j, char mark)
{
    int count =0;
    if(check_Same_Mark(board,i,j,mark)==true) count++;
    if(check_Same_Mark(board,i+1,j-1,mark)==true) count++;
    if(check_Same_Mark(board,i+2,j-2,mark)==true) count++;
    if(check_Same_Mark(board,i+3,j-3,mark)==true) count++;
    if(count==4) return true;
    return false;
}


bool check_winning(char board[ROWS][COLUMNS],char mark, int row, int column)
{
    /* ROW: */
 if(check_row(board, row, column,mark)==true) return true;
 if(check_row(board, row, column-1,mark)==true) return true;
 if(check_row(board, row, column-2,mark)==true) return true;
 if(check_row(board, row, column-3,mark)==true) return true;
  /* COLUMN: */
 if(check_column(board,row, column, mark)) return true;
 if(check_column(board,row-1, column, mark)) return true;
 if(check_column(board,row-2, column, mark)) return true;
 if(check_column(board,row-3, column, mark)) return true;
  /* LEFT DIAGONAL: */
 if(check_Left_diagonal(board,row, column, mark)) return true;
 if(check_Left_diagonal(board,row-1, column-1, mark)) return true;
 if(check_Left_diagonal(board,row-2, column-2, mark)) return true;
 if(check_Left_diagonal(board,row-3, column-3, mark)) return true;
  /* RIGHT DIAGONAL: */
 if(check_Right_diagonal(board,row, column, mark)) return true;
 if(check_Right_diagonal(board,row-1, column+1, mark)) return true;
 if(check_Right_diagonal(board,row-2, column+2, mark)) return true;
 if(check_Right_diagonal(board,row-3, column+3, mark)) return true;
 return false;
}


bool add_Mark(int column, int steps[42], int placement, char board[ROWS][COLUMNS], char mark)
{//add mark to play board
     int i, row;
     bool enter_mark = false;
     
        for(i=ROWS-1; i>=0 && enter_mark==false; i=i-1)
            {
               if(board[i][column]==SPACE)
                 {//enter new mark & check if won
                 row=i;
                 board[row][column]=mark; 
                 steps[placement] = column+1;
                 enter_mark=true;
                   }  
                }
            
            if(enter_mark == false)
            {
                printf("Invalid input, this column is full. Please choose another one:\n");
                return false;
            }
            
            if(enter_mark && check_winning(board,mark,row,column)==true)
            {//send to check if won:
                printf("Player %c won!\n", mark);
                print_Board(board);
                exit(0);
            }
            else{
            return true;
            }
     
}

void remove_Mark(int column,char board[ROWS][COLUMNS])
{//remove last mark from play board
    
     int i;
     bool enter_mark = false;
     column = column-1;
     
        for(i=0; i<ROWS && enter_mark==false; i++)
                {
                     if(board[i][column]!=' ')
                     {
                         board[i][column]=' ';
                          enter_mark=true;
                     }
                }
}

bool play(int column, int steps[42],int *placement,char board[ROWS][COLUMNS],char mark,char *input)
{
    
    if(column == 0)
    {
       if(*placement==0)
       {//can't undo - board's empty
         printf("Board is empty - can't undo!\nChoose another number:\n");
         return true;
       }
       else
       {//send to undo last step
          *placement =  (*placement)-1;
          int prev_step = steps[*placement];
          remove_Mark(prev_step, board);
          steps[*placement]=0;
          return false;
       }
    }
    
    
    else 
    {//need to add mark to board
        if(add_Mark(column-1, steps,*placement,board, mark) == true)
        {//added successfully
          *placement = *placement+1;
          return false;
        }
          else //column is full
          return true;
       
       }
}
