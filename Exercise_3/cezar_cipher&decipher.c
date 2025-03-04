#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            cipher[i] = (str[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            cipher[i] = (str[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            cipher[i] = (str[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            cipher[i] = str[i];
        }
    }
    cipher[length] = '\0';
    return cipher;
}


char* cezar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    str[length] = '\0';

    return str;
}


int main()
{
    char str[MAXN];

    printf("Enter the message: ");
    scanf("%s", str);
    printf("Enter the key: ");
    int key;
    scanf("%d", &key);

    char choice;
    printf("Do you want to cipher or decipher? c/d;");
    scanf(" %c", &choice);

    if(choice == 'c')
    {
        char* cipher = cezar_cipher(str, key);
        printf("%s", cipher);
    }
    else if(choice == 'd')
    {
        char* text = cezar_decipher(str, key);
        printf("%s", text);
        free(text);
    }
    else if (choice =='END')
    {
        return EXIT_SUCCESS;
        
    }
    
    else
    {
        printf("Invalid choice\n");
    }
    
    return EXIT_SUCCESS;
}