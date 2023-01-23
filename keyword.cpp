#include<bits/stdc++.h>
using namespace std;
string keywords[] = {"auto","break","case","char","const","continue","default","do","double","else",
                     "enum","extern","float","for","goto","if","int","long","register","return","short",
                     "signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
                     "volatile","while"
                    };

bool iskeyword(string str)
{
    for (int i = 0; i < 32; ++i)
        if (str == keywords[i])
        {
            cout << str << " is a keyword\n";
            return true;
        }

    return false;
}


bool isdelimeter(char a)
{
    char delimeter[5] ={' ', ',', ';', '(', ')'};
    for(int i=0;i<5;i++)
    {
        if(a==delimeter[i])
            return true;
    }
}

int main()
{
    string inp,token;
    token = "";
    getline(cin, inp);
    for(int i=0;i<inp.length();i++)
    {
        if(isalpha(inp[i]))
        {
            token = token + inp[i];
        }
        else if(isdelimeter(inp[i]))
        {
            iskeyword(token);
            token = "";
        }
    }

}
