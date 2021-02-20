//Note: use this step to compile:
//step1) gcc pro3.c -o pro3 -lm
//step2) ./pro3.c
#include<stdio.h> 
//#include<conio.h> 
#include<math.h> 
#include<stdlib.h> 
#define MAX 5 
int top=-1,a[MAX]; 

void push(int item) // Push function
 {
      if(top==MAX-1)
       printf("Stack overflow\n"); 
      else
       a[++top]=item;
// Pushing an element to stack
}
 int pop() // Pop function
  {
       int itemdel; 
       if(top==-1)
        return 0; 
       else
        {
             itemdel=a[top--]; // Poping an element from stack
            return itemdel; 
        } 
   } 
void display() // Display function
 {
      int i; 
      if(top==-1)
       printf("Stack empty\n"); 
      else
       {
            printf("The elements are:\n");
            for(i=top;i>=0;i--)
             printf("%d\n",a[i]);
       }
 }
void palindrome(int num) //Palindrome function
 {
      int count=0,rem,i,rev=0,n,item; 
      n=num; 
      while(n!=0)
       {
             rem=n%10; 
             push(rem); // The last digit of a number n pushing into the stack
             n=n/10; 
             count++; // Count gives the total number of digits pushed into the stack
       } 
   
       for(i=0;i<count;i++)
        {
              item=pop();
              rev=item*pow(10,i)+rev;
             
        } 
      
        printf("Reversed number = %d\n",rev); 
        if(num==rev)
         printf("The number is palindrome\n"); 
        else
         printf("The number is not a palindrome\n"); 
        } 
void main()
 {
       int ch,item,num,itemdel; 
       //clrscr();
        while(1)
         {
               printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
               printf("Enter the choice\n"); 
               scanf("%d",&ch); 
               switch(ch)
                {
                      case 1: printf("Enter the item to be inserted\n"); 
                      scanf("%d",&item); 
                      push(item); 
                      break;
                      case 2: itemdel=pop(); 
                      if(itemdel)
                       printf("Deleted item is : %d\n",itemdel); 
                      else
                       printf("Stack underflow\n"); 
                       break;
                      case 3: display(); 
                      break;
                      case 4: printf("Enter the number:\n"); 
                      scanf("%d",&num); 
                      palindrome(num); 
                      break;
                      case 5: exit(0);
               } 
          } 
}
