#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
typedef struct polynode
 {
      int coeff,x_exp,y_exp,z_exp; 
      struct polynode *link;
 } polynode; 
polynode *create(int coeff,int x_exp,int y_exp,int z_exp)
 {
      polynode *node; 
      node=(polynode*)malloc(sizeof(polynode));
      node->coeff=coeff; 
      node->x_exp=x_exp; 
      node->y_exp=y_exp; 
      node->z_exp=z_exp; 
      node->link=NULL; 
      return node; 
 } 
polynode *attach(polynode *node,polynode *poly)
 {
      polynode *cur; 
      cur=poly->link; 
      while(cur->link!=poly)
       {
            cur=cur->link;
       }
      cur->link=node;
      node->link=poly; 
      return poly;
 } 
polynode *read()
 {
      int n,i; 
      int coeff,x_exp,y_exp,z_exp;
      polynode *temp; 
      polynode *poly=(polynode*)malloc(sizeof(polynode)); 
      poly->link=poly; 
      printf("Enter number of terms\n"); 
      scanf("%d",&n); 
      for(i=0;i<n;i++)
       {
            printf("Term %d:\n",i+1); 
            printf("Enter the coefficient\n"); 
            scanf("%d",&coeff); 
            printf("Enter exponent values for x,y and z\n"); 
            scanf("%d%d%d",&x_exp,&y_exp,&z_exp); 
            temp=create(coeff,x_exp,y_exp,z_exp); 
            poly=attach(temp,poly); 
        } 
      return poly; 
 } 
void display(polynode *poly)
 {
      polynode *cur; 
      cur=poly->link; 
      while(cur!=poly)
       {
            if(cur->coeff>=0)
             printf("+%dx^%dy^%dz^%d",cur->coeff,cur->x_exp,cur->y_exp,cur->z_exp); 
            else printf("%dx^%dy^%dz^%d",cur->coeff,cur->x_exp,cur->y_exp,cur->z_exp); 
            cur=cur->link; 
        } 
} 
void evaluate(polynode *poly1)
 {
      polynode *poly; 
      int x,y,z,xval,yval,zval,res=0; 
      poly=poly1->link; 
      printf("\nEnter the values for x, y and z:\n"); 
      scanf("%d%d%d",&x,&y,&z); 
      while(poly!=poly1)
       {
            xval=pow(x,poly->x_exp); 
            yval=pow(y,poly->y_exp); 
            zval=pow(z,poly->z_exp); 
            res+=poly->coeff*xval*yval*zval; 
            poly=poly->link; 
        }
        printf("Result=%d\n",res); 
  }
polynode *add(polynode *poly1,polynode *poly2,polynode *poly)
 {
      int comp; 
      polynode *a,*b,*temp; 
      a=poly1->link; 
      b=poly2->link; 
      while(a!=poly1 && b!=poly2)
       {
            if(a->x_exp==b->x_exp && a->y_exp==b->y_exp && a->z_exp==b->z_exp)
             comp=0; 
            else if(a->x_exp>b->x_exp)
             comp=1; 
            else
             {
                  if(a->x_exp==b->x_exp && a->y_exp>b->y_exp)
                   comp=1; 
                  else if(a->x_exp==b->x_exp && a->y_exp==b->y_exp && a->z_exp>b->z_exp)
                   comp=1 ; 
                  else comp=-1;
             }
            switch (comp)
             {
                  case 0: temp=create(a->coeff+b->coeff,a->x_exp,a->y_exp,a->z_exp); 
                  poly=attach(temp,poly); 
                  a=a->link; 
                  b=b->link; 
                  break;
                  case 1: temp=create(a->coeff,a->x_exp,a->y_exp,a->z_exp); 
                  poly=attach(temp,poly); 
                  a=a->link; 
                  break;
                  case -1: temp=create(b->coeff,b->x_exp,b->y_exp,b->z_exp); 
                  poly=attach(temp,poly); 
                  b=b->link; 
                  break;
             } 
        }
        while(a!=poly1)
         {
              temp=create(a->coeff,a->x_exp,a->y_exp,a->z_exp);
               poly=attach(temp,poly);
               a=a->link;
         }
        while(b!=poly2)
         {
              temp=create(b->coeff,b->x_exp,b->y_exp,b->z_exp); 
              poly=attach(temp,poly); 
              b=b->link; 
        } 
        return poly; 
 }
void main()
 {
      int ch; 
      polynode *poly1,*poly2,*poly3; 
      //clrscr(); 
      poly3=(polynode*)malloc(sizeof(polynode)); 
      poly3->link=poly3; 
      while(1)
       {
            printf("\n1.Represent & Evaluate a Polynomial\n2.Add 2 Polynomial\n3.Exit\n"); 
            scanf("%d",&ch); 
            switch(ch)
             {
                  case 1: printf("Enter polynomial:\n"); 
                  poly1=read(); 
                  display(poly1); 
                  evaluate(poly1); 
                  break;
                  case 2: printf("Enter polynomial 1:\n"); 
                  poly1=read(); 
                  display(poly1); 
                  printf("\nEnter polynomial 2:\n"); 
                  poly2=read(); 
                  display(poly2); 
                  poly3=add(poly1,poly2,poly3); 
                  printf("\nThe resultant polynomial is:\n"); 
                  display(poly3); 
                  break;
                  case 3: exit(0); 
             } 
        } 
 }
