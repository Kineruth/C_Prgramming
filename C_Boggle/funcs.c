#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funcs.h"
#define SIZE 4



bool isWord(char* s)
{ //25 WORDS - 5 duplicates: rat, rate, rats, art, ate.
    return (!strcmp(s,"CAT") |!strcmp(s,"CATS") |!strcmp(s,"TRAM") |!strcmp(s,"TRAMS") |!strcmp(s,"TAME") |!strcmp(s,"CAR") |
    !strcmp(s,"SMART") |!strcmp(s,"RAT") |!strcmp(s,"RATS") |!strcmp(s,"RAMP") |!strcmp(s,"ART") |!strcmp(s,"CART")||
!strcmp(s,"STAMP") |!strcmp(s,"TAKEN") |!strcmp(s,"MEN") |!strcmp(s,"MAKE") |!strcmp(s,"TAKE") |!strcmp(s,"ATE")|!strcmp(s,"ME") |
!strcmp(s,"SELL") |!strcmp(s,"STEEL") |!strcmp(s,"RAKE") |!strcmp(s,"SEE")|!strcmp(s,"RATE")|!strcmp(s,"MATE"));
}

// bool isWord(char* s){
// 		return (!strcmp(s,"CAT") |!strcmp(s,"CATS") |	!strcmp(s,"TRAM") |	!strcmp(s,"TRAMS") |!strcmp(s,"TAME") |
// 			!strcmp(s,"CAR") |!strcmp(s,"SMART") |	!strcmp(s,"RAT") |!strcmp(s,"RATS") |	!strcmp(s,"RAMP") |	!strcmp(s,"ART") |!strcmp(s,"CART") |	!strcmp(s,"STAMP") |!strcmp(s,"TAKEN") |!strcmp(s,"MEN") |	!strcmp(s,"MAKE") |	!strcmp(s,"TAKE") |	!strcmp(s,"ATE") |	!strcmp(s,"SELL") |	!strcmp(s,"STEEL") |!strcmp(s,"RAKE") );
// }

void move(char boggle[SIZE][SIZE], bool visited[SIZE][SIZE], int i, int j, char* tempStr, char* str)
{
         strcpy(tempStr,str); //temporary string to work on
         tempStr[strlen(str)]=boggle[i][j];//add charater to tempStr
         tempStr[strlen(str)+1]='\0'; //for a string
         visited[i][j]=true; //mark as visited
         return;
} 

bool isSafe(int i, int j)
{ //check borderlines
   if(i>=0 && i<SIZE && j>=0 && j<SIZE)
   {
       return true; 
   }
   return false;
}

int routin(char boggle[SIZE][SIZE], bool visited[SIZE][SIZE], int i, int j,  char* str)
{ //check if safe to move and wasn't visited already
    int counter=0;
    char tempStr[6];
   
    bool tempVisited[4][4];
    int k,l;
    for(k=0;k<4;k++){
        for(l=0;l<4;l++){
            tempVisited[k][l]= visited[k][l];
        }
    }
    
     if(strlen(str)>1 && strlen(str)<7 && isWord(str) ){
    //a word was found
         counter++;
        printf("found ::  %s\n",str);
         fflush(stdout);
     }

    if(strlen(str)<7){
    if(isSafe(i,j-1)&&!tempVisited[i][j-1])
    { //left
         move( boggle, tempVisited,i,j-1,tempStr, str);
         counter+=routin(boggle,tempVisited,i,j-1,tempStr);
         tempVisited[i][j-1]=false; //mark as unvisited
    }
    if(isSafe(i,j+1)&&!tempVisited[i][j+1])
    { //right
        move( boggle, tempVisited,i,j+1,tempStr, str);
         counter+=routin(boggle,tempVisited,i,j+1,tempStr);
         tempVisited[i][j+1]=false; //mark as unvisited
    }
    if(isSafe(i+1,j)&&!tempVisited[i+1][j])
    { //down
         move( boggle, tempVisited,i+1,j,tempStr, str);
         counter+=routin(boggle,tempVisited,i+1,j,tempStr);
         tempVisited[i+1][j]=false; //mark as unvisited
    }
     if(isSafe(i-1,j)&&!tempVisited[i-1][j])
    { //up
       move( boggle, tempVisited,i-1,j,tempStr, str);
         counter+=routin(boggle,tempVisited,i-1,j,tempStr);
         tempVisited[i-1][j]=false; //mark as unvisited
    }
    }

   return counter;
}


int printWords(char boggle[SIZE][SIZE])
{
    int counter=0,i,j;
    char str[6];
    bool visited[SIZE][SIZE] = {{false,false,false,false}};
    
    for( i=0; i<SIZE; i++)
    {
    //    memset( str, '\0', sizeof(str)); //why here and not in the other loop? do we need this?
        for ( j = 0; j < SIZE; j++) {

           memset( str, '\0', sizeof(str));
           str[0]=boggle[i][j];
            visited[i][j]=true;

            counter+=routin(boggle,visited,i,j,str);
            visited[i][j]=false;            
        }
    }
    return counter;
}

