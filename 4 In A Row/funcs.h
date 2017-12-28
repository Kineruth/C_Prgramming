#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SPACE ' '
#define COLUMNS 7
#define ROWS 6

void print_Board(char board[ROWS][COLUMNS]);
int check_Input(char *input, bool *double_input);
bool check_Same_Mark(char board[ROWS][COLUMNS],int i, int j, char mark);
bool check_row(char board[ROWS][COLUMNS],int i, int j, char mark);
bool check_column(char board[ROWS][COLUMNS],int i, int j, char mark);
bool check_Left_diagonal(char board[ROWS][COLUMNS],int i, int j, char mark);
bool check_Right_diagonal(char board[ROWS][COLUMNS],int i, int j, char mark);
bool check_winning(char board[ROWS][COLUMNS],char mark, int row, int column);
bool add_Mark(int column, int steps[42], int placement, char board[ROWS][COLUMNS], char mark);
void remove_Mark(int column, char board[ROWS][COLUMNS]);
bool play(int column, int steps[42],int *placement,char board[ROWS][COLUMNS],char mark,char *input);
// bool check_If_Full(char board[ROWS][COLUMNS]);
