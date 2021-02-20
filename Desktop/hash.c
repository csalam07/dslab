//I am using diffrent "emp.txt" file so output will vary from our record one
#include<stdio.h> 
#define m 20 
int HT[10]; 
int hash(int key) // This function will return the index where the key has to be placed in the table
 {
      return key%m; 
 } 
void linear_probe(int hk,int key) // This function will solve the collision
 {
      int i,flag=0; 
      for(i=hk+1;i<m;i++)
       {
            if(HT[i]==999)
             {
                  HT[i]=key; 
                  flag=1; 
                  break; 
              } 
        } 
      for(i=0;i<hk&&flag==0;i++)
       {
            if(HT[i]==999)
             { 
                 HT[i]=key; 
                 flag=1; 
                 break; 
             } 
       } 
       if(!flag) // If flag is not set to 1 indicates that the key is not placed in the table 
         printf("HASH Table is Full!!!\n"); 
 } 
void main()
 {
      FILE *fp; 
      int N,i,key,hk; 
      char name[100];
      for(i=0;i<m;i++)
       HT[i]=999; // Initialize all the table values to 999
      fp=fopen("emp.txt","r"); // Emp file includes key of an employee and name of employee 
      while(!feof(fp)) // Till the file reaches end
       { 
           fscanf(fp,"%d%s",&key,name); 
           hk=hash(key);
           if(HT[hk]==999)
            HT[hk]=key;
           else
            { 
                printf("Collision for key %d:\n",key); 
                printf("Collision solved by Linear Probing\n");
                linear_probe(hk,key); 
            } 
        }
      printf("Address\tKeys\n"); 
      for(i=0;i<m;i++)
       printf("%d\t%d\n",i,HT[i]); 
     //getch(); 
 }
