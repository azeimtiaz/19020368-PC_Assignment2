#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <omp.h>

#define N 80000
#define THREADS 8

int A[N];
int count[N];
int B[N];

int main()
{
  int i, j, x;
  struct timeval start, stop;

  printf("Paralell execution of the Rank Sort\n");

  // /* Generate the numbers to sort */
  // for (i = 0; i < N; i++) {
  //   A[i] = rand();
  // }

  /* Read the array from file */
  FILE *file;
  file = fopen("input.txt", "r");
  for (i = 0; i < N; i++)
    if (fscanf(file, "%d", &A[i]) != 1)
    {
      fclose(file);
      return 1;
    }
  fclose(file);

#ifdef PRINT
  for (i = 0; i < N; i++)
    printf("%d\t", A[i]);
  printf("\n");
#endif

  gettimeofday(&start, 0);

  for (i = 0; i < N; i++)
  {
    count[i] = 0;
  }

  omp_set_num_threads(THREADS);

#pragma omp parallel private(i, j, x)
  {
    /* Show total number of threads*/
    int thread_id = omp_get_thread_num();
    if (thread_id == 0)
    {
      printf("Total number of threads = %d\n", omp_get_num_threads());
    }

#pragma omp for schedule(dynamic, 1)
    for (i = 0; i < N; i++)
    {
      x = 0;

      for (j = 0; j < N; j++) /* count number of nos. less than it */
        if (A[i] > A[j])
          x++;

      /* Now the position is found */
      count[x]++;

      /* Adjust for duplicates */
      if (count[x] > 1)
        x = x + count[x] - 1;

      B[x] = A[i]; /* copy number into correct place in the final list */
    }              /* end for */
  }                /* end parallel region */

  /* show time taken for execution*/
  gettimeofday(&stop, 0);
  fprintf(stdout, "Time = %.6f\n\n",
          (stop.tv_sec + stop.tv_usec * 1e-6) - (start.tv_sec + start.tv_usec * 1e-6));

  /* print sorted list */
  printf("\nSorted list:\t");
  for (i = 0; i < N; i++)
    printf("%d\t", B[i]);
  printf("\n");

  return 0;
}
