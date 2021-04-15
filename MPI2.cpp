#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
    int rank, size;
    int i, j, n = 1000;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n_partial = n / size;
    double* a_partial = new double[n_partial * n];
    double* x = new double[n];
    double* y_partial = new double[n_partial];
    double* y_total = new double[n];
    double* a = new double[n * n];
    if (rank == 0)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                    a[i * n + j] = rand();
            }
        }
        for (i = 0; i < n; i++)
        {
            x[i] = rand();
        }
    }
    double t = MPI_Wtime();
    MPI_Bcast(x, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(a, n_partial * n, MPI_DOUBLE, a_partial, n_partial * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    for (i = 0; i < n_partial; i++)
    {
        y_partial[i] = 0.0;
        for (j = 0; j < n; j++)
            y_partial[i] += a_partial[i * n + j] * x[j];
    }
    MPI_Gather(y_partial, n_partial, MPI_DOUBLE, y_total, n_partial, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    t = MPI_Wtime() - t;
    if (rank == 0)
    {
        cout << "time = " << t;
    }
    delete[] a_partial;
    delete[] a;
    delete[] x;
    delete[] y_partial;
    delete[] y_total;

    MPI_Finalize();
    return 0;
}
