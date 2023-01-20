#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void operatorAnalyzer(char* string);    
bool isArithOperator(char c);              

int main()
{
    char string[5000], c = ' '; 
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')            
    {
        scanf("%c", &string[x]);
        c = string[x];      
        x++;
    }
    string[x-1] = '\0';         

    printf("\n\n\n\nOperator Token:\n\n");

    operatorAnalyzer(string);

}

void operatorAnalyzer(char* string)
{
    int length = strlen(string);

    for(int i=0; i<length; i++)
    {
        if(isArithOperator(string[i]) == true)      
        {
            if(i+1 < length && string[i+1] == '=') 
                i++;
            else if(i+1 < length && (string[i]=='+' && string[i+1]=='+') || (string[i]=='-' && string[i+1]=='-')) 
                i++;
            else                                                            
                printf("%c is a valid Arithmetic Operator.\n", string[i]);
        }
    }
}

bool isArithOperator(char c)
{
    char arith[] = {'+', '-', '*', '/', '^', '%'};

    for(int i=0; i<6; i++)
    {
        if(c == arith[i])       
            return true;
    }
    return false;
}
