#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void numberAnalyzer(char* string);      
bool isDigit(char c);                       
bool isDelimiter(char c);                      

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

    numberAnalyzer(string);

}

void numberAnalyzer(char* string)
{
    int left = 0, right = 0;            
    int length = strlen(string);

    while(right < length)       
    {

        if(isDigit(string[right]) == false && isDelimiter(string[right]) == false && string[right] != '.')
        {                                                               
            while(isDelimiter(string[right]) == false)                      
            {
                right++;
                left = right;
            }
            continue;
        }

        if(isDigit(string[right]) == true)          
        {
            right++;
        }
        else if(isDelimiter(string[right]) == true)     
        {
            if(string[left] != ' ' && isDelimiter(string[left]) == false)               
            {
                for(int i=left; i<right; i++)
                {
                    printf("%c", string[i]);                
                }
                printf(" is a number.\n");
            }

            right++;                
            left = right;               
        }
        else if(string[right] == '.')   
        {
            right++;
        }
    }
}

bool isDigit(char c)
{
    int digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i=0; i<10; i++)
    {
        if(c == digit[i])      
            return true;
    }

    return false;
}

bool isDelimiter(char c)
{
    char delimiter[] ={' ', ',', ';', '(', ')', '\t', '+', '-', '*', '/', '%', '=', '<', '>'};
    for(int i=0;i<14;i++)
    {
        if(c == delimiter[i])       
            return true;                
    }
    return false;
}

