#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void literalAnalyzer(char* string);     

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

    printf("\n\n\nString Literal:\n\n");
    literalAnalyzer(string);

}

void literalAnalyzer(char* string)
{
    int left = 0, right = 0;        
    int length = strlen(string);
    char str[500];                      

    while(right < length)
    {
        if(string[right] == '"')        
        {
            right++;
            left = right;               
            bool isString = false;          

            while(right < length)           
            {
                if(string[right] == '"')        
                {
                    isString = true;
                    break;
                }

                str[right-left] = string[right];        
                right++;

            }
            str[right - left] = '\0';               


            if(isString == true)                            
            {
                printf("%s is a valid String Literal.\n", str);
            }

            right++;                   
            left = right;
        }
        else
        {
            right++;
        }
    }
}
