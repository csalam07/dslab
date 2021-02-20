#include<stdio.h> 
#include<ctype.h>
#include<math.h> 
float a[25]; 
int top=-1; 
void push(float symbol) // Push function
 {
      a[++top]=symbol; 
 }
float pop() // Pop function
 {
      return(a[top--]); 
 }
float eval(char op,float op1,float op2) // Function for evaluating postfix expression
 {
      switch(op)
       {
            case '^': return(pow(op1,op2)); 
            case '*': return(op1*op2); 
            case '/': return(op1/op2); 
            case '%': return((int)op1%(int)op2);
// Finding remainder so typecast op1 and op2 to integer
            case '+': return(op1+op2); 
            case '-': return(op1-op2);
       }    
       return 0; 
  } 
  void main()
   {
        char postfix[25],symbol; 
        float op1,op2,res;int i; 
        //clrscr(); 
        printf("Enter the postfix expression\n"); 
        scanf("%s",postfix); 
        for(i=0;postfix[i]!='\0';i++)
         {
              symbol=postfix[i]; 
              if(isdigit(symbol))
               push(symbol-'0');
              else
               {
                    op2=pop(); 
                    op1=pop(); 
                    res=eval(symbol,op1,op2); 
                    push(res); 
                } 
         } 
         res=pop(); 
         printf("Result = %.3f",res); 
         //getch(); 
    }