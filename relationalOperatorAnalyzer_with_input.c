#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void operatorAnalyzer(char* string);        // input string থেকে relational operator analyze করে
bool isRelaOperator(char c);                    // কোন character relational operator কিনা জানায়


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
    string[x-1] = '\0';                     // input এর শেষে null character দিয়ে string বানিয়ে নেওয়া

    printf("\n\n\n\nOperator Token:\n\n");

    operatorAnalyzer(string);

}

void operatorAnalyzer(char* string)
{
    int length = strlen(string);

    for(int i=0; i<length; i++)
    {
        if(isRelaOperator(string[i]) == true || string[i] == '=')       // যদি i no. character relational op হয় (<, > etc) বা = হয়
        {
            if(i+1 < length && string[i+1] == '=')                  // এরসাথেই যদি = sign থাকে, তাহলে এইটা compound operator হয়ে যাবে, ২টা মিলে relational operator
            {
                printf("%c%c is a valid Relational Operator.\n", string[i], string[i+1]);
                i++;
            }
            else if(string[i] == '=')               // শুধু যদি একটা = sign হয়, তাহলে বাদ
                continue;
            else if(i+1 < length && (string[i]=='<' && string[i+1]=='<') || (string[i]=='>' && string[i+1]=='>'))      // যদি (<<,>>) হয়, তাহলেও বাদ
                i++;
            else                                                        // normally এইটা তাহলে relational
                printf("%c is a valid Relational Operator.\n", string[i]);
        }
    }
}

bool isRelaOperator(char c)
{
    char rela[] = {'<', '>', '!'};

    for(int i=0; i<3; i++)
    {
        if(c == rela[i])            // relational operator কিনা array-র সাথে মিলিয়ে check করা
            return true;
    }
    return false;
}
