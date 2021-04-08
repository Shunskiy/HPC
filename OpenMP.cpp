#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
	double start = clock();
	const int N = 5000;
	int i, j, k;
	double A[N][N];
	double B[N][N];
	double C[N][N];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = rand();
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			B[i][j] = rand();
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i][j] = 0;
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	cout << (clock() - start);
	return 0;
}


