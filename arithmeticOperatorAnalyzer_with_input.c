#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void operatorAnalyzer(char* string);    // input string থেকে arithmetic operator analyze করে
bool isArithOperator(char c);               // কোন character arithmetic operator কিনা জানায়

int main()
{
    char string[5000], c = ' '; // c empty হিসেবে initialize করা
    printf("Enter a string: ");
    int x = 0;
    while(c != '\n')            // c যতক্ষন enter বা newline না পাবে, input নিতে থাকবে
    {
        scanf("%c", &string[x]);
        c = string[x];      // c এর মধ্যে current character store করা
        x++;
    }
    string[x-1] = '\0';         // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    printf("\n\n\n\nOperator Token:\n\n");

    operatorAnalyzer(string);

}

void operatorAnalyzer(char* string)
{
    int length = strlen(string);

    for(int i=0; i<length; i++)
    {
        if(isArithOperator(string[i]) == true)      // যদি i no. character arithmetic op হয় (+, - etc)
        {
            if(i+1 < length && string[i+1] == '=') // কিন্তু এরসাথেই যদি = sign থাকে, তাহলে এইটা compound operator হয়ে যাবে, so বাদ
                i++;
            else if(i+1 < length && (string[i]=='+' && string[i+1]=='+') || (string[i]=='-' && string[i+1]=='-')) // আবার যদি (++, --) হয়, তাহলেও বাদ
                i++;
            else                                                            // normally এইটা তাহলে arithmetic
                printf("%c is a valid Arithmetic Operator.\n", string[i]);
        }
    }
}

bool isArithOperator(char c)
{
    char arith[] = {'+', '-', '*', '/', '^', '%'};

    for(int i=0; i<6; i++)
    {
        if(c == arith[i])       // arithmetic operator কিনা array-র সাথে মিলিয়ে check করা
            return true;
    }
    return false;
}
