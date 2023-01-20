#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void numberAnalyzer(char* string);      // input string থেকে number analyze করে
bool isDigit(char c);                       // কোন character digit কিনা জানায়
bool isDelimiter(char c);                       // কোন character delimiter বা separator কিনা জানায়

int main()
{
    char string[5000], c = ' ';         // c empty হিসেবে initialize করা
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')                    // c যতক্ষন enter বা newline না পাবে, input নিতে থাকবে
    {
        scanf("%c", &string[x]);
        c = string[x];                  // c এর মধ্যে current character store করা
        x++;
    }
    string[x-1] = '\0';                 // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    numberAnalyzer(string);

}

void numberAnalyzer(char* string)
{
    int left = 0, right = 0;            // token এর শুরু শেষ track রাখে left, right
    int length = strlen(string);

    while(right < length)       // যতক্ষন না input string শেষ হয়
    {

        if(isDigit(string[right]) == false && isDelimiter(string[right]) == false && string[right] != '.')
        {                                                               // যদি current character digit, delimiter, point(.) কোনটাই না হয়,
            while(isDelimiter(string[right]) == false)                      // তাহলে যতক্ষন না, একটা delimiter পাওয়া যায়, input character এর পরের গুলাতে যেতে হবে
            {
                right++;
                left = right;
            }
            continue;
        }

        if(isDigit(string[right]) == true)          // যদি current character একটা digit হয়, তাহলে পরের input character নিয়ে কাজ করতে হবে
        {
            right++;
        }
        else if(isDelimiter(string[right]) == true)     // আর যদি current character delimiter হয়, তাহলে এর আগ পর্যন্ত একটা number ছিল
        {
            if(string[left] != ' ' && isDelimiter(string[left]) == false)               //token এর শুরু অবশ্যই space বা delimiter হবে না
            {
                for(int i=left; i<right; i++)
                {
                    printf("%c", string[i]);                // number token টা print করা
                }
                printf(" is a number.\n");
            }

            right++;                // পরের character নিয়ে কাজ করার জন্য right increment হয়
            left = right;               // next token এর শুরু তাহলে হবে right থেকেই
        }
        else if(string[right] == '.')   // যদি current character point (.) হয়, তাহলে পরের character নিয়ে কাজ করা লাগবে
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
        if(c == digit[i])       // digit কিনা array-র সাথে মিলিয়ে check করা
            return true;
    }

    return false;
}

bool isDelimiter(char c)
{
    char delimiter[] ={' ', ',', ';', '(', ')', '\t', '+', '-', '*', '/', '%', '=', '<', '>'};
    for(int i=0;i<14;i++)
    {
        if(c == delimiter[i])       // delimiter কিনা array-র সাথে মিলিয়ে check করা
            return true;                // delimiter আরো চাইলে বেশি নেওয়া যাইতে পারে
    }
    return false;
}

