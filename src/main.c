#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ASCII_SIZE                   (7u)
#define NMAX                       (101u)

static void process(const char * str)
{
    unsigned int k = 0, cnt = 0; 
    char old, tmp;
    bool isFirstBit = true;
	
    unsigned int max_size = strlen(str) * ASCII_SIZE * 4; 
    char *res = malloc(max_size * sizeof(char));
	
    size_t pos = 0;
    const char * ptr;
    ptr = str;

    // Je parcours les caracteres
    while(*ptr != '\0')
    {
        // Je parcours les bits du caractere
        for(int i = ASCII_SIZE-1 ; i >= 0 ; i--)
        {
            tmp = (*ptr >> i) & 0x01;

            if(isFirstBit)
            {
                if(tmp == 1)
                    pos += snprintf(res+pos, max_size-pos, "0 ");
                else if(tmp == 0)
                    pos += snprintf(res+pos, max_size-pos, "00 ");
                else {}
                cnt = 1;
                isFirstBit = false;
            }
            else if(tmp != old)
            {
                for(int j = 0; j < cnt; j++)
                {
                    pos += snprintf(res+pos, max_size-pos, "0");
                }
                pos += snprintf(res+pos, max_size-pos, " ");
                
                if(tmp == 1)
                    pos += snprintf(res+pos, max_size-pos, "0 ");
                else if(tmp == 0)
                    pos += snprintf(res+pos, max_size-pos, "00 ");
                else {}
                
                cnt = 1;
            }
            else 
            {
                cnt++;
            }
            old = tmp;
        }
        ptr++;
    }
    for (int j = 0; j < cnt; j++)
        pos += snprintf(res+pos, max_size-pos, "0");

    printf("%s", res);
    free(res);
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
