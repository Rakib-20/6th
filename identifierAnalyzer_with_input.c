#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void identifierAnalyzer(char* string);      
bool isKeyword(char* str);                      
bool isDelimeter(char c);                           

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

    identifierAnalyzer(string);

}

void identifierAnalyzer(char* string)
{
    int left = 0, right = 0;            
    int length = strlen(string);
    char str[500];                      

    while(right < length)               
    {
        if(isDelimeter(string[right]) == true)      
        {
            str[right - left] = '\0';                   
            if(isKeyword(str) == false)                     
            {
                bool ans = true;                    

                if(isalpha(str[0]) || str[0] == '_')    
                {
                    for(int i=1; i<strlen(str); i++)        
                    {
                        if(isalpha(str[i]) || isdigit(str[i]) || str[i] != '_')     
                            ans = true;
                        else                                
                        {
                            ans = false;
                            break;
                        }
                    }

                    if(ans == true)                              
                        printf("%s is a valid Identifier.\n", str);
                }
            }

            right++;        
            left = right;       
        }
        else                                    
        {
            str[right - left] = string[right];
            right++;
        }
    }
}

bool isKeyword(char* str)
{
    char keywords[][500] = {"auto","break","case","char","const","continue","default","do","double","else",
                     "enum","extern","float","for","goto","if","int","long","register","return","short",
                     "signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
                     "volatile","while"};

    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(str,keywords[i]) == 0)       
            return true;
    }

    return false;
}

bool isDelimeter(char c)
{
    char delimeter[] ={' ', ',', ';', '(', ')', '\t', '+', '-', '*', '/', '%', '='};
    for(int i=0;i<12;i++)
    {
        if(c == delimeter[i])     
            return true;
    }
    return false;
}
