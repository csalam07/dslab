#include<stdio.h> 
//#include<conio.h> 
#include<stdlib.h> 
#define MAX 5 
int a[MAX],f=0,r=-1,count=0; 
void insert(int item) // Function for inserting an element into the queue
 {
      if(count==MAX)
       printf("Queue overflow\n"); 
      else
       {
            r=(r+1)%MAX; 
            a[r]=item;
            count=count+1; 
        }
 }
void del() // Function for deleting an element from queue
 {
      int itemdel; 
      if(count==0)
       printf("Queue underflow\n");
        else
         {
              itemdel=a[f]; 
              f=(f+1)%MAX; 
              count=count-1; 
              printf("The deleted item is %d\n",itemdel);
         }
  }
   void display() // Function for displaying the contents of queue
    {
         int i,j; 
         if(count==0)
          printf("Queue empty\n");
         else
          {
              i=f;
              for(j=1;j<=count;j++)
               {
                  printf("%d\t",a[i]); i=(i+1)%MAX; 
               } 
          } 
    }
void main()
 {
   int ch,item,itemdel; 
   //clrscr(); 
   while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the choice\n"); 
        scanf("%d",&ch); 
        switch(ch)
         {

           case 1: printf("Enter the item to be inserted\n"); 
                   scanf("%d",&item); insert(item); 
           break;
           case 2: del(); 
           break;
           case 3: display(); 
           break;
           case 4: exit(0); 
         } 
    } 
 }
