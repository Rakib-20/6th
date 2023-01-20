#include<stdio.h>
#include<string.h>

void TAC(char s[]);     // একটা arithmetic expression string হিসেবে pass করলে TAC function three address code generate করে দেবে

int main()
{
    printf("Enter the arithmetic expression: ");
    char input[100];
    scanf("%s", input);

    printf("\nThe three address code is: \n\n");
    TAC(input);

    return 0;
}

void TAC(char s[])
{
    int cnt = 1;            // temporary variable (t1, t2, t3 etc) এর numbering এর জন্য

    for(int i=0; i<strlen(s); i++)      // string টার শুরু থেকে শেষ পর্যন্ত loop
    {
        if(s[i] == '*' || s[i] == '/')      // যেই postion-এ গিয়ে * বা / খুজে পাবে, ঐটার কাজ আগে করবে
        {
            if(cnt == 1)                // এইটা যদি শুরুর temporary variable, মানে t1 হয়, তাহলে এর আগে অন্য কোন temp variable-এ result store করা নাই
            {
                printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);     // এইজন্য (t1=x*y) এর মতোন, direct character variable এর উপরেই operation হবে
            }                                                               // t এর সাথে কতো নং temp, মানে count এইটা বসবে, আর এরপর = দিয়ে বাম পাশের variable (i-1), পরে operator (i), আর তারপর ডান পাশের variable
            else                                    // যদি 1st temp variable না হয়, তাহলে এইটার কোনপাশে অন্য একটা temp variable থাকতে পারে
            {
                if(s[i-1] == '0' && s[i+1] == '0')                  // operator এর বাম আর ডান দুইপাশই যদি 0, মানে খালি থাকে, খালি মানে ঐটুকু portion এর tac code করা শেষ,
                {                                                           // তাহলে 1st operand (x) আর 2nd operand (y), দুইটাই temp variable হবে
                    printf("t%d=t%d%ct%d \n", cnt, cnt-1, s[i], cnt-2); // position i এর operator একপাশে cnt-1 no. temp variable, আর আরেকপাশে cnt-2 no.
                }
                else if(s[i-1] == '0')                          // শুধু যদি বামপাশ খালি থাকে, তার মানে বামপাশে একটা temp variable আছে
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i+1]); // ডানপাশের character variable টার সাথে বামপাশের temp variable এর operation
                }
                else if(s[i+1] == '0')                      // শুধু যদি ডানপাশ খালি থাকে, তার মানে ডানপাশে একটা temp variable আছে
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i-1]);     // বামপাশের character variable টার সাথে ডানপাশের temp variable এর operation
                }
                else                                            // যদি কোনপাশই খালি না থাকে, মানে কোন পাশেই কোন temp variable নাই,
                {
                    printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);     // তাহলে normal 1st time যেমন ছিলো, ঐরকম
                }
            }

            cnt++;                      // temp variable এর count বাড়ানো
            for(int j=i-1; j<=i+1; j++)     // i-1 আর i আর i+1, এই ৩টা position-এই তো tac code করা হলো, তাই এই ৩টা position খালি করা হবে, 0 দিয়ে
            {
                s[j] = '0';             // 0 দিয়ে এই ৩টা position খালি বুঝানো হচ্ছে, মানে এইখানে একটা temp variable আছে
            }
            i = 0;                  // আবার string এর শুরু থেকে check করা, যে কোন * বা / আছে কিনা
        }

    }

    for(int i=0; i<strlen(s); i++)          // উপরের for loop টা সুন্দর করে copy paste করলেই এই for loop হয়ে যাবে
    {
        if(s[i] == '+' || s[i] == '-')      // এই for loop-এ শুধু change এইটুকুই যে, এইখানে */ এর বদলে +- দেওয়া আছে, বাকিসব same
        {
            if(cnt == 1)
            {
                printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);
            }
            else
            {
                if(s[i-1] == '0' && s[i+1] == '0')
                {
                    printf("t%d=t%d%ct%d \n", cnt, cnt-1, s[i], cnt-2);
                }
                else if(s[i-1] == '0')
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i+1]);
                }
                else if(s[i+1] == '0')
                {
                    printf("t%d=t%d%c%c \n", cnt, cnt-1, s[i], s[i-1]);
                }
                else
                {
                    printf("t%d=%c%c%c \n", cnt, s[i-1], s[i], s[i+1]);
                }
            }

            cnt++;
            for(int j=i-1; j<=i+1; j++)
            {
                s[j] = '0';
            }
            i = 0;
        }
    }                                   // ২টা for loop এর একদম শেষের কাজটা হচ্ছে assign operator (=) এর জন্য
                                            // last পর্যন্ত যেই temp variable এর মধ্যে result টা store হইছে, ঐটাকে শুরুর character variable এর  মধ্যে store করে রাখা লাগবে
    printf("%c=t%d\n\n\n", s[0], cnt-1);
}
