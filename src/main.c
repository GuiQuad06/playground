#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NMAX      10000
#define ASCII_SIZE    7

static void process_char(char ch)
{
    bool isFirstBit = true;
    char old, tmp;
    char data[ASCII_SIZE-1];
    unsigned int occ[ASCII_SIZE-1];
    unsigned int k = 0;

    for(int i = ASCII_SIZE-1 ; i >= 0 ; i--)
    {
        tmp = (ch >> i) & 0x01;

        if(isFirstBit)
        {
            data[k] = tmp;
            occ[k] = 1;
            isFirstBit = false;
        }
        else if(tmp != old)
        {
            data[++k] = tmp;
            occ[k] = 1;
        }
        else 
        {
            occ[k]++;
        }
        old = tmp;
    }
    // data contient le first block
    // occ contient le second block
    // k est le nombre de suite (sert a sizer les deux blocks)
}

static void process(const char * str)
{
    const char * ptr;
    ptr = str;

    while(*ptr != '\0')
    {
        // Passe le caractere
        process_char(*ptr);
        ptr++;
    }
}

int main()
{
    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("../input.txt", "r");

    // Store the content of the file
    char myString[NMAX];

    // If the file exist
    if(fptr != NULL)
    {
        // Read the content and print it
        // "for line in text:" equivalent
        while(fgets(myString, NMAX, fptr))
        {
            // Do the thing
        }

    }
    // If the file does not exist
    else
    {
        printf("Not able to open the file.");
    }

    // Close the file
    fclose(fptr);

    // Passe la chaine
    process(myString);

	return 0;
}
