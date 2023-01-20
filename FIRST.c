#include<stdio.h>
#include<ctype.h>

void FIRST(char c);         // একটা character জন্য FIRST function ঐটার FIRST বের করে দিতে পারে

int count, n;                   // count এইখানে কতগুলা production বুঝায়, আর n হচ্ছে, কোনো character এর first এর মধ্যে কয়টা element আছে বুঝায়
char prod[10][10], first[10];       // prod এইখানে production গুলা 2D array হিসেবে store করবে, আর first এর মধ্যে কোনো character first এর element গুলা থাকবে

int main()
{
    printf("Enter the number of production: ");
    scanf("%d", &count);

    printf("\nEnter the productions: \n\n");

    for(int i=0; i<count; i++)
    {
        scanf("%s", prod[i]);
    }

    printf("\n\nFIRST of the non-terminals: \n\n");
    for(int i=0; i<count; i++)
    {
        n = 0;                  // শুরুতে first-এ কোন element নাই
        char c = prod[i][0];        // production গুলার বামপাশের non-terminal গুলার জন্যই FIRST বের করা হবে, তাই ঐ non-terminal টাকে c তে রাখা
        FIRST(c);               // c non-terminal টার জন্য FIRST বের করা

        printf("FIRST(%c) = {", c);
        for(int j=0; j<n-1; j++)
        {                               // first array তে c non-terminal এর FIRST গুলা load হয়ে আছে, ঐটাই শুধু print দেওয়া লাগবে
            printf("%c, ", first[j]);
        }
        printf("%c}\n", first[n-1]);        // last element এর পরে কোন কমা থাকে না, তাই last element টা আলাদা করে print দেওয়া
    }
}

void FIRST(char c)
{
    if(!isupper(c))             // c যদি uppercase না হয়, তাহলে অবশ্যই c non-terminal না, c হচ্ছে terminal
        first[n++] = c;             // terminal-টাই তাহলে এইখানে first হবে, n এর value একি line-এ increment করা

    for(int j=0; j<count; j++)
    {
        if(prod[j][0] == c)         // c যদি কোন production এর 0 no character হয়, তাহলে ঐ production থেকে c এর first বের করা যাবে
        {
            if(prod[j][2] == '$')       // ঐ production এর 2nd position, মানে = এর পরে যদি $ (epsilon) থাকে,
                first[n++] = '$';           // তাহলে $-ই এইটার first

            else if(islower(prod[j][2]))     // ঐ production এর 2nd position, মানে = এর পরে যদি lower_letter এর character থাকে,  মানে terminal
                first[n++] = prod[j][2];           // তাহলে terminal-ই এইটার first

            else                        // কোনোটাই না হওয়া মানে = এর পরের character একটা non-terminal
                FIRST(prod[j][2]);          // এই non-terminal এর জন্য আবারো FIRST function call করা লাগবে
        }
    }
}
