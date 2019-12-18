                                                                                                                    
#include<stdio.h>                                                                                                                     
void quicksort(int number[25],int first,int last)                                      
                                                                                                                                    /*reference:www.beginnersbook.com*/   
{                                                                                                                                        
int i, j, pivot, temp;                                                                                                                                                                                                                                                      
if(first<last)                                                                                                                        
{                                                                                                                                        
pivot=first;                                                                                                                          
i=first;                                                                                                                              
j=last;                                                                                                                                                                                                                                                                     
while(i<j)                                                                                                                            
{                                                                                                                                        
while(number[i]<=number[pivot]&&i<last)                                                                                                  
i++;                                                                                                                               
while(number[j]>number[pivot])                                                                                                           
j--;                                                                                                                               
if(i<j){                                                                                                                                 
temp=number[i];                                                                                                                       
number[i]=number[j];                                                                                                                  
number[j]=temp;                                                                                                                    
}                                                                                                                                  
}                                                                                                                                                                                                                                                                           
temp=number[pivot];                                                                                                                   
number[pivot]=number[j];                                                                                                              
number[j]=temp;                                                                                                                       
quicksort(number,first,j-1);                                                                                                          
quicksort(number,j+1,last);                                      
 }                                                                                                                                  
}                                                                                                                                                                                                                                                                           
int main()                                                                                                                            
{                                                                                                                                        
int i, count,number[100];                                                                                                             
int j, count1, number1[100];                                                                                                          
int r,k,l;                                                                                                                                                                                                                                                                  
printf("How many elements are u going to enter for table 1?: ");                                                                      
scanf("%d",&count1);                                                                                                                  
printf("Enter %d elements ", count1);                                                                                                 
number1[0]=-999;                                                                                                                      
count1+2;                                                                                                                             
number1[count1]=999;                                                                                                                  
for(i=1;i<=count1;i++)                                                                                                                
{                                                                                                                                             
scanf("%d",&number1[i]);                                                                                                      
}                                                                                                                                     
quicksort(number1,1,count1);                                                                                                       
printf("Order of sorted elements for table 1:");                                                                                      
for(i=1;i<=count1;i++)                                                                                                                
{                                                                                                                                             
printf("%d\n",number1[i]);                                                                                                                    
continue;                                                                                                             
}                                                                                                                                        
printf("How many elements are u going to enter for table 2?");                                                                        
scanf("%d",&count);                                                                                                                   
printf("Enter %d elements: ", count);                                                                                                 
number[0]=-99999999;                  
  count+2;                                                                                                                              
number[count]=99999999;                                                                                                               
for(j=1;j<=count;j++)                                                                                                                 
{                                                                                                                                        
scanf("%d",&number[j]);                                                                                                            
}                                                                                                                                                                                                                                                                           
quicksort(number,1,count);                                                                                                                                                                                                                                                  
printf("Order of Sorted elements: ");                                                                                                 
for(j=1;j<=count;j++)                                                                                                                 
{      printf(" %d\n",number[j]);                                                                                                                                                                                                                                           
continue;                                                                                                                             
}                                                                                                                                  
printf("enter the rank to be searched");                                                                                              
scanf("%d",&r);                                                                                                                                                                                                                                                                     
for(i=0;i<count1;i++)                                                                                                         
{                                                                                                                                             
for (j=0;j<count;j++)                                                                                                                 
{                                                                                                                                             
if(i+j==r)                                                                                                                            
{                                                                                                                                                                                                                                                                                   
if ((number[j]<number1[i]) && (number1[i]<=number[j+1]))                                                                              
{                                                                                                                                                                                                                                                                                                                                                                                                                                   
printf("The element at rank %d is %d",r,number1[i]);     
                                                                                                                                       
}                                                                                                                                                                                                                                                                   
else if ( (number1[i]<=number[j] ) && (number[j]<number1[i+1]))                                                                                       
{                                                                                                                                                                                                                                                                           
printf("The element at rank %d is %d",r,number[j]);                                                                                                                                                                                                                                                                                                                                                               
}                                                                                                                      
}                                                                                                                                    
}                                                                                                                          
} 
} 
