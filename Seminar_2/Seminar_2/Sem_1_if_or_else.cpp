#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define TASK_10

#ifdef TASK_1
int main()
{
	double x = 0;
	printf("Enter number\n");
	scanf("%lf", &x);
	if (10 <= x && x <= 100)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
#endif

#ifdef TASK_2
int main()
{
	int x = 0;
	printf("Enter number\n");
	scanf("%d", &x);
	if (x/100 == x%10)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
#endif

#ifdef TASK_3
int main()
{
	int x = 0 , y=0 , z=0;
	printf("Enter numbers\n");
	scanf("%d%d%d", &x, &y, &z);
	int count_otriz = 0;
	if (x < 0)
		count_otriz +=1;
	if (y < 0)
		count_otriz += 1;
	if (z < 0)
		count_otriz += 1;
	if (count_otriz % 2 == 0)
		printf("Polozhitelnoe\n");
	else
		printf("Otricatelnoe\n");
	return 0;
}
#endif

#ifdef TASK_4
int main()
{
	int x = 0;
	printf("Enter number\n");
	scanf("%d", &x);
	if (x % 5 == 0)
		printf("Cratone\n");
	else
		printf("NE cratnoe\n");
	return 0;
}
#endif

#ifdef TASK_5
int main()
{
	int lang = 0;
	scanf("%d", &lang);
	switch (lang)
	{

	case 1:
		printf("Russian\n");
		break;
	case 2:
		printf("English\n");
		break;
	default:
		printf("Unknown language\n");
		break;
	}
	return 0;
}
#endif

#ifdef TASK_6
int main()
{
	double x = 0, y = 0;
	scanf("%lf%lf", &x, &y);
	if (x > 0 && y > 0)
		printf("I quater");
	if (x < 0 && y > 0)
		printf("II quater");
	if (x < 0 && y < 0)
		printf("III quater");
	if (x > 0 && y < 0)
		printf("IV quater");
	if (x == 0 && y == 0)
		printf("centre");
	if (x == 0 || y == 0)
		printf(" Na Osi");
}
#endif

#ifdef TASK_7
int main()
{
	int x = 0;
	printf("Enter number\n");
	scanf("%d", &x);
	if ((x % 2 == 0 && x >= 100 && x < 1000) || (x % 2 == 0 && x > -1000 && x <= -100))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
#endif

#ifdef TASK_8
int main()
{
	int x = 0, y = 0;
	printf("Enter numbes\n");
	scanf("%d%d", &x, &y);
	if (x % 10 == y % 10)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
#endif

#ifdef TASK_9
int main()
{
	int assesment = 0;
	scanf("%d", &assesment);
	switch (assesment)
	{

	case 0:case 1:case 2:case 3:
		printf("2\n");
		break;
	case 4:case 5:
		printf("3\n");
		break;
	case 6:case 7:
		printf("4\n");
		break;
	case 8:case 9: case 10:
		printf("5\n");
		break;
	default:
		printf("Unknown assesment\n");
		break;
	}
	return 0;
}
#endif

#ifdef TASK_10
int main()
{
	double x = 0;
	printf("Enter numbe\n");
	scanf("%lf", &x);
	if ((x>=0 && x<=10) || (x >= 20 && x <= 30))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
#endif