#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define TASK_6

#ifdef TASK_1
int main()
{
	printf("Hello, world!\n");
	return 0;
}
#endif

#ifdef TASK_2
int main()
{
	printf("Enter 2 numbers\n");
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("Summa is %d\n", a+b);
	return 0;
}
#endif

#ifdef TASK_3
int main()
{
	printf("Enter 2 numbers\n");
	double a = 0, b = 0;
	scanf("%lf%lf", &a, &b);
	printf("Summa is %.2lf\n", a + b);
	return 0;
}
#endif

#ifdef TASK_4
int main()
{
	printf("Enter 2 numbers\n");
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("Chast is %d\n", a / b);
	return 0;
}
#endif

#ifdef TASK_5
int main()
{
	double radius = 0;
	scanf("%lf", &radius);
	printf("%lf", 4.0 / 3 * M_PI * pow(radius,3));
	return 0;
}
#endif

#ifdef TASK_6
int main()
{
	printf("Enter 2 numbers\n");
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("Ostat is %d\n", a % b);
	return 0;
}
#endif