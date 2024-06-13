#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NMAX    10000
#define LEN_MAX    15

int romanToInt(char* s)
{    
    size_t len = strlen(s);

    if (len > LEN_MAX || len < 1)
        return -1;
    else {
        unsigned int acc = 0;

        while(*s != '\n') {
            switch(*s) {
                case 'M':
                    acc += 1000;
                    s++;
                    break;
                case 'D':
                    acc += 500;
                    s++;
                    break;
                case 'C':
                    if (*(s+1) == 'M') {
                        acc += 900;
                        s += 2;
                    }
                    else if (*(s+1) == 'D') {
                        acc += 400;
                        s += 2;
                    }
                    else {
                        acc += 100;
                        s++;
                    }
                    break;
                case 'L':
                    acc += 50;
                    s++;
                    break;
                case 'X':
                    if (*(s +1) == 'L') {
                        acc += 40;
                        s += 2;
                    }
                    else if (*(s +1) == 'C') {
                        acc += 90;
                        s += 2;
                    }
                    else {
                        acc += 10;
                        s++;
                    }
                    break;
                case 'V':
                    acc += 5;
                    s++;
                    break;
                case 'I':
                    if (*(s + 1) == 'V') {
                        acc += 4;
                        s += 2;
                    }
                    else if (*(s + 1) == 'X') {
                        acc += 9;
                        s += 2;
                    }
                    else {
                        acc += 1;
                        s++;
                    }
                    break;
                default:
                    printf("Wrong character...\n");
                    return -1;
            }
        }
        return (acc >= 1 ? (acc <= 3999 ? acc : -1) : -1);
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
            // Process the int equivalent
            printf("%d\n", romanToInt(myString));
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
