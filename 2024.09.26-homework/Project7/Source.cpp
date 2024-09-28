#include<iostream>
int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	int n1 = 0;
	scanf_s("%d", &k);
	scanf_s("%d", &m);
	scanf_s("%d", &n);
	if (n == 0)
	{
		printf("%d", 0);
	}
	else if (n <= k)
	{
		printf("%d", m * 2);
	}
	else if (n1 = (n * 2 / k))
	{
		printf("%d", n1 * m);
	}
	return EXIT_SUCCESS;
}