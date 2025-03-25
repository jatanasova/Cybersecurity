#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* cipher, char *key)
{
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char *)malloc(sizeof(char) * (cipher_length + 1));
    memset(plaintext, '\0', sizeof(char) * (cipher_length + 1));

    for (int i = 0; i < cipher_length; i++)
    {
        if (isalpha(cipher[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(cipher[i]))
            {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            }
            else
            {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[cipher_length] = '\0';
    return plaintext;
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



int main(){
    
    char cipher_filename[MAXN];
    scanf("%s", cipher_filename);
    char key_filename[MAXN];
    scanf("%s", key_filename);
    
    char cipher[MAXN];
    char key[MAXN];
    read_file(cipher_filename, cipher);
    read_file(key_filename, key);

    printf("Plaintext: %s\n", cipher);
    printf("Key: %s\n", key);

    char* plaintext = vigenere_decrypt(cipher, key);
    printf("%s", plaintext);
    free(plaintext);
    return EXIT_SUCCESS;
}