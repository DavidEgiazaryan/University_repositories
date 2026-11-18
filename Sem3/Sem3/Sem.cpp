#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TASK_4

#ifdef TASK_1
#define SIZE 20
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	rand();
	int sum = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand()%201-100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] > 0)
			sum += arr[i];
		else
			break;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d", arr[i]);
		printf("\n");
	}
	printf("%d", sum);
	return 0;
}
#endif

#ifdef TASK_2
#define SIZE 20
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	rand();
	int count = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] % 5 ==0)
			count += 1;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d", arr[i]);
		printf("\n");
	}
	printf("%d", count);
	return 0;
}
#endif

#ifdef TASK_3
#define SIZE 15
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = SIZE - 1; i >= 0; --i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	return 0;
}
#endif

#ifdef TASK_4
#define SIZE 10
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int max_ind = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i)
	{
		if(arr[i]>=arr[max_ind])
		{
			max_ind = i;
		}

	}
	printf("\n");
	printf("%d", arr[max_ind]);
	printf("\n");
	printf("%d", max_ind);
	return 0;
}
#endif

#ifdef TASK_5
#define SIZE 20
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = k; i < SIZE - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}

	arr[SIZE - 1] = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");
	
	return 0;
}
#endif

#ifdef TASK_6
#define SIZE 15
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int  flag = 1;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 10-5;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] < 0)
		{
			flag = 0;
			break;
		};
	}
	if (flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
#endif

#ifdef TASK_7
#define SIZE 15
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int  S = 0;
	scanf("%d", &S);
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100 ;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = i+1; j < SIZE; ++j) 
		{
			if (arr[i] + arr[j] == S)
				printf(" % d / n % d", arr[i], arr[j]);
		}
	}

	return 0;
}
#endif

#ifdef TASK_8
#define SIZE 20
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int  count = 0;;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 1; i < SIZE - 1; ++i)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			count += 1;
	}
	if (arr[0] > arr[1])
		count += 1;
	if (arr[SIZE-1] > arr[SIZE-2])
		count += 1;
	printf("%d", count);
	return 0;
}
#endif


#ifdef TASK_9
#define SIZE 20
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int  count = 1;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 1; i < SIZE ; ++i)
	{
		if (arr[i]!=arr[i-1])
			count += 1;
	}
	printf("%d", count);
	return 0;
}
#endif

#ifdef TASK_10
#define SIZE 15
int main()
{
	int arr[SIZE] = { 0 };
	srand(time(NULL));
	int  max_ind = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	printf("\n");

	for (int i = 1; i < SIZE; ++i)
	{
		if (arr[i] > arr[max_ind])
			max_ind = i;
	}
	printf("%5d%5d", arr[max_ind], max_ind);
	printf("\n");
	for (int i = 1; i < SIZE; ++i)
	{
		if (arr[i] == arr[max_ind])
			arr[i] = 0;
	}
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%5d", arr[i]);
	}
	
	return 0;
}
#endif