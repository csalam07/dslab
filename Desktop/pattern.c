#include<stdio.h>
//#include<conio.h>

  void findandreplace(char str[50],char pat[50],char rep[50])
   { 
       int s,c,p,i,j,occ=0;
       char res[50]; 
       s=p=c=j=0;
       while(str[c]!='\0') // Checking for end of the main string 
       {
            if(str[s]==pat[p]) // Comparing each character of main string and pattern string
             {
                  p++; s++; 
                  if(pat[p]=='\0') // End of the pattern string
                   {
                        occ++; // Increase the number of occurrences 
                        printf("Pattern found at %d\n",c); 
                        for(i=0;rep[i]!='\0';i++,j++) // Copy the replace string to result string 
                        res[j]=rep[i]; 
                        p=0; // Initializing pattern string from first character 
                        c=s; 
                        } 
                        } 
                        else // Characters are not matching 
                        {
                             res[j] = str[c]; // Copy the main string character to result string 
                             j++; 
                             c++; 
                             s=c; 
                             p=0; 
                             } 
                             } // End of while 
                             res[j]='\0'; 
                             if(occ)
                              {
                                   printf("Number of occurrences=%d\n",occ); 
                                   printf("The resultant string is:%s" ,res); 
                              }
                              else
                               printf("Pattern not found"); 
                        }
                         void main()
                          {
                               char str[50],pat[50],rep[50]; 
                               //clrscr(); 
                               printf("Enter a string \n"); 
                               //gets(str); 
                               scanf("%s",str);
                               printf("Enter a pattern string \n"); 
                               scanf("%s",pat);
                               printf("Enter a replace string \n"); 
                               scanf("%s",rep); 
                               findandreplace(str,pat,rep); 
                               //getch(); 
                          }
