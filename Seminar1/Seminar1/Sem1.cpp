#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define Task_1

#ifdef Task_1
int main()

{
	double r = 0, h = 0;
	printf("Enter radius and height\n");
	scanf("%lf%lf", &r, &h);
	printf("volume is %lf", M_PI * r * r * h);
}
#endif

#ifdef Task_2
int main()

{
	double r = 0, h = 0;
	printf("Enter radius and height\n");
	scanf("%lf%lf", &r, &h);
	printf("are is %lf", 2*M_PI*r*r + 2*M_PI*r*h);
}
#endif

#ifdef Task_3
int main()

{
	int m = 0;
	printf("Enter minutes\n");
	scanf("%d", &m);
	printf("time is %d hours and %d minutes", m/60, m%60);
}
#endif

#ifdef Task_4
int main()

{
	double f = 0;
	printf("Enter ft\n");
	scanf("%lf", &f);
	printf("weight is %.3lf kg", f*0.4059);
}
#endif

#ifdef Task_5
int main()

{
	double U = 0, R = 0;
	printf("Enter U and R\n");
	scanf("%lf%lf", &U, &R);
	printf("I is %.2lf", U / R);
}
#endif

#ifdef Task_6
int main()

{
	double weight = 0, cost = 0;
	printf("Enter weight in kg and cost\n");
	scanf("%lf%lf", &weight, &cost);
	printf("price is %.2lf rubles",weight/0.1*cost);
}
#endif

#ifdef Task_7
int main()

{
	double l = 0, w = 0;
	printf("Enter lenth and width\n");
	scanf("%lf%lf", &l, &w);
	printf("area is %.2lf", l*w);
}
#endif

#ifdef Task_8
int main()

{
	double weight = 0, cost = 0;
	printf("Enter weight in kg and cost\n");
	scanf("%lf%lf", &weight, &cost);
	printf("price is %.2lf rubles", weight  * cost);
}
#endif

#ifdef Task_9
int main()

{
	double dist = 0, benz = 0;
	printf("Enter dist, benz\n");
	scanf("%lf%lf", &dist, &benz);
	printf("total cost is %lf rubles", 2*(benz/100*dist));
}
#endif

#ifdef Task_10
int main()

{
	double a = 0, b = 0, c=0;
	printf("Enter a,b,c\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("volume is %lf", a*b*c);
}
#endif