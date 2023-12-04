#include <stdlib.h>
#include <stdio.h>

#define NMAX    500

int main()
{
    FILE *fptr;

    unsigned long max = 0;
    unsigned int acc = 0;

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
            if (myString[0] == '\n')
            {
                if (acc > max)
                {
                    max = acc; 
                }
                acc = 0;
            }
            else 
            {
                acc += atoi(myString);
            }
        }

        // If the file does not exist
    }
    else
    {

        printf("Not able to open the file.");
    }

    // Close the file
    fclose(fptr);

    printf("L'Elf qui a mange le plus de calories en a mange:%d\n", max);

	return 0;
}
