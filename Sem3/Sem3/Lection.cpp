#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TASK_

#ifdef TASK_1
#define SIZE 1000
int main()
{
	int arr[SIZE];
	srand(time(NULL));
	rand();
	for (int i = 0; i < SIZE; ++i)
	{
		//scanf("%d", &arr[i]);
		arr[i] = rand() % 201 - 100;
	}
	/*for (int i = 0; i < SIZE; ++i)
	{
		arr[i] *= 10;
	}*/
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");
	return 0;
}
#endif

#ifdef TASK_2
#define SIZE 10 
int main()
{
	double weights[SIZE] = { 0 };
	srand(time(NULL));
	rand();
	for (int i = 0; i < SIZE; ++i)
	{
		weights[i] = rand() * 0.0006;
		//weights[i] = (double)rand() /(rand()+1);
	}
	//double min = weights[0];
	int k = 0;
	for (int i = 1; i < SIZE; ++i)
	{
		if (weights[k] > weights[i])
			k = i;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%7.2lf", weights[i]);
	}
	printf("\nmin at %d\n", k + 1);
	return 0;
}
#endif

#ifdef TASK_3
#define SIZE 36000
#define NUM 11
int main()
{
	int arr[SIZE] = { 0 };
	int stat[NUM] = { 0 };
	srand(time(NULL));
	rand();
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = (rand() % 6 + 1) + (rand() % 6 + 1);
		//arr[i] = rand() % NUM + 2;
		++stat[arr[i] - 2];
	}
	for (int i = 0; i < NUM; ++i)
	{
		printf("%2d - %5d\n", i + 2, stat[i]);
	}
	return 0;
}
#endif

#ifdef TASK_4
#define ROW 2
#define COL 3

int main()
{
	int matrix[ROW][COL] = { 10,20,30,40,50,60 };
	for (int i = 0; i < COL; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			printf("%5d", matrix[j][i]);
		}
		printf("\n");
	}

	int matr[COL][COL] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < COL; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", matr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < COL; ++i)
	{
		printf("%5d", matr[i][i]);
	}
	printf("\n");
	return 0;
}

#endif