#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<limits.h> // for the macro INT_MIN

struct stack 
{
    int capacity, top, *array;
};

struct stack* create(int capacity)
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1-> capacity = capacity;
    s1-> top = -1;
    s1-> array =(int *)malloc(s1->capacity * sizeof(int));
    return s1;
}

void push(struct stack *s1,int item) 
{
    if(s1->top == s1-> capacity-1)
        return;
        s1-> array[++s1->top] = item;   
}

int pop(struct stack *s1) 
{
    if(s1->top == -1)
        return INT_MIN;
    return s1->array[s1->top--];    
}

void move(struct stack *src, struct stack *dest, char s, char d)
{
    int p1= pop(src),p2= pop(dest);
    if(p1==INT_MIN)
    {
        push(src,p2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",p2,d,s);
    }
    else if(p2==INT_MIN)
    {
        push(dest,p1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",p1,s,d);
    }
    else if (p1>p2)
    {
        push(src,p1);
        push(src,p2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",p2,d,s);
    }
    else 
    {
        push(dest,p2);
        push(dest,p1);
        printf("Move the disk %d from \'%c\' to \'%c'\n",p1,s,d);
    }
}

void tower(int n, struct stack *src, struct stack *aux,struct stack *dest)
{
    int i,t;
    char s='S', d='D', a='A';
    if(n%2==0)
    {
        char temp = d;
        d=a;
        a=temp;
    }
    t= pow(2,n)-1;
    for (i=n;i>=1;i--)
    push(src,i);
    for ( i = 1; i <=t; i++)
    {
        if(i%3==1)
           move(src,dest,s,d);
        else if(i%3==2)
           move(src,aux,s,a);
        else if(i%3==0)
           move(aux,dest,a,d);
    }         
}

void main()
{
    int n;
    struct stack *src, *dest, *aux;
    printf("enter the number of disk\n");
    scanf("%d",&n);
    src= create(n);
    aux= create(n);
    dest= create(n);
    tower(n,src,aux,dest);
}

