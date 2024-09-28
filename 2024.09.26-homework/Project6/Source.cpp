#include<iostream>
#include<math.h>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if ((a==0) && (b==0) && (c==0))
	{
		printf("%d", -1);
	}
	else if ((a==0) && (b==0))
	{
		printf("%d", 0);
	}
	else if (a==0)
	{
		printf("%d", 1); printf("%d", -c / b);
	}
	d = b * b - 4 * a * c;
	if (d < 0)
	{
		printf("%d", 0);
	}
	else if (d == 0)
	{
		printf("%d", 1); printf("%d", -b / 2 * a);
	}
	else if (d > 0)
	{
		d = sqrt(d);
		printf("%d", 2); printf("%d", (-b - d) / (2 * a)); printf("%d", (-b + d) / (2 * a));
	}
	return EXIT_SUCCESS;
}