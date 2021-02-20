#include<stdio.h> 
//#include<conio.h> 
#include<string.h> 
#include<stdlib.h> 
struct emp
 {
      char SSN[12]; 
      char name[25]; 
      char dept[25]; 
      char designation[25]; 
      float salary; 
      int phone_no; 
      struct emp *left; 
      struct emp *right; 
  }; 
typedef struct emp EMP; 
EMP *read()
 {
      float salary; 
      EMP *temp; 
      temp=(EMP *)malloc(sizeof(EMP)); 
      printf("Enter the employees details:\n"); 
      printf("Enter SSN\n"); 
      scanf("%s",temp->SSN); 
      printf("Enter Name\n"); 
      scanf("%s",temp->name); 
      printf("Enter Department\n"); 
      scanf("%s",temp->dept); 
      printf("Enter Designation\n"); 
      scanf("%s",temp->designation); 
      printf("Enter Salary\n"); 
      scanf("%f",&salary); 
      temp->salary=salary;
      printf("Enter Phone Number\n"); 
      scanf("%d",&temp->phone_no); 
      temp->right=temp->left=NULL; 
      return temp; 
 } 
 EMP *insert_front(EMP *head)
  {
       EMP *New; 
       New=read(); 
       if(head==NULL) // If there is no node in the list then new node will be the head node 
         head=New; 
       else 
       {
            head->left=New; 
            New->right=head; 
            head=New; 
        } 
        return head; 
  } 
EMP *insert_end(EMP *head)
 {
      EMP *temp,*New; 
      New=read(); 
      if(head==NULL)
       head=New; 
      else
       {
            temp=head; 
            while(temp->right!=NULL) // Till the end of the list is reached keep on moving to the right node in the list 
            temp=temp->right; 
            temp->right=New; 
            New->left=temp; 
        } 
    return head; 
 } 
EMP *delete_front(EMP *head)
 {
      EMP *temp,*next; 
      if(head==NULL)
       printf("List is empty\n"); 
      else
       {
            temp=head; 
            if(temp->right==NULL)
               head=NULL; 
            else
             {
                  next=temp->right; 
                  temp->left=NULL; 
                  head=next; 
             } 
             free(temp); 
        } 
        return head; 
 }
EMP *delete_end(EMP *head)
 {
      EMP *temp,*prev; 
      if(head==NULL)
       printf("List is empty\n");
      else
       {
            temp=head; 
            if(temp->right==NULL)
             head=NULL; 
            else
             {
                while(temp->right!=NULL)
                 {
                      temp=temp->right;
                 } 
                 prev=temp->left; 
                 prev->right=NULL;
             }
            free(temp); 
        } 
        return head;
 } 
void display(EMP *head)
 {
      EMP *temp; 
      int count=0; 
      if(head==NULL)
       printf("List is empty\n"); 
       else
        {
             temp=head; 
             printf("SSN\tName\tDept\tDesignation\tSalary\t\tPhone_No.\n");
             while(temp!=NULL)
              {
                   printf("%s\t%s\t%s\t%s\t\t%f\t%d\n",temp->SSN,temp->name,temp->dept,temp->designation,temp->salary,temp->phone_no); 
                   temp=temp->right; 
                   count++; 
              } 
              printf("Number of nodes in DLL=%d\n",count); 
        } 
  } 
EMP *deq(EMP *head)
 {
      int ch; 
      while(1)
       {
            printf("1.Insert front\n2.Insert end\n3.Delete front\n4.Delete end\n5.Display\n6.Exit\n");
            printf("enter the choice\n"); 
            scanf("%d",&ch); 
            switch(ch)
             {
                  case 1: head=insert_front(head); 
                  break;
                  case 2: head=insert_end(head); 
                  break;
                  case 3: head=delete_front(head); 
                  break;
                  case 4: head=delete_end(head); 
                  break;
                  case 5: display(head); 
                  break;
                  case 6: 
                  return head; 
              } 
        } 
  } 
void main()
 {
      int ch,n,i; 
      EMP *head; 
      //clrscr(); 
      head=NULL; 
      printf("Creation of DLL\n"); 
      printf("Enter the number of employees\n"); 
      scanf("%d",&n); 
      for(i=1;i<=n;i++)
       head=insert_end(head);
     while(1)
     {  
         printf("1.Display\n2.Insert front\n3:Insert end \n4.Delete front\n5.Delete n5.Delete end\n6.Double ended queue\n7.Exit\n");
         printf("Enter the choice\n"); 
         scanf("%d",&ch); 
         switch(ch)
          {
             case 1: display(head); 
             break;
             case 2: head=insert_front(head);
             printf("Node Inserted at front\n"); 
             break;
             case 3: head=insert_end(head); 
             printf("Node inserted at end\n");
             break;
             case 4: head=delete_front(head); 
             printf("Node deleted at front\n"); 
             break;
             case 5: head=delete_end(head); 
             printf("Node deleted at end\n"); 
             break;
             case 6: head=deq(head); 
             break;
             case 7: exit(0); 
          } 
     } 
}
