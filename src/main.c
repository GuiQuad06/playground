#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_list.h"

int main()
{
    string_list_t my_list;
    const char* string = "Hello,World";

    string_list_init(&my_list);

    int wc = string_list_split(&my_list, string, ',', 1);
    printf("There are %d words in the given sentence\n", wc);

    string_list_clear(&my_list);

    return 0;
}
