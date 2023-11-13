#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 80000
#define NUMLIMIT 30000

int main()
{
    int A[N];
    int i;

    /* Generate input array */
    srand(time(NULL));
    for (i = 0; i < N; i++)
        A[i] = (rand() % NUMLIMIT);

    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}
