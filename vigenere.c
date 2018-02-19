#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

int main (int argc, string argv[])
{
    if(argc == 2)
    {
    
    //track the length of the input keyword
    
     int m = strlen(argv[1]);
     
     //iterate through the keyword to get an array of the corresponding shifts
     
     for(int i = 0, j = m; i < j; i++)
     {
         if(isalpha(argv[1][i]) && argv[1][i] >= 'A' && argv[1][i] <= 'Z')
         {
             argv[1][i] = argv[1][i] - 65;
         }
         
         else if (isalpha(argv[1][i]) && argv[1][i] >= 'a' && argv[1][i] <= 'z')
         {
             argv[1][i] = argv[1][i] - 97;
         }
     }
     
     //Get input text to be encrypted
     
    printf("Input text to be encrypted:");
    
    string s = GetString();
    
    int charcount = 0;
    
    
    //iterate through the input text to apply the shift
    
    for(int i = 0, j = strlen(s); i < j; i++)
    {
        
        if(isalpha(s[i]) && s[i] >= 'A' && s[i] <= 'Z' )
        {
            s[i] = s[i] - 65;
            //to access jth character shift of the keyword k, split the # of input chars into m groups using modulo
            //m groups is the amunt of chars in the input keyword
            s[i] = (s[i] + (argv[1][charcount % m]) ) % 26;
            s[i] = s[i] + 65;
            printf("%c", s[i]);
            charcount = charcount + 1;
        }
        
        else if(isalpha(s[i]) && s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 97;
            s[i] = (s[i] + (argv[1][charcount % m]) ) % 26;
            s[i] = s[i] + 97;
            printf("%c", s[i]);
            charcount = charcount + 1;
        }
        
        else
        {
            printf("%c", s[i]);
        }
    }
    }
}