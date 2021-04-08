#include <iostream>
#include <iomanip>  
#include <chrono> 
#include "mpi.h" 
using namespace std; 
int main(int argc, char* argv[]) {
setlocale(LC_ALL, "Russian"); 
srand(time(NULL));

int length1 = 100000; ; 
double* a1 = new double[length1]; 
double* b1 = new double[length1]; 
double res1 = 0, all_res1; int size, rank; 
for (int i = 0; i < length1; i++) {
	a1[i] = (100 + (double)(rand() % 1000)) / 100;
}
for (int i = 0; i < length1; i++) {
	b1[i] = (100 + (double)(rand() % 1000)) / 100;
}
auto start = chrono::steady_clock::now(); 
MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size); 
for (int i = 0; i < length1; i++) {
	res1 += a1[i] * b1[i];
}
MPI_Reduce(&res1, &all_res1, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
MPI_Finalize(); 
auto end = chrono::steady_clock::now(); 
chrono::duration<double> elapsed_seconds = end - start; 
cout « "time 1: " « elapsed_seconds.count() « "s\n"; 
delete[] a1; 
delete[] b1; 
return 0;
}