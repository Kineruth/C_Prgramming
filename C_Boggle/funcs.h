#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include "funcs.h"
#define SIZE 4


bool isWord(char* s);
bool isSafe(int i, int j);
int routin(char boggle[SIZE][SIZE], bool visited[SIZE][SIZE], int i, int j,  char* str);
void move(char boggle[SIZE][SIZE], bool visited[SIZE][SIZE], int i, int j,  char* tempStr, char* str);
int printWords(char A[SIZE][SIZE]);
