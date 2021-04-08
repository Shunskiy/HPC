#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
int main()
{

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int length1 = 100000;
	int length2 = 10000;
	int length3 = 1000;
	double res1 = 0;
	double* a1 = new double[length1];
	double* b1 = new double[length1];
	for (int i = 0; i < length1; i++)
	{
		a1[i] = (100 + (double)(rand() % 1000)) / 100;
	}

	for (int i = 0; i < length1; i++)
	{
		b1[i] = (100 + (double)(rand() % 1000)) / 100;
	}

	auto start = chrono::steady_clock::now();

	for (int i = 0; i < length1; i++)
	{
		res1 += a1[i] * b1[i];
	}

	auto end = chrono::steady_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

	cout << "time 1: " << elapsed_seconds.count() << "s\n";

	delete[] a1;
	delete[] b1;
	double** a2 = new double* [length2];
	double* b2 = new double[length2];
	double* res2 = new double[length2];

	for (int i = 0; i < length2; i++)
	{
		a2[i] = new double[length2];
		for (int j = 0; j < length2; j++)
		{
			a2[i][j] = (100 + (double)(rand() % 1000)) / 100;
		}
	}

	for (int i = 0; i < length2; i++)
	{
		b2[i] = (100 + (double)(rand() % 1000)) / 100;
		res2[i] = 0;
	}

	auto start2 = chrono::steady_clock::now();

	for (int i = 0; i < length2; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			res2[i] += a2[i][j] * b2[j];
		}

	}

	auto end2 = chrono::steady_clock::now();

	chrono::duration<double> elapsed_seconds2 = end2 - start2;

	cout << "time 2: " << elapsed_seconds2.count() << "s\n";

	delete[] a2;
	delete[] b2;

	double** a3 = new double* [length3];
	double** b3 = new double* [length3];
	double** res3 = new double* [length3];

	for (int i = 0; i < length3; i++)
	{
		a3[i] = new double[length3];
		for (int j = 0; j < length3; j++)
		{
			a3[i][j] = (100 + (double)(rand() % 1000)) / 100;
		}

	}

	for (int i = 0; i < length3; i++)
	{
		b3[i] = new double[length3];
		for (int j = 0; j < length3; j++)
		{
			b3[i][j] = (100 + (double)(rand() % 1000)) / 100;
		}

	}

	for (int i = 0; i < length3; i++)
	{
		res3[i] = new double[length3];
		for (int j = 0; j < length3; j++)
		{
			res3[i][j] = 0;
		}
	}

	auto start3 = chrono::steady_clock::now();

	for (int i = 0; i < length3; i++)
	{
		for (int j = 0; j < length3; j++)
		{
			res3[i][j] = 0;
			for (int k = 0; k < length3; k++)
			{
				res3[i][j] += ((a3[i][k]) * (b3[k][j]));
			}
		}
	}

	auto end3 = chrono::steady_clock::now();

	chrono::duration<double> elapsed_seconds3 = end3 - start3;

	cout << "time 3: " << elapsed_seconds3.count() << "s\n";

	delete[] a3;
	delete[] b3;
	system("pause");
	return 0;

}