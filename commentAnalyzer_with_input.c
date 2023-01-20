#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void commentAnalyzer(char* string);     

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

    printf("\n\n\n\nComment Token:\n\n");

    commentAnalyzer(string);

}

void commentAnalyzer(char* string)
{
    int left = 0, right = 0;            
    int length = strlen(string);
    char str[500];                      

    while(right < length)
    {
        if(right+1 < length && string[right] == '/' && string[right+1] == '/')  
        {
            right += 2;
            left = right;       

            while(right < length)       
            {
                if(right + 1 == length)             
                {
                    str[right-left] = string[right];    
                    break;
                }

                str[right-left] = string[right];        
                right++;

            }
            str[right - left] = '\0';               


            printf("%s is a valid Comment.\n", str);        

            right++;
            left = right;
        }
        else if(right+1 < length && string[right] == '/' && string[right+1] == '*') 
        {
            right += 2;
            left = right;       

            while(right < length)       
            {
                if(right+1 < length && string[right] == '*' && string[right+1] == '/')  
                {
                    break;
                }
                str[right-left] = string[right];            
                right++;
            }
            str[right - left] = '\0';                   

            printf("%s is a valid Comment.\n", str);         
        }
        else
        {
            right++;
        }
    }
}
