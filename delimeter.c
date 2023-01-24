 #include<stdio.h>
  #include<string.h>
 int main()
 {
     char deli[]={' ', '(', ')', '{', '}', '[', ']', ',', ';'};
     char s[100];
     int i,j,k;
     printf("Enter Statement: ");
     gets(s);
     int len=strlen(s);
     for(i=0;i<len;i++)
     {
         for(j=0;j<9;j++)
         {
             if(s[i]==deli[j])printf("%c is delimiter\n",s[i]);
         }
     }

 }
