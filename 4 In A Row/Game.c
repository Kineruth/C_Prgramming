#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funcs.h"

#define SPACE ' '
#define COLUMNS 7
#define ROWS 6
#define Max_Value 1024

int main()
{
    int steps[42]= {0}; 
    char board[ROWS][COLUMNS]= {{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE},{SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE}};
    bool x_player=true, double_input=false, flag;
    char input[Max_Value];
    char mark;
    int column, placement=0;
    
    int k;
    
    
    printf("Welcome!\n");
    print_Board(board);

    while(1)
    {
        if(x_player)
        {
            mark='X';
            flag=true;
            
            if(double_input==true)
             {//need to move it so the sec' player could play and than exit the program
                 printf("Invalid input, bye-bye!\n");
                 exit(0);
             }
             
             printf("Player %c, please enter a column number (or 0 to undo)\n",mark);
             
            while(flag)
            {
               double_input=false;
               column = check_Input(input, &double_input);
               flag = play(column, steps, &placement, board, mark, input);

            }
            
            print_Board(board);
            
            if(placement==41)
            {
                printf("It's a tie!\n");
                exit(0);
            }
            
            x_player = false;
            
        }
        
        else
        {
            mark='O';
            flag=true;
           
            if(double_input==true)
             {//need to move it so the sec' player could play and than exit the program
                 printf("Invalid input, bye-bye!\n");
                 exit(0);
             }
             
            printf("Player %c, please enter a column number (or 0 to undo)\n",mark);
              
            while(flag)
            {
              double_input=false;
              column = check_Input(input, &double_input);
              flag = play(column, steps, &placement, board, mark, input);
            }
            
            print_Board(board);
            
            if(placement==41)
            {
                printf("It's a tie!\n");
                exit(0);
            }
            
            x_player = true;
        }
    }
}