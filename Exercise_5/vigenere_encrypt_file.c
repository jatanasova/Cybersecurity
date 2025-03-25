#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024

char *vigenere_encrypt(char *plaintext, char *key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);
    char *cipher = (char *)malloc(sizeof(char) * (text_length + 1));
    memset(cipher, '\0', sizeof(char *) * (text_length + 1));

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }

    cipher[text_length] = '\0';
    return cipher;
}

int read_file(char *filename, char *data)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if (fgets(data, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

//int write_file(char)

int main()
{

    char text_filename[MAXN];
    scanf("%s", text_filename);
    char key_filename[MAXN];
    scanf("%s", key_filename);
    
    char text[MAXN];
    char key[MAXN];
    read_file(text_filename, text);
    read_file(key_filename, key);

    printf("Plaintext: %s\n", text);
    printf("Key: %s\n", key);
    

    char *cipher = vigenere_encrypt(text, key);
    printf("%s", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}
