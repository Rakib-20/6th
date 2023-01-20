/*

The DFA is:
    L = {W|W is a string of a and b ending with the substring "bb".}
    states,Q= {1,2,3}
    start State,S=1;
    Final state,F=3;
    Input Symbols={a,b};
Transitions Are:
    T( 1,a)=1;  T(1,b)=2;   T(2,a)=1;  T(2,b)=3;   T(3,a)=1;  T(3,b)=3;

*/

#include<stdio.h>

int Move(int s, char c);            // কোনো state থেকে input character এর জন্য next কোন state-এ move করবে সেইটা return করবে

int main()
{                                   // main function টা একেবারে doc-file-এর algorithm এর মতোন
    char input[100];
    printf("Provide the input string: ");
    scanf("%s", input);

    int state = 1;                  // state = হচ্ছে starting state = 1
    int i = 0;
    char c = input[i];          // input string থেকে nextchar টা কে c তে store করা

    while(input[i] != '\0')         // যতক্ষন পর্যন্ত না null character-এ পৌছে যায়, মানে string শেষ হয়
    {
        state = Move(state, c);         // current state থেকে input charater এর জন্য নতুন যেই state Move function দিলো, ওইটাই এখন state

        if(state == -1)                 // যদি কোনো invalid state-এ চলে যায়, তাহলে আর check করার দরকার নাই, এইটা DFA accept করবে না
            break;
        i++;
        c = input[i];               // c তে nextchar store করা
    }

    printf("Accepted by DFA: ");

    if(state == 3)              // এই DFA-র final state হচ্ছে 3, তাই যদি state এর value 3 হয়, তাহলে YES
        printf("YES\n");

    else                    // অন্য কোনো state-এ থাকলে, NO
        printf("NO\n");

    return 0;
}


int Move(int s, char c)         // MOVE function টা একেক DFA-র জন্য একেকরকম হবে, DFA অনুযায়ী condition গুলা হবে
{
    if(s == 1)                  // এই DFA-র ৩টা state (1, 2,3), তাই ৩ টা if condition হবে
    {
        if(c == 'a')            // এই DFA-র ২টা input symbol, তাই প্রত্যেকটা state condition এর মধ্যে ২টা করে if condition হবে input symbol এর জন্য
            return 1;

        else if(c == 'b')
            return 2;

        else                // a,b বাদে অন্য কোন input symbol দিলে -1 return করবে, কারন এইটা invalid
            return -1;
    }
    else if(s == 2)
    {
        if(c == 'a')
            return 1;

        else if(c == 'b')
            return 3;

        else
            return -1;
    }
    else if(s == 3)
    {
        if(c == 'a')
            return 1;

        else if(c == 'b')
            return 3;

        else
            return -1;
    }
    else
        return -1;
}
