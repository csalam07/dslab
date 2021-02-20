#include<stdio.h> 
//#include<conio.h>
 #include<stdlib.h> 
 int a[50],n,pos,ele; 
 // Global variables declaration 
 void create() // Function for creating an array with n number of elements 
 { 
     int i; 
     printf("Enter the number of elements\n"); 
     scanf("%d",&n); 
     printf("Enter the array elements\n"); 
     for(i=0;i<n;i++) scanf("%d",&a[i]); 
}
void insert() // Function for inserting an element at the given position
 {
  int i; 
  printf("Enter the element and position\n"); 
  scanf("%d%d",&ele,&pos); 
  for(i=n-1;i>=pos;i--)
   { 
       a[i+1]=a[i]; 
   }
    a[pos]=ele; 
    n++; // After insertion number of elements (n) has to increase
  }
   void del() // Function for deleting an element at the given position
   { 
       int i; 
       printf("Enter the element position you want to delete\n"); 
       scanf("%d",&pos); 
       printf("The deleted element is %d\n",a[pos]); 
   for(i=pos;i<n;i++)
    {
         a[i]=a[i+1]; 
    }
     n--; // After deletion the number of elements (n) has to decrease 
   }
   void display() {
     int i;
     printf("The array elements are:\n");
      for(i=0;i<n;i++)
       printf("%d\t",a[i]); 
       printf("\n");
     }
 void main()
  {
int ch;
//clrscr();
 create();
  while(1) {
  printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
 printf("Enter the choice\n"); 
 scanf("%d",&ch); 
 switch(ch) {
case 1: insert(); break;
case 2: del(); break;
case 3: display(); break;
case 4: exit(0);
default: printf("Invalid choice\n"); } } }
  // Function for displaying the array elements
