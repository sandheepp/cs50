#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//function to return the key
int shift(char c)
{
    int key = 0;
    if ((c >= 'A' && c <= 'Z'))
    {
        key = c - 'A';
    }
    else if ((c >= 'a' && c <= 'z'))
    {
        key = c - 'a';
    }       
    return key;
}

//main function which accpets the arguments and keyword
int main(int argc, string argv[])
{
    int length = 0, i = 0, j = 0, str_length = 0, cipher_length = 0;
    char str[100];

    if (argc == 2)
    {   
        length = strlen(argv[1]);
        for (i = 0 ; i < length ; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                exit(1);
            }
        }
        cipher_length = i;
        // printf("%d", cipher_length);
        printf("plaintext:");
        fgets(str, 100, stdin); 
        printf("ciphertext:");
        str_length = strlen(str);
        
        //loop through the letters
        for (i = 0 ; i < str_length ; i++)
        {
            //if the str is a capital letter
            if ((str[i] >= 'A' && str[i] <= 'Z'))
            {
                str[i] = 'A' + (str[i] - 'A' + shift(argv[1][j])) % 26;
                printf("%c", str[i]);
                j++;
            }
            //if the str is a small letter
            else if ((str[i] >= 'a' && str[i] <= 'z'))
            {
                str[i] = 'a' + (str[i] - 'a' + shift(argv[1][j])) % 26;
                printf("%c", str[i]);
                j++;
            }
            else
            {
                printf("%c", str[i]);
            }
            //To return to the loop value o the keyword
            if (j == cipher_length)
            {
                // printf("updation");
                j = 0;
            }

        }
    }
    //if not a word
    else
    {
        printf("Usage: ./vigenete keyword \n");
        return 1; //error return
    }
}
