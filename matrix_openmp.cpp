#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>


#define N 1024
#define M 10

int A[N][N];
int B[N][N];
int C[N][N];

int main(int argc, char** argv) 
{
    int i,j,k;
    struct timeval tv1, tv2;
    struct timezone tz;
	double elapsed; 
    int nProc;
    if (argc==1)
        nProc = omp_get_num_procs();
    else 
        nProc = atoi(argv[1]);

    printf("Matrix Multiplication in OpenMP with %d processess.\n", nProc);
    omp_set_num_threads(nProc);
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            A[i][j] = rand()%M;
            B[i][j] = rand()%M;
	}
    gettimeofday(&tv1, &tz);
    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("Elapsed time = %f seconds.\n", elapsed);

    /*for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }*/
}
 