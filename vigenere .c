#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int shift(string c, int counter);

int main(int argc, string argv[])
{
    // checks whether the number of arguments is correct or not
    if (argc == 2)
    {
        // iterates over argv[1] and checks whether its all alphabetical characters or not
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    int counter = 0;
    const int max_count = strlen(argv[1]);
    int key;
    int character;
    
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    // translates the plaintext to ciphertext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // checks if the char is an alphabetic character in order to move the counter
        if (isalpha(plaintext[i]))
        {
            key = shift(argv[1], counter);
            // checks if the char is in uppercase and returns it shifted according key
            if (isupper(plaintext[i]))
            {
                character = plaintext[i] + key;
                counter++;
                if (character > 90)
                {
                    // does a while loop in order to get the correct letter after it reached Z
                    while (character > 90)
                    {
                        character = 65 + (character % 91);                        
                    }
                    printf("%c", character);
                }
                else
                {
                    printf("%c", character);
                }
            }
            // checks if the char is in lowercase and returns it shifted according key     
            else if (islower(plaintext[i]))
            {
                character = plaintext[i] + key;
                counter++;
                if (character > 122)
                {
                    // does a while loop in order to get the correct letter after it reached z 
                    while (character > 122)
                    {
                        character = 97 + (character % 123);
                    }
                    printf("%c", character);
                }
                else
                {
                    printf("%c", character);
                }
            }
            // checks if the counter for the key reached its maximum and resets it if it did
            if (counter == max_count)
            {
                counter = 0;
            }
        }
        // if the char is not an aplhabetical char, it prints it as it is    
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

// returns the ammount of numbers the plaintext will be moved to become ciphertext
int shift(string c, int counter)
{
    //defines the array acording to the length of the string that will be used as a keyword
    int key[strlen(c)];
    for (int i = 0, n = strlen(c); i < n; i++)
    {
        //checks the key if the inputed character is in uppercase
        if (isupper(c[i]))
        {
            key[i] = c[i] % 65;        
        }
        //checks the key if the inputed character is in lowercase
        else if (islower(c[i]))
        {
            key[i] = c[i] % 97;
        }
        //returns error if the inputed character is not an alphabetic 
        else
        {
            return 1;
        }
    }
    return key[counter];
}
