#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void identifierAnalyzer(char* string);      // input string থেকে identifier operator analyze করে
bool isKeyword(char* str);                      // কোন string keyword কিনা জানায়
bool isDelimeter(char c);                           // কোন character delimeter বা separator কিনা জানায়

int main()
{
    char string[5000], c = ' ';         // c empty হিসেবে initialize করা
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')                        // c যতক্ষন enter বা newline না পাবে, input নিতে থাকবে
    {
        scanf("%c", &string[x]);
        c = string[x];                  // c এর মধ্যে current character store করা
        x++;
    }
    string[x-1] = '\0';                 // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    identifierAnalyzer(string);

}

void identifierAnalyzer(char* string)
{
    int left = 0, right = 0;            // token এর শুরু শেষ track রাখে left, right
    int length = strlen(string);
    char str[500];                      // token গুলাকে store করার জন্য str array

    while(right < length)               // যতক্ষন না input string শেষ হয়
    {
        if(isDelimeter(string[right]) == true)      // যদি current character delimeter হয়, তাহলে এর আগ পর্যন্ত একটা token complete হইছে
        {
            str[right - left] = '\0';                   // token বা str এর ending বুঝাতে str এর length এর last position-এ null character দেওয়া
            if(isKeyword(str) == false)                     // str বা token টা যদি keyword না হয়
            {
                bool ans = true;                    // ধরে নেই যে token টা একটা identifier, তাই ans হচ্ছে true

                if(isalpha(str[0]) || str[0] == '_')    // 1st character টা যদি কোন alphabet বা underscore(_) হয়, isalpha() built-in function
                {
                    for(int i=1; i<strlen(str); i++)        // এরপর token টার বাকিটুকু check করা
                    {
                        if(isalpha(str[i]) || isdigit(str[i]) || str[i] != '_')     // পরের character গুলা alphabet বা digit বা underscore, যাই হোক সমস্যা নাই
                            ans = true;
                        else                                // কিন্তু এগুলা বাদে অন্য কিছু হলেই, এই token টা identifier না, তখন ans = false করে, বের হয়ে যাবে
                        {
                            ans = false;
                            break;
                        }
                    }

                    if(ans == true)                              // যদি identifier হয়, তাহলে আগে token টা print করা লাগবে
                        printf("%s is a valid Identifier.\n", str);
                }
            }

            right++;        // পরের character নিয়ে কাজ করার জন্য right increment হয়
            left = right;       // next token এর শুরু তাহলে হবে right থেকেই
        }
        else                                    // যদি delimeter না হয়, তাহলে str token টা বড় হতে থাকবে, character গুলা add হইতে থাকবে token-এ
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
        if (strcmp(str,keywords[i]) == 0)       // keyword কিনা array-র সাথে string compare করে check করা
            return true;
    }

    return false;
}

bool isDelimeter(char c)
{
    char delimeter[] ={' ', ',', ';', '(', ')', '\t', '+', '-', '*', '/', '%', '='};
    for(int i=0;i<12;i++)
    {
        if(c == delimeter[i])       // delimeter কিনা array-র সাথে মিলিয়ে check করা
            return true;
    }
    return false;
}
