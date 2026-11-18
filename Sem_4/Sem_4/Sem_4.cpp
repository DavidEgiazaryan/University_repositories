#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TASK_6

#ifdef TASK_1

int main()
{
#define ROW 10
#define COL 10
#define SQUARE_SIZE 2

	int arr[ROW][COL] = { 0 };
	srand(time(NULL));
	rand();
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] = rand() % 101;
		}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i <= ROW - SQUARE_SIZE; ++i) {
		for (int j = 0; j <= COL - SQUARE_SIZE; ++j) {
			int sum = 0;
			for (int si = 0; si < SQUARE_SIZE; ++si) {
				for (int sj = 0; sj < SQUARE_SIZE; ++sj) {
					sum += arr[i + si][j + sj];
				}
			}
			printf(" sum = %d\n", sum);
		}
	}
	return 0;
}
#endif

#ifdef TASK_2

int main()
{
#define ROW 5
#define COL 12
	int arr[ROW][COL] = { 0 };
	int minj = 0;
	int maxdiff;
	srand(time(NULL));
	rand();
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] = rand() % 101;
		}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	int maxi_first = 0;
	int mini_first = 0;
	for (int i = 0; i < ROW; ++i) {
		if (arr[i][0] < arr[mini_first][0])
			mini_first = i;
		if (arr[i][0] > arr[maxi_first][0])
			maxi_first = i;
	}
	maxdiff = arr[maxi_first][0] - arr[mini_first][0];

	for (int j = 0; j < COL; ++j) {
		int maxi = 0;
		int mini = 0;
		for (int i = 0; i < ROW; ++i) {
			if (arr[i][j] < arr[mini][j])
				mini = i;
			if (arr[i][j] > arr[maxi][j])
				maxi = i;
		}
		int diff = arr[maxi][j] - arr[mini][j];
		if (diff < maxdiff) {
			minj = j;
			maxdiff = arr[maxi][j] - arr[mini][j];
		}
	}
	printf("%d", minj+1);
	return 0;
}
#endif

#ifdef TASK_3

int main()
{
#define ROW 9
#define COL 9
	int arr[ROW][COL] = { 0 };
	srand(time(NULL));
	rand();
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] = rand() % 101;
		}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	int maxc = 0;
	int popular = arr[0][0];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < ROW; j++) {
			int k = 0;
			for (int a = 0; a < ROW; a++) {
				for (int b = 0; b < ROW; b++) {
					if (arr[i][j] == arr[a][b])
						k++;
				}
			}
			if (k > maxc) {
				maxc = k;
				popular = arr[i][j];
			}

		}
	}

	printf("most popular - %d %d times",popular,maxc);
	return 0;
}
#endif

#ifdef TASK_4

int main()
{
#define ROW 9
#define COL 9
	int arr[ROW][COL] = { 0 };
	srand(time(NULL));
	rand();
	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] = rand() % 201-100;
		}
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	int flag = 1;

	for (int i = 0; i < ROW-1; ++i) {
		for (int j = 0; j < COL - 1; ++j) {

			if ((arr[i][j] > 0 && arr[i + 1][j + 1] < 0) || (arr[i][j] < 0 && arr[i + 1][j + 1] > 0))
			{
				printf("%d", i+1);
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	return 0;
}
#endif

#ifdef TASK_5

int main()
{
#define ROW 7
#define COL 7
	int arr[ROW][COL] = { 0 };
	srand(time(NULL));

	for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] = rand() % 11; 
		}

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	int max_len_final = 1; 
	int best_row = 0;

	for (int i = 0; i < ROW; ++i) {
		int current_len = 1;

		for (int j = 1; j < COL; ++j) {
			if (arr[i][j] == arr[i][j - 1]) {
				current_len+=1;
			}
			else {
				if (current_len > max_len_final) {
					max_len_final = current_len;
					best_row = i;
				}
				current_len = 1;
			}
		}

		if (current_len > max_len_final) {
			max_len_final = current_len;
			best_row = i;
		}
	}

	
	printf("%d %d", max_len_final, best_row);
	  return 0;
}
#endif

