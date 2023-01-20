#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void commentAnalyzer(char* string);     // input string থেকে comment analyze করে

int main()
{
    char string[5000], c = ' ';         // c empty হিসেবে initialize করা
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')                    // c যতক্ষন enter বা newline না পাবে, input নিতে থাকবে
    {
        scanf("%c", &string[x]);
        c = string[x];                   // c এর মধ্যে current character store করা
        x++;
    }
    string[x-1] = '\0';                 // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    printf("\n\n\n\nComment Token:\n\n");

    commentAnalyzer(string);

}

void commentAnalyzer(char* string)
{
    int left = 0, right = 0;            // token এর শুরু শেষ track রাখে left, right
    int length = strlen(string);
    char str[500];                      // token গুলাকে store করার জন্য str array

    while(right < length)
    {
        if(right+1 < length && string[right] == '/' && string[right+1] == '/')  // যদি ২টা forward slash (//) থাকে, তাহলে পরেরটুকু comment
        {
            right += 2;
            left = right;       // comment শুরু হবে ২ position পরে থেকে

            while(right < length)       // input string এর বাকিটুকু check করা
            {
                if(right + 1 == length)             // যদি একেবারে input string এর শেষে চলে যায়,
                {
                    str[right-left] = string[right];    // তাহলে একেবারে শেষ পর্যন্ত comment, str এর মধ্যে last character টা store করা
                    break;
                }

                str[right-left] = string[right];        // str-এর মধ্যে character গুলা insert করা
                right++;

            }
            str[right - left] = '\0';               // str এর ending mean করতে null character use


            printf("%s is a valid Comment.\n", str);        // comment print

            right++;
            left = right;
        }
        else if(right+1 < length && string[right] == '/' && string[right+1] == '*') // যদি forward slash আর star থাকে, তাহলে multiline comment হবে
        {
            right += 2;
            left = right;       // comment শুরু হবে ২ position পরে থেকে

            while(right < length)       // input string এর বাকিটুকু check করা
            {
                if(right+1 < length && string[right] == '*' && string[right+1] == '/')  // যদি input string-এ star আর forward slash আসে, তাহলে break
                {
                    break;
                }
                str[right-left] = string[right];            // যতক্ষন না (*/) আসে, ততক্ষন পর্যন্ত str এর মধ্যে character insert করা
                right++;
            }
            str[right - left] = '\0';                   // str এর ending mean করতে null character use

            printf("%s is a valid Comment.\n", str);         // comment print
        }
        else
        {
            right++;
        }
    }
}
