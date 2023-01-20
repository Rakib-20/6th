#include<stdio.h>
#include<string.h>

void TAC(char s[]);     

int main()
{
    printf("Enter the arithmetic expression: ");
    char input[100];
    scanf("%s", input);

    printf("\nThe three address code is: \n\n");
    TAC(input);

    return 0;
}

void TAC(char s[])
{
    int cnt = 1;            

    for(int i=0; i<strlen(s); i++)     
    {
        if(s[i] == '*' || s[i] == '/')      
        {
            if(cnt == 1)                
            {
                printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);     
            }                                                                
            else                                    
            {
                if(s[i-1] == '0' && s[i+1] == '0')                  
                {                                                           
                    printf("t%d=t%d%ct%d \n", cnt, cnt-1, s[i], cnt-2); 
                }
                else if(s[i-1] == '0')                          
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i+1]); 
                }
                else if(s[i+1] == '0')                      
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i-1]);     
                }
                else                                            
                {
                    printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);     
                }
            }

            cnt++;                      
            for(int j=i-1; j<=i+1; j++)     
            {
                s[j] = '0';             
            }
            i = 0;                  
        }

    }

    for(int i=0; i<strlen(s); i++)          
    {
        if(s[i] == '+' || s[i] == '-')      
        {
            if(cnt == 1)
            {
                printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);
            }
            else
            {
                if(s[i-1] == '0' && s[i+1] == '0')
                {
                    printf("t%d=t%d%ct%d \n", cnt, cnt-1, s[i], cnt-2);
                }
                else if(s[i-1] == '0')
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i+1]);
                }
                else if(s[i+1] == '0')
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i-1]);
                }
                else
                {
                    printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);
                }
            }

            cnt++;
            for(int j=i-1; j<=i+1; j++)
            {
                s[j] = '0';
            }
            i = 0;
        }
    }                                   
                                        
    printf("%c=t%d\n\n\n", s[0], cnt-1);
}
