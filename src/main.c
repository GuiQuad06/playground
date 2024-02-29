#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "sort.h"

#define N    (800000u)

static void create_rand_array(int data[], size_t len)
{
    for (int i = 0; i < len; i++)
    {
        data[i] = rand();
    }
}

int main()
{
    srand( time( NULL ) );

    int toto[N];
    create_rand_array(toto, N);

    clock_t begin = clock();

    selection_sort(toto, N);

    clock_t end = clock();
    unsigned long ticks = (unsigned long) (end - begin);
    printf( "Selection Sort Finished in %ld ticks\n", ticks ); 

    create_rand_array(toto, N);

    begin = clock();

    bubble_sort(toto, N);

    end = clock();
    ticks = (unsigned long) (end - begin);
    printf( "bubble_sort Finished in %ld ticks\n", ticks ); 

    create_rand_array(toto, N);
    
    begin = clock();

    swapping_sort(toto, N);

    end = clock();
    ticks = (unsigned long) (end - begin);
    printf( "swapping_sort Finished in %ld ticks\n", ticks ); 

    create_rand_array(toto, N);

    begin = clock();

    merge_sort(toto, N);

    end = clock();
    ticks = (unsigned long) (end - begin);
    printf( "Merge sort Finished in %ld ticks\n", ticks ); 

    return EXIT_SUCCESS;
}
