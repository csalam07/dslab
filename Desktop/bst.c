#include<stdio.h> 
//#include<conio.h> 
#include<stdlib.h> 
struct node
 {
      int info; 
      struct node *left; 
      struct node *right; 
 }; 
typedef struct node NODE; 
NODE *insert(int item,NODE *root) // Function for inserting the elements
 {
      NODE *temp,*cur,*prev; 
      temp=(NODE *)malloc(sizeof(NODE)); 
      temp->info=item; 
      temp->left=NULL; 
      temp->right=NULL; 
      if(root==NULL)
       return temp; 
      prev=NULL; 
      cur=root; 
      while(cur!=NULL)
       {
            prev=cur; 
            cur=(item<=cur->info)?cur->left:cur->right; 
       } 
       if(item<prev->info)
        prev->left=temp; 
       else 
        prev->right=temp; 
       return root; 
 }
NODE *construct(NODE *root) // This function is for constructing the binary search tree
 {
      int a,n,i;
      printf("Enter the number of elements\n"); 
      scanf("%d",&n); 
      printf("Enter the elements\n"); 
      for(i=0;i<n;i++)
       {
            scanf("%d",&a); 
            root=insert(a,root); 
       } 
       printf("Tree constructed successfully…..\n"); 
       return root; 
 } 
void preorder(NODE *root)
 {
      if(root!=NULL)
       {
            printf("%d\t",root->info); 
            preorder(root->left); 
            preorder(root->right); 
        } 
 } 
void inorder(NODE *root)
 {
      if(root!=NULL)
       {
            inorder(root->left); 
            printf("%d\t",root->info); 
            inorder(root->right); 
        } 
 } 
void postorder(NODE *root)
 {
      if(root!=NULL)
       {
            postorder(root->left); 
            postorder(root->right); 
            printf("%d\t",root->info); 
        } 
} 
int search(NODE *root,int key)
 {
    NODE *cur; 
    int n=0; 
    cur=root; 
    if(cur!=NULL)
     {
         if(key==cur->info)
          {
               n=1; 
               return n; 
          } 
          else if(key<cur->info) // If key is less than the current node then search the key in left subtree 
            return search(cur->left,key); 
          else // If key is greater than the current node then search the key in right subtree
           return search(cur->right,key);
     } 
     else
      return 0; 
  }
NODE *minvalue(NODE* node)
 { 
     NODE *current = node; 
     while(current->left != NULL) // Loop to find the leftmost leaf
      current=current->left; 
     return current; 
 }
NODE *del(NODE *root,int key)
 {
      if(root==NULL)
       return root; 
       if(key<root->info)
        root->left=del(root->left, key); 
       else if(key>root->info)
        root->right=del(root->right, key); 
       else
        {
             if(root->left==NULL) // Node with only one child or no child
              { 
                  NODE *temp = root->right; 
                  free(root); 
                  return temp; 
              } 
              else if(root->right==NULL)
               { 
                   NODE *temp = root->left; 
                   free(root); 
                   return temp; 
               } 
               else // Node with two children
                { 
                    NODE *temp=minvalue(root->right);
                    root->info=temp->info; 
                    root->right=del(root->right, temp->info); 
                } 
        } 
        return root; 
 } 
void main()
 {
      int item,ch,key,n; 
      NODE *root; 
      //clrscr(); 
      root=NULL; 
      while(1)
       {
            printf("\n1.Construct BST\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search an Element\n6.Delete an Element\n7:Exit\n"); 
            printf("Enter choice\n"); 
            scanf("%d",&ch); 
            switch(ch)
             {
                  case 1: root=construct(root); 
                  break;
                  case 2: preorder(root); 
                  break;
                  case 3: inorder(root); 
                  break;
                  case 4: postorder(root); 
                  break;
                  case 5: if(root==NULL)
                             printf("List Empty\n"); 
                          else
                           {
                                printf("Enter the element\n"); 
                                scanf("%d",&key); 
                                n=search(root,key); 
                                if(n)
                                 printf("Key found\n"); 
                                else
                                 printf("Not found\n"); 
                            } 
                  break;
                  case 6: if(root==NULL)
                             printf("List Empty\n"); 
                          else
                           { 
                               printf("Enter the element\n"); 
                               scanf("%d",&key); 
                               n=search(root,key); 
                               if(n)
                                { 
                                    root=del(root,key);
                                    printf("Element deleted\n"); 
                                }
                                else 
                                  printf("Not found\n"); 
                            }
                  break; 
                  case 7: exit(0);
                  default: printf("Wrong Choice\n");
            }
    } 
}
