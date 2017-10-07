#include<stdio.h>
#include<stdlib.h>
 int f(int n)
    {
      int i;
      if(n==0)
      {
         printf("\n Recursion Stopped");
      }
      else
      {
         for(i=0;i<=n;i++)
         {
            printf("\n Hello");
         }  
         f(n-1);
      }
    } 
