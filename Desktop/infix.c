#include<stdio.h> 
//#include<conio.h> 
char a[25]; 
int top=-1; 
void push(char symbol) // Push function
 {
      a[++top]=symbol;
 }
char pop() // Pop function
 {
      char item; 
      item=a[top--]; 
      return(item); 
 }
int pre(char op) // Precedence function gives the precedence of the operator
 {
      int p; 
      switch(op)
       { 
           case '^':p=3; 
           break;
           case '*': 
           case '/': 
           case '%':p=2; 
           break;
           case '+': 
           case '-':p=1; 
           break;
           case '(':p=0; 
           break;
           case '$':p=-1; 
           break;
       }
        return p;
    } 
void infixtopostfix(char infix[],char postfix[]) // Infix to postfix conversion function
 {
      int i,j=0; 
      char symbol,item;
      push('$'); // first $ is pushed to indicate the end of the stack
      for(i=0;infix[i]!='\0';i++)
       {
            symbol=infix[i]; 
            switch(symbol)
             {
                  case '(':push(symbol); 
                  break;
                  case ')':item=pop();
                  while(item!='(') 
                    { 
                        postfix[j++]=item;
                        item=pop();
                    }
                  break;
                  case '+': 
                  case '-': 
                  case '*': 
                  case '/': 
                  case '^': 
                  case '%':while(pre(a[top])>=pre(symbol)) // Checks the precedence of symbol
                   {
                        item=pop();
                        postfix[j++]=item;
                   }
                    push(symbol);
                  break;
                  default:postfix[j++]=symbol; // If the symbol is operand copy to postfix 
                  break;
} 
}
  while(top>0) // The remaining symbols in the stack copying to postfix
   {
        item=pop(); 
        postfix[j++]=item;
   } postfix[j]='\0'; 
}
 void main()
  {
       char infix[25],postfix[25]; 
       //clrscr(); 
       printf("Enter the infix expression:\n"); 
       scanf("%s",infix); 
       infixtopostfix(infix,postfix);
       printf("Postfix expression is : %s\n",postfix); 
       //getch();
  }
