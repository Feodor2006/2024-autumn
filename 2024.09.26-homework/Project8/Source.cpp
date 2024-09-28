#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	if (n == 1 && m==1)
	{
		printf("%d", 1*4);
	}
	else if (n == 1)
	{
		printf("%d", m * 4);
	}
	else if (m==1)
	{
		printf("%d", n*4);
	}
	else
	{
		printf("%d", n * 4 + m * 4);
	}
	return EXIT_SUCCESS;
}