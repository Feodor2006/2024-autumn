#include<iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int i = 0;
	int max = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	{
		if (a > b)
		{
			max = a;
		}
		if (a < b)
		{
			max = b;
		}
	}
	for (i = max; i <= (a * b); i += max)
		if ((i % a == 0) && (i % b == 0))
		printf("%d", i);
	return EXIT_SUCCESS;
}