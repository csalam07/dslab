#include<stdio.h> 
//#include<conio.h> 
#include<stdlib.h> 
struct student // Structure for student details
 {
      char usn[12],name[25],branch[25]; 
      int sem,phone_no; 
      struct student *link;
 };
typedef struct student STUD;
STUD *read() // Function for reading the student details
 {
      char usn[12],name[25],branch[25]; 
      int sem,phone_no; 
      STUD *temp; 
      temp=(STUD *)malloc(sizeof(STUD)); 
      printf("Enter the students details:\n"); 
      printf("Enter USN:"); 
      scanf("%s",temp->usn); 
      printf("Enter name:"); 
      scanf("%s",temp->name); 
      printf("Enter branch:"); 
      scanf("%s",temp->branch); 
      printf("Enter semester:"); 
      scanf("%d",&temp->sem); 
      printf("Enter phone number:"); 
      scanf("%d",&temp->phone_no); 
      temp->link=NULL; 
      return temp;
  } 
STUD *insert_front(STUD *head) // Function for inserting node at front
 {
      STUD *New; 
      New=read(); 
      New->link=head;
      return New; 
 }
STUD *insert_end(STUD *head) // Function for inserting node at end
 {
      STUD *New,*temp; 
      New=read(); 
      if(head==NULL)
       return New; 
      temp=head; 
      while(temp->link!=NULL)
       temp=temp->link; 
      temp->link=New; 
      return head;
 }
STUD *delete_front(STUD *head) // Function for deleting node at front
 {
      STUD *temp; 
      if(head==NULL)
       {
            printf("List is empty\n");
            return head;
       } 
       temp=head; 
       head=head->link; 
       free(temp); 
       return head; 
 } 
STUD *delete_end(STUD *head) // Function for deleting node at end
 {
      STUD *prev,*temp; 
      if(head==NULL)
       {
            printf("List is empty\n"); 
            return head; 
       } 
       prev=NULL; 
       temp=head; 
       while(temp->link!=NULL)
        {
             prev=temp; 
             temp=temp->link; 
        } 
        prev->link=NULL; 
        free(temp); 
        return head;
  } 
void display(STUD *head)
 {
      STUD *temp; 
      int count=0; 
      if(head==NULL)
       {
            printf("List is empty\n"); 
            return; 
       } 
       printf("USN\tNAME\tBRANCH\tSEM\tPHONE NO.\n"); 
       temp=head; 
       while(temp!=NULL)
        {
             printf("%s\t%s\t%s\t%d\t%d\n",temp->usn,temp->name,temp->branch,temp->sem,temp-> phone_no); 
             temp=temp->link; 
             count++; 
        } 
        printf("The number of nodes in SLL=%d\n",count); 
        } 
        void stack()
         {
              int ch; 
              STUD *head=NULL; 
              while(1)
               {
                    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n"); 
                    printf("Enter choice\n"); 
                    scanf("%d",&ch); 
                    switch(ch)
                     {
                          case 1: head=insert_front(head); 
                          printf("Node inserted \n"); 
                          break;
                          case 2: head=delete_front(head); 
                          printf("Node deleted\n"); 
                          break;
                          case 3: display(head); 
                          break;
                          case 4: return; 
                     } 
               } 
          } 
void main() 
 { 
     int ch,i,n; 
     STUD *head=NULL; 
     //clrscr(); 
     printf("Creation of SLL of N students\n"); 
     printf("Enter the number of students\n"); 
     scanf("%d",&n); 
     for(i=1;i<=n;i++)
      head=insert_front(head); 
     printf("SLL created successfully…..\n"); 
     while(1)
      {
           printf("1.Display\n2.Insert Front\n3:Insert End\n4.Delete Front\n5.Delete End\n6.Stack\n7.Exit\n");
           printf("Enter the choice\n"); 
           scanf("%d",&ch); 
           switch(ch)
            {
                 case 1: display(head); 
                 break;
                 case 2: head=insert_front(head); 
                 printf("Node inserted at front\n"); 
                 break;
                 case 3: head=insert_end(head); 
                 printf("Node inserted at end\n"); 
                 break;
                 case 4: head=delete_front(head); 
                 printf("Node deleted at Front\n"); 
                 break;
                 case 5: head=delete_end(head); 
                 printf("Node deleted at end\n"); 
                 break;
                 case 6: stack(); 
                 break;
                 case 7: exit(0); 
            } 
      } 
 }
