#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NMAX       (10000u)
#define MAX_THIRD    (999u)
#define SIZE_PLAQUE   (10u)

#define INIT_PLAQUE    {.first_delimiter = '-', .second_delimiter = '-'}

typedef struct __attribute__((__packed__)) {
    char first_letters[2];
    char first_delimiter;
    char third_digit[3];
    char second_delimiter;
    char second_letters[2];
} plaque_t;

static void parsing(plaque_t * pl, char * str)
{
    char * ptr, *end_ptr;
    ptr = str;
    end_ptr = strchr(ptr, pl->first_delimiter);
    memcpy(pl->first_letters, ptr, end_ptr-ptr);

    ptr = end_ptr + 1;
    end_ptr = strchr(ptr, pl->second_delimiter);
    memcpy(pl->third_digit, ptr, end_ptr-ptr);
            
    ptr = end_ptr + 1;
    memcpy(pl->second_letters, ptr, sizeof(pl->first_letters));
}

static void process(char * res, plaque_t * pl, const unsigned int nb)
{
    char tmp[4] ;
    unsigned int sum = (nb + atoi(pl->third_digit));
    unsigned int new_value = sum % MAX_THIRD;
    unsigned int reste = (unsigned int)(sum / MAX_THIRD);

    while (reste > 0)
    {
        // 998+1 particular case
        if (sum == MAX_THIRD)
        {
            new_value = MAX_THIRD;
            break;
        }

        // Incremente le second_letters and test
        if (++pl->second_letters[1] > 'Z')
        {
            pl->second_letters[1] = 'A';
            if (++pl->second_letters[0] > 'Z')
            {
                pl->second_letters[0] = 'A';    
                if (++pl->first_letters[1] > 'Z')
                {
                    pl->first_letters[1] = 'A';     
                    if (++pl->first_letters[0] > 'Z')
                    {
                        fprintf(stderr, "Overflow de plaque !\n");
                    }
                }
            }
        }
        reste--;
    }
    // Format the string response
    // First : format the mid integer with a 3 digits format
    sprintf(tmp, "%03d", new_value);
    // Second : doing this memcpy with (void*) cast remove the \0 after the middle number 
    memcpy(&pl->third_digit, (void*)tmp, sizeof(pl->third_digit));
    // Finally : decode the data structure in the res string
    memcpy(res, pl, sizeof(*pl));
}

int main()
{
    FILE *fptr;
    plaque_t plaque = INIT_PLAQUE;
    char result[SIZE_PLAQUE] = "";
    const unsigned int n = 1;
   
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

    parsing(&plaque, myString);
    process(result, &plaque, n);
    printf("%s\n", result);

	return 0;
}
