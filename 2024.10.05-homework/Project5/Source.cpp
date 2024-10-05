#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int i = 0;
	int j = 0;
	int b = 0;
	int z = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
		{
			scanf_s("%d", &b);
			z += b;
		}
	printf("%d", z / 2);
	return EXIT_SUCCESS;
}