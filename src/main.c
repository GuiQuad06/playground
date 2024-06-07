#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR_IN_LINE    20u
#define NMAX             10000u
#define QMAX             10000u

typedef struct {
    char ext[11];
    char mime[51];
} mime_type_t;

typedef struct {
    int n;
    int q;
    mime_type_t *mime_map;
    char output[MAX_CHAR_IN_LINE][QMAX];
} mime_input_t;

static char *into_lower(const char *str)
{
    size_t len = strlen(str)+1;
    char *res = (char*) malloc(len);
    
    for (int i = 0 ; i < len; i++)
    {
        if (isupper(str[i]))
            res[i] = tolower(str[i]);
        else 
            res[i] = str[i];
    }
    return res;
}

int main()
{
    FILE *fptr;
    bool hasFound = false;

    mime_input_t mime;

    // Open a file in read mode
    fptr = fopen("../input.txt", "r");

    // Store the content of the file
    char *buffer = (char *)malloc(MAX_CHAR_IN_LINE);

    // If the file exist
    if(fptr != NULL)
    {
        char **end = NULL;
        char *lower_ext;

        // Parse the file
        // N Param
        fgets(buffer, MAX_CHAR_IN_LINE, fptr);
        mime.n = strtol(buffer, end, 10);

        mime.mime_map = (mime_type_t *)malloc( mime.n * sizeof(mime_type_t));

        // Q Param
        fgets(buffer, MAX_CHAR_IN_LINE, fptr);
        mime.q = strtol(buffer, end, 10);

        // input array Param
        for (int i = 0; i < mime.n; i++)
        {
            fgets(buffer, MAX_CHAR_IN_LINE, fptr);

            char *ptr_space;
            char *ptr;
            ptr = buffer;
            
            // Found the space, first word into ext struct member
            ptr_space = strchr(ptr, ' ');
            lower_ext = into_lower(ptr);
            strncpy(mime.mime_map[i].ext, lower_ext, ptr_space - ptr);
            ptr = ptr_space + 1;

            // Second word into mime struct member
            ptr_space = strchr(ptr, '\n');
            strncpy(mime.mime_map[i].mime, ptr, ptr_space - ptr);
        }

        // Output array Param
        for (int i = 0; i < mime.q; i++)
        {
            fgets(buffer, MAX_CHAR_IN_LINE, fptr);

            char *ptr_dot;
            char *ptr;
            ptr = buffer;
            hasFound = false;

            //Found the extension of the FILE
            ptr_dot = strrchr(ptr, '.');

            if (NULL == ptr_dot)
            {
                printf("UNKNOWN\n");
            }
            else 
            {
                ptr = ptr_dot + 1;
                lower_ext = into_lower(ptr);

                int indx = 0;
                for ( ; indx < mime.n ; indx++)
                {
                    if (!strncmp(lower_ext, mime.mime_map[indx].ext, strlen(mime.mime_map[indx].ext)))
                    {
                        hasFound = true; 
                        break;
                    }
                }
                if (hasFound)
                {
                    strcpy(mime.output[i], mime.mime_map[indx].mime);
                    printf("%s\n", mime.output[i]);
                }
                else 
                {
                    printf("UNKNOWN\n");
                }
            }
        }

        free(lower_ext);
    }
    // If the file does not exist
    else
    {
        printf("Not able to open the file.");
    }

    // Close the file and free dyn alloc
    free(mime.mime_map);
    free(buffer);
    fclose(fptr);

    return 0;
}
