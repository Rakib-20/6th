#include<stdio.h>
#include<ctype.h>

void FIRST(char c);         
int count, n;                   
char prod[10][10], first[10];       
int main()
{
    printf("Enter the number of production: ");
    scanf("%d", &count);

    printf("\nEnter the productions: \n\n");

    for(int i=0; i<count; i++)
    {
        scanf("%s", prod[i]);
    }

    printf("\n\nFIRST of the non-terminals: \n\n");
    for(int i=0; i<count; i++)
    {
        n = 0;                  
        char c = prod[i][0];        
        FIRST(c);               

        printf("FIRST(%c) = {", c);
        for(int j=0; j<n-1; j++)
        {                               
            printf("%c, ", first[j]);
        }
        printf("%c}\n", first[n-1]);        
    }
}

void FIRST(char c)
{
    if(!isupper(c))             
        first[n++] = c;             

    for(int j=0; j<count; j++)
    {
        if(prod[j][0] == c)         
        {
            if(prod[j][2] == '$')       
                first[n++] = '$';           

            else if(islower(prod[j][2]))     
                first[n++] = prod[j][2];           

            else                        
                FIRST(prod[j][2]);          
        }
    }
}
