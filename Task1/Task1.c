#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#define SIZE 3



    void main()
{
     int nums[SIZE];
     bool rungame=true, computer=true, input=false, invalid=true;
     int choose=0, change=0, valid;
     while(!input){
     printf("Please enter 3 numbers: \n");
     valid = scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
     if(checkInput(nums,valid))
     input=true;
     }
     sortNums(nums);
     printf("Packet sizes are: %d %d %d \n\n", nums[0], nums[1], nums[2]);
     computer=computerTurn(nums);
       while(rungame){
          
           if(computer)
           {
                 choose=nums[2];
               if(nums[0]==0 && nums[1]==0 && nums[2]>1)
           {
                 change=1;
                 nums[2]=1;
                 rungame=false;
               
           }
            else if(nums[0]==0 && nums[1]==1 && nums[2]>=1)
             {
                 change=0;
                 nums[2]=0;
                 rungame=false;
             }
             else if(nums[0]==1 && nums[1]==1 && nums[2]>1)
             {
                  change=0;
                  nums[2]=0;
             }

             else
             {
                 change=nums[1]-nums[0];
                 nums[2]=change;
        
             }
             sortNums(nums);
             printf("I turned %d to %d \n", choose, change);
             computer=false;
           }
           else
           {
                while(invalid){
                printf("Your Turn\n Please state how much to take?\n");
                valid=scanf("%d %d", &choose, &change);
               if(checkValidInput(nums, choose, change, valid)){
                setByUser(nums, choose, change);
                sortNums(nums);
                computer=true;
                invalid=false;
               }
               
                }
                invalid=true;
                
           }
          
           printf("Packet sizes are now: %d %d %d\n\n", nums[0], nums[1], nums[2]);
           if(nums[0]+nums[1]+nums[2]==1 ) //who needs to start?
           computer=false;
       }
       
       if(!rungame)
           printf("\nYou lost! Game over");
     return;
   }

