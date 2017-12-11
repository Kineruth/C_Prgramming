#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MATRIX_SIZE 4


    
bool isWord(char* s){
		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );
}

int findWord(char A[MATRIX_SIZE][MATRIX_SIZE], char* str, bool bmatrix[MATRIX_SIZE][MATRIX_SIZE],int i,int j){
    int countwords = 0;
    char temp;
    char newstr[5];
    if(strlen(str)>2 && strlen(str)<6 ){
        if(isWord(str)){
        printf("%s\n",str);
        countwords++;
        }
    }
    bool nbmatrix[4][4];
    int k,l;
    for(k=0;k<4;k++){
        for(l=0;l<4;l++){
            nbmatrix[k][l]= bmatrix[k][l];
        }
    }
    char matrix[4][4];
    for(k=0;k<4;k++){
        for(l=0;l<4;l++){
            matrix[k][l]= A[k][l];
        }
    }
    if(strlen(str)<5){
            if(j!=3&&nbmatrix[i][j+1]==true){
                nbmatrix[i][j+1]=false;
                temp = matrix[i][j+1];
                memcpy(newstr,str, strlen(str));
                newstr[strlen(str)] = temp;
                newstr[strlen(str)+1] = '\0';
                countwords+=findWord(matrix, newstr, nbmatrix,i,j+1);
                nbmatrix[i][j+1]=true;
            }
            if(j!=0&&nbmatrix[i][j-1]==true){
                nbmatrix[i][j-1]=false;
                temp = matrix[i][j-1];
                memcpy(newstr,str, strlen(str));
                newstr[strlen(str)] = temp;
                newstr[strlen(str)+1] = '\0';
                countwords+=findWord(matrix, newstr, nbmatrix,i,j-1);
                nbmatrix[i][j-1]=true;
            }
            if(i!=3&&nbmatrix[i+1][j]==true){
                nbmatrix[i+1][j]=false;
                temp = matrix[i+1][j];
                memcpy(newstr,str, strlen(str));
                newstr[strlen(str)] = temp;
                newstr[strlen(str)+1] = '\0';
                countwords+=findWord(matrix, newstr, nbmatrix,i+1,j);
                nbmatrix[i+1][j]=true;
            }
            if(i!=0&&nbmatrix[i-1][j]==true){
                nbmatrix[i-1][j]=false;
                temp = matrix[i-1][j];
                memcpy(newstr,str, strlen(str));
                newstr[strlen(str)] = temp;
                newstr[strlen(str)+1] = '\0';
                countwords+=findWord(matrix, newstr, nbmatrix,i-1,j);
                nbmatrix[i-1][j]=true;
            }
    }
    return countwords;
}

int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]){
    bool bmatrix[4][4] = {
        {true,true,true,true},
        {true,true,true,true},
        {true,true,true,true},
        {true,true,true,true}
    };
    int i,j,countwords =0;
    char temp;
        char str[5];
    for(i=0;i<4;i++){
        
        memset( str, '\0', sizeof(str));
        for(j=0;j<4;j++){
            temp=A[i][j];
            str[0] = temp;
            bmatrix[i][j] = false;
            countwords+=findWord(A, str, bmatrix, i, j);
            bmatrix[i][j] = true;
        }
    }
    return countwords;
}

int main(void){

    char matrix[4][4] = {
            {'C','A','R','T'},
            {'E','T','A','K'},
            {'E','S','M','E'},
            {'L','L','P','N'}
        };
    int countwords = printWords(matrix);
    printf("count of words: %d\n",countwords);
    return 0;
}