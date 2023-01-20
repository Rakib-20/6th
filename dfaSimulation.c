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

int Move(int s, char c);            

int main()
{                                   
    char input[100];
    printf("Provide the input string: ");
    scanf("%s", input);

    int state = 1;                  
    int i = 0;
    char c = input[i];          

    while(input[i] != '\0')         
    {
        state = Move(state, c);        

        if(state == -1)                 
            break;
        i++;
        c = input[i];               
    }

    printf("Accepted by DFA: ");

    if(state == 3)              
        printf("YES\n");

    else                    
        printf("NO\n");

    return 0;
}


int Move(int s, char c)         
{
    if(s == 1)                  
    {
        if(c == 'a')            
            return 1;

        else if(c == 'b')
            return 2;

        else                
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
