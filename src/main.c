#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#define N    (10u)

int main()
{
    int status;

    linked_list_t *my_list = NULL;

    for (int i = 0; i < N; i++)
    {
        (void) add_node(&my_list, i);
    }

    print_list(my_list);

    status = remove_node(&my_list, 5);
    if (EXIT_SUCCESS != status)
    {
        fprintf(stderr, "No node found with this value:%d\n", status);
    }

    print_list(my_list);

    status = insert_node(&my_list, 33, 7);
    if (EXIT_SUCCESS != status)
    {
        fprintf(stderr, "Position %d not found in the list\n", status);
    }

    print_list(my_list);

    status = remove_node(&my_list, 9);
    if (EXIT_SUCCESS != status)
    {
        fprintf(stderr, "No node found with this value:%d\n", status);
    }

    print_list(my_list);

    // Free
    clear_list(&my_list);

	return EXIT_SUCCESS;
}
