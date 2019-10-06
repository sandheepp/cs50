//Libraries to be included

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// main function
int main(int argc, string argv[])
{
    int length = 0, i = 0, key = 0, str_length = 0;
    char str[100];
    //if there are two arguments
    if (argc == 2)
    {   
        length = strlen(argv[1]);
        for (i = 0 ; i < length ; i++)
        {    
            //checking if every argument is a number
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                exit(1);
            }
            key = key * 10 + argv[1][i] - '0';
        }
        printf("plaintext:");
        fgets(str, 100, stdin); 
        printf("ciphertext:");
        str_length = strlen(str);
        //Loop through the length of the string
        for (i = 0 ; i < str_length ; i++)
        {
            //To check if it uppercase
            if ((str[i] >= 'A' && str[i] <= 'Z'))
            {
                str[i] = 'A' + (str[i] - 'A' + key) % 26;
                printf("%c", str[i]);
            }
            //To check if it is lowercase
            else if ((str[i] >= 'a' && str[i] <= 'z'))
            {
                str[i] = 'a' + (str[i] - 'a' + key) % 26;
                printf("%c", str[i]);
            }
            else //if it is any other character
            {
                printf("%c", str[i]);
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
}
