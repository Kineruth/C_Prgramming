 #include <stdio.h>
 #include <stdbool.h>
 #include "functions.h"
 #define SIZE 3

 
 
    void sortNums(int nums[])
   {                                                           
       int i, j, temp;                                            
                                                               
       for(i = 1; i < SIZE; i++) 
       {
          for(j = 1; j <= SIZE-i; j++)
          {
             if(nums[j-1] >= nums[j])                                
             {
                temp = nums[j-1];                                    
                nums[j-1] = nums[j];                                 
                nums[j] = temp;                                      
             }
         }
     }
             return;
   }        




     bool computerTurn(int nums[])
    {
    if((nums[0]+nums[1]==nums[2]) || (nums[0]==1 && nums[1]==1 && nums[2]==1))
        return false;
    else 
        return true;
 
    }




    void setByUser(int nums[], int choose, int change)
    {
    if(nums[0]==choose)
       nums[0]=change;
    else if(nums[1]==choose)
        nums[1]=change;
    else
        nums[2]=change;
    return;
  
    }






    bool checkValidInput(int nums[], int choose, int change, int valid)
{
    bool validInput=false;
    if(valid==3){
    if(choose==nums[0] && change>=0 && change<=choose)
        validInput=true;
    else if(choose==nums[1] && change>=0 && change<=choose)
    validInput=true;
    else if(choose==nums[2] && change>=0 && change<=choose)
    validInput=true;
    else
    validInput= false;
    }
    else{
        getchar();
        printf("Invalid input! Try again\n\n");
        // validInput=false;
    }
    return validInput;
    }
    
    
    
    
    
    
    bool checkInput(int nums[], int valid)
    {
    bool check=false;
    if(valid==3){
    if(nums[0]<0) 
    check= false;
    else if(nums[1]<0)
    check= false;
    else if(nums[2]<0)
    check= false;
    else if(nums[0]==0 && nums[1]==0 && nums[2]==0)
    check= false;
        else
    check=true;
    }
    else{
    getchar();
    printf("\nInvalid input! Try again\n\n");
    }

     return check;
    }

