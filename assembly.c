#include<stdio.h>
#include<string.h>

int main()
{
    printf("Enter the number of lines of TAC: ");
    int n;
    scanf("%d", &n);

    int reg[100];                       // কোন tac code এর result কোন register-এ আছে track রাখে
    char code[100][100];                    // stores the code, 1st-dimension-এ line, আর 2nd dimension-এ line এর character
    printf("\nEnter the TAC codes: \n\n");
    for(int i=0; i<n; i++)
    {
        scanf("%s", code[i]);
        reg[i] = -1;                    // কোন code-line-এই এখনো register use করা হয় নাই, তাই invalid register
    }

    printf("\nAssembly code: \n\n");
                                        // count register গুলার no. indicate করে
    int count = 0, x = -1, y = -1;        // x, 1st operand কোনো register-এ store করা কিনা সেইটা বলে, আর y 2nd register-এর জন্য
    char op[5];                         // op-র মধ্যে operation এর নাম থাকবে

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)          // পেছনের line গুলা check করে দেখা যে, 1st operand টা অন্য কোনো line-এর result কিনা
        {
            if(code[i][2] == code[j][0])    //1st operand যদি পেছনের কোন line এর result হয়, [0 position-এ ঐ line-এর result থাকে, আর 2 posion-এ ঐ line-এর 1st operand থাকে
            {
                x = j;                  // x এর মধ্যে ঐ line no store করা
            }
        }

        for(int j=0; j<i; j++)          // পেছনের line গুলা check করে দেখা যে, 1st operand টা অন্য কোনো line-এর result কিনা
        {
            if(code[i][4] == code[j][0])    //2nd operand যদি পেছনের কোন line এর result হয়, [0 position-এ ঐ line-এর result থাকে, আর 4 posion-এ ঐ line-এর 2nd operand থাকে
            {
                y = j;                  // y এর মধ্যে ঐ line no store করা
            }
        }

        if(x != -1 && reg[x] != -1)         // x আর reg[x] valid, তার মানে 1st operand টা আসলে একটা register-এ আছে
        {
            printf("MOV R%d, R%d\n", reg[x], count);    // ঐ register-টা কে নতুন একটা register-এ move করা
        }
        else                                        // যদি অন্য register-এ store করা না থাকে
        {
            printf("MOV %c, R%d\n", code[i][2], count);     // তাহলে 1st operand character টা কে নতুন register-এ move করা
        }

        if(code[i][3] == '+')               // sign অনুযায়ী op এর মধ্যে operator এর নাম copy করে রাখা
            strcpy(op, "ADD");
        else if(code[i][3] == '-')
            strcpy(op, "SUB");
        else if(code[i][3] == '*')
            strcpy(op, "MUL");
        else if(code[i][3] == '/')
            strcpy(op, "DIV");

        if(y != -1 && reg[y] != -1)         // y আর reg[y] valid, তার মানে 2nd operand টা আসলে একটা register-এ আছে
        {
            printf("%s R%d, R%d\n", op, reg[y], count);     // ঐ register-টা কে নতুন  register-এর সাথে operation করা
        }
        else                                        // যদি অন্য register-এ store করা না থাকে
        {
            printf("%s %c, R%d\n", op, code[i][4], count);  // তাহলে 2nd operand character টা কে নতুন register-এর সাথে operate করা
        }

        reg[i] = count;         // এই line এর result যেই register-এ store হবে
        x = -1;                     // x, y কে আবারো invalid করে দেওয়া
        y = -1;
        count++;                // পরের line এর জন্য register count বাড়ানো
    }

    printf("MOV R%d, %c\n", count-1, code[n-1][0]); // শেষ register-এ যে total result আছে, ঐটা একদম last variable মধ্যে move করা

    return 0;
}
