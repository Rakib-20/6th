#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void literalAnalyzer(char* string);     // input string থেকে string literal analyze করে

int main()
{
    char string[5000], c = ' ';         // c empty হিসেবে initialize করা
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')                    // c যতক্ষন enter বা newline না পাবে, input নিতে থাকবে
    {
        scanf("%c", &string[x]);
        c = string[x];                      // c এর মধ্যে current character store করা
        x++;
    }
    string[x-1] = '\0';                 // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    printf("\n\n\nString Literal:\n\n");
    literalAnalyzer(string);

}

void literalAnalyzer(char* string)
{
    int left = 0, right = 0;        // token এর শুরু শেষ track রাখে left, right
    int length = strlen(string);
    char str[500];                      // token গুলাকে store করার জন্য str array

    while(right < length)
    {
        if(string[right] == '"')        // যেই position থেকে quotation mark আসবে
        {
            right++;
            left = right;               // quotation এর পরের position থেকে string token শুরু হবে
            bool isString = false;          // ধরে নেই যে token টা string না

            while(right < length)           // input string বাকিটুকু check করা,
            {
                if(string[right] == '"')        // যখন আরেকটা quotation আসবে, তখন string true বলা যাবে, আর loop থেকে break করতে হবে
                {
                    isString = true;
                    break;
                }

                str[right-left] = string[right];        //quotation পাওয়ার আগ পর্যন্ত str token-এ character add করা হবে
                right++;

            }
            str[right - left] = '\0';               // str token এর ending বুঝাতে শেষে null character দিতে হবে


            if(isString == true)                            // string literal হলে print করতে হবে
            {
                printf("%s is a valid String Literal.\n", str);
            }

            right++;                    // next token নিয়ে কাজ start করা
            left = right;
        }
        else
        {
            right++;
        }
    }
}
