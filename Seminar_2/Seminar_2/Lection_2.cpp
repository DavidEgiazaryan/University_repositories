#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define TASK_

#ifdef TASK_1
int main()
{
	int x = -20;
	if (-30 < x && x < -10)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
#endif

#ifdef TASK_2
int main()
{
	int MyVeryVeryVeryFavouriteLongNamedVariable = 10;
	int MyVeryVeryVeryFavouriteLongNameVariable = 10;
	int MyVeryVeryVeryFavouriteLongName2Variable = 10;
	MyVeryVeryVeryFavouriteLongNamedVariable += 5;
	return 0;
}
#endif

#ifdef TASK_3
int main()
{
	int a = 5;
	printf("%d\n", a);
	printf("%d\n", ++a);
	printf("%d\n", a++);
	printf("%d\n", a);
}
#endif

#ifdef TASK_4
int main()
{
	int a = 7;
	printf("%d\n", a > 5 ? a : 5);
	printf("%s\n", a > 5 ? "YES" : "NO");
}
#endif

#ifdef TASK_5
int main()
{
	double a = 0, b = 0, c = 0;
	int n = scanf("%lf%lf%lf", &a, &b, &c);
	if (n != 3)
	{
		printf("Wrong data\n");
		return 0;
	}
	if (a + b > c && a + c > b && b + c > a)
	{
		double p = (a + b + c) / 2;
		printf("Area is %.2lf\n",
			sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	else
	{
		printf("No triangle\n");
		return -1;
	}
	return 0;
}
#endif

#ifdef TASK_6
int main()
{
	double a = 0.0;
	if (a < 10) {
		;
	}
	else if (a > -20)
	{
		;
	}
	else
		;
}
#endif

#ifdef TASK_7
int main()
{
	int month = 0;
	scanf("%d", &month);
	switch (month)
	{

	case 1:
		printf("January\n");
		break;
	case 2:
		printf("Febraury\n");
		break;
	case 3:
		printf("March\n");
		break;
	case 4:
		printf("April\n");
		break;
	case 5:
		printf("May\n");
		break;
	case 6:
		printf("June\n");
		break;
	case 7:
		printf("July\n");
		break;
	case 8:
		printf("August\n");
		break;
	case 9:
		printf("September\n");
		break;
	case 10:
		printf("October\n");
		break;
	case 11:
		printf("November\n");
		break;
	case 12:
		printf("December\n");
		break;
	default:
		printf("Wrong number\n");
		break;
	}
	return 0;
}
#endif

#ifdef TASK_8
int main()
{
	int month = 0;
	scanf("%d", &month);
	switch (month)
	{
	case 1:case 2:case 12:
		printf("Winter\n");
		break;

	case 3:case 4:case 5:
		printf("Spring\n");
		break;

	case 6:case 7:case 8:
		printf("Summer\n");
		break;

	case 9:case 10:case 11:
		printf("Autumn\n");
		break;

	default:
		printf("Wrong number\n");
		break;
	}
	return 0;
}
#endif

#ifdef TASK_9
int main()
{
	double a = 0, b = 0, c = 0;
	//int n = scanf("%lf%lf%lf", &a, &b, &c);
	/*if (n != 3)
	{
		printf("Wrong data\n");
		return 0;
	}*/
	do
	{
		int n = scanf("%lf%lf%lf", &a, &b, &c);
		if (!(a + b > c && a + c > b && b + c > a))
			printf("No triangle\n");
		else
			break;
	} while ('\0');
	double p = (a + b + c) / 2;
	printf("Area is %.2lf\n",
		sqrt(p * (p - a) * (p - b) * (p - c)));


	return 0;
}
#endif

#ifdef TASK_10
int main()
{
	for (int c = 0; c < 256; ++c)
	{
		printf("%2c - %3d\n", c, c);
	}
}
#endif

#ifdef TASK_11
int main()
{
	//for (int i = 0;	i < 10; ++i)
	//{
	//	if (5 == i)
	//		continue;
	//	printf("%d\n", i);
	//}
	int i = 0;
	while (i < 10)
	{
		if (5 == i)
		{
			++i;
			continue;
		}
		printf("%d\n", i++);
	}
}
#endif

#ifdef TASK_12
int main()
{
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			printf("%5d", i * j);
		}
		printf("\n");
	}
}
#endif

#ifdef TASK_14
int main()
{
	double x = 10;
	for (; ;)
		if (x > 0.000005)
			printf("%.10lf\n", x *= 0.012);
		else
			break;
	printf("%.10lf\n", x);
}
#endif