#include<iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int x = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	for (x = -100; x <= 100; ++x)
	{
		if ((a * x * x * x + b * x * x + c * x + d) == 0)
			printf("%d ", x);
	}
	return EXIT_SUCCESS;
}