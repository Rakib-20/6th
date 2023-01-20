#include<stdio.h>
#include<string.h>

int main()
{
    printf("Enter the number of lines of TAC: ");
    int n;
    scanf("%d", &n);

    int reg[100];                      
    char code[100][100];                    
    printf("\nEnter the TAC codes: \n\n");
    for(int i=0; i<n; i++)
    {
        scanf("%s", code[i]);
        reg[i] = -1;                    
    }

    printf("\nAssembly code: \n\n");
                                        
    int count = 0, x = -1, y = -1;        
    char op[5];                         

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)          
        {
            if(code[i][2] == code[j][0])   
            {
                x = j;                  
            }
        }

        for(int j=0; j<i; j++)          
        {
            if(code[i][4] == code[j][0])    
            {
                y = j;                  
            }
        }

        if(x != -1 && reg[x] != -1)         
        {
            printf("MOV R%d, R%d\n", reg[x], count);    
        }
        else                                        
        {
            printf("MOV %c, R%d\n", code[i][2], count);     
        }

        if(code[i][3] == '+')               
            strcpy(op, "ADD");
        else if(code[i][3] == '-')
            strcpy(op, "SUB");
        else if(code[i][3] == '*')
            strcpy(op, "MUL");
        else if(code[i][3] == '/')
            strcpy(op, "DIV");

        if(y != -1 && reg[y] != -1)         
        {
            printf("%s R%d, R%d\n", op, reg[y], count);     
        }
        else                                        
        {
            printf("%s %c, R%d\n", op, code[i][4], count);  
        }

        reg[i] = count;         
        x = -1;                     
        y = -1;
        count++;                
    }

    printf("MOV R%d, %c\n", count-1, code[n-1][0]); 

    return 0;
}