#ifdef TASK_6

#define SIZE 8
#define COUNT_MATRIX 3
#define RAND_NUM 5

srand(time(NULL));
rand();

int matrixs[COUNT_MATRIX][SIZE][SIZE] = { 0 };
for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrixs[index_matrix][i][j] = rand() % RAND_NUM;
			printf("%3d", matrixs[index_matrix][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
for (int index_stolbec = 0; index_stolbec < SIZE; index_stolbec++)
{
	int max_elements[COUNT_MATRIX] = { 0 };
	for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
	{
		int max_elem_in_stolbec = matrixs[index_matrix][0][index_stolbec];
		for (int index_stroka = 0; index_stroka < SIZE; index_stroka++)
		{
			if (max_elem_in_stolbec < matrixs[index_matrix][index_stroka][index_stolbec])
				max_elem_in_stolbec = matrixs[index_matrix][index_stroka][index_stolbec];
		}
		max_elements[index_matrix] = max_elem_in_stolbec;
	}
	if (max_elements[0] == max_elements[1] and max_elements[1] == max_elements[2])
		printf("index - %2d, max element - %2d\n", index_stolbec, max_elements[0]);
}
#endif

#ifdef TASK_7

#define SIZE 12
#define COUNT_MATRIX 3
#define RAND_NUM 50

srand(time(NULL));
rand();

int matrixs[COUNT_MATRIX][SIZE][SIZE] = { 0 };
for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrixs[index_matrix][i][j] = rand() % RAND_NUM;
			printf("%3d", matrixs[index_matrix][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int min_temp[SIZE] = { 0 };
for (int index_stolbec = 0; index_stolbec < SIZE; index_stolbec++)
{
	int min_elem_in_stolbec = matrixs[0][0][index_stolbec];
	for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
	{
		for (int index_stroka = 0; index_stroka < SIZE; index_stroka++)
		{
			if (min_elem_in_stolbec > matrixs[index_matrix][index_stroka][index_stolbec])
				min_elem_in_stolbec = matrixs[index_matrix][index_stroka][index_stolbec];
		}
	}
	min_temp[index_stolbec] = min_elem_in_stolbec;
}
for (int j = 0; j < SIZE; j++)
{
	printf("%3d", min_temp[j]);
}
printf("\n");
#endif

#ifdef TASK_8

#define SIZE_STR 9
#define SIZE_STB 12
#define COUNT_MATRIX 3
#define RAND_NUM 100

srand(time(NULL));
rand();

int matrixs[COUNT_MATRIX][SIZE_STR][SIZE_STB] = { 0 };
int srednee[COUNT_MATRIX] = { 0 };
for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
{
	int srednee_matrix = 0;
	for (int i = 0; i < SIZE_STR; i++)
	{
		for (int j = 0; j < SIZE_STB; j++)
		{
			matrixs[index_matrix][i][j] = rand() % RAND_NUM;
			srednee_matrix += matrixs[index_matrix][i][j];
			printf("%4d", matrixs[index_matrix][i][j]);
		}
		printf("\n");
	}
	printf("\n");
	srednee[index_matrix] = srednee_matrix / (SIZE_STR * SIZE_STB);
}
int* days = NULL;
int good_days = 0;
for (int day = 0; day < SIZE_STB; day++)
{
	int flag = 1;
	for (int m = 0; m < COUNT_MATRIX; m++)
	{
		int upper = 0;
		for (int row = 0; row < SIZE_STR; row++)
		{
			if (matrixs[m][row][day] > srednee[m])
			{
				upper = 1;
				break;
			}
		}

		if (!upper)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		good_days++;
		if (good_days == 1)
			days = (int*)malloc(sizeof(int));
		else
			days = (int*)realloc(days, good_days * sizeof(int));
		days[good_days - 1] = day + 1;
	}
}
if (good_days > 0)
{
	printf("Days: ");
	for (int i = 0; i < good_days; i++)
		printf("%d ", days[i]);
	printf("\n");
}
else
printf("No such days\n");
free(days);
#endif

#ifdef TASK_9

#define SIZE_STR 8
#define SIZE_STB 20
#define COUNT_MATRIX 3
#define RAND_NUM 100

srand(time(NULL));

int matrixs[COUNT_MATRIX][SIZE_STR][SIZE_STB] = { 0 };
for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
{
	for (int i = 0; i < SIZE_STR; i++)
	{
		for (int j = 0; j < SIZE_STB; j++)
		{
			matrixs[index_matrix][i][j] = rand() % RAND_NUM;
			printf("%4d", matrixs[index_matrix][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int* days = NULL;
int good_days = 0;
for (int day = 0; day < SIZE_STB; day++)
{
	int max_food = matrixs[1][0][day];
	int min_danger = matrixs[0][0][day];
	int has_water = 0;
	for (int i = 0; i < SIZE_STR; i++)
	{
		if (matrixs[0][i][day] < min_danger)
			min_danger = matrixs[0][i][day];
		if (matrixs[1][i][day] > max_food)
			max_food = matrixs[1][i][day];
		if (matrixs[2][i][day] > 0)
			has_water = 1;
	}
	int has_max_food = 0;
	for (int i = 0; i < SIZE_STR; i++)
	{
		if (matrixs[1][i][day] == max_food)
		{
			has_max_food = 1;
			break;
		}
	}
	int has_min_danger = 0;
	for (int i = 0; i < SIZE_STR; i++)
	{
		if (matrixs[0][i][day] == min_danger)
		{
			has_min_danger = 1;
			break;
		}
	}
	if (has_max_food and has_min_danger and has_water)
	{
		good_days++;
		if (good_days == 1)
		{
			days = (int*)malloc(sizeof(int));
		}
		else
		{
			days = (int*)realloc(days, good_days * sizeof(int));
		}
		days[good_days - 1] = day + 1;
	}
}
printf("Days: ");
for (int i = 0; i < good_days; i++)
{
	printf("%d ", days[i]);
}
printf("\n");
free(days);
#endif

#ifdef TASK_10

#define SIZE 9
#define COUNT_MATRIX 3
#define RAND_NUM 100

srand(time(NULL));

int matrixs[COUNT_MATRIX][SIZE][SIZE] = { 0 };
for (int index_matrix = 0; index_matrix < COUNT_MATRIX; index_matrix++)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrixs[index_matrix][i][j] = rand() % RAND_NUM;
			printf("%4d", matrixs[index_matrix][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int max_sum = 0;
for (int week = 0; week < SIZE; week++)
{
	int honey = 0;
	for (int i = 0; i < SIZE; i++)
	{
		honey += matrixs[0][i][week] + matrixs[1][i][week];
	}
	if (honey > max_sum)
		max_sum = honey;
}
int* weeks = NULL;
int good_weeks = 0;
int dance_threshold = rand() % RAND_NUM;
for (int week = 0; week < SIZE; week++)
{
	int honey = 0;
	int max_dance = 0;
	for (int i = 0; i < SIZE; i++)
	{
		honey += matrixs[0][i][week] + matrixs[1][i][week];
		if (matrixs[2][i][week] > max_dance)
			max_dance = matrixs[2][i][week];
	}

	if (honey == max_sum && max_dance <= dance_threshold)
	{
		good_weeks++;
		if (good_weeks == 1)
		{
			weeks = (int*)malloc(sizeof(int));
		}
		else
		{
			weeks = (int*)realloc(weeks, good_weeks * sizeof(int));
		}
		weeks[good_weeks - 1] = week + 1;
	}
}
printf("Weeks: ");
for (int i = 0; i < good_weeks; i++)
{
	printf("%d ", weeks[i]);
}
printf("\n");
free(weeks);
#endif


