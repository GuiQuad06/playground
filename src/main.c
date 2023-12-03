#include <stdlib.h>
#include <stdio.h>

#define NMAX    10000

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

	return 0;
}
