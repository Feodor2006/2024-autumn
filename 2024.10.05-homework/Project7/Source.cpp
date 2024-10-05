#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	if (m % n == 0 || m == n)
	{
		printf("%d", 1);
	}
	if ((m % n != 0) && (m > n))
	{
		printf("%d", n);
	}
	if ((m%n!=0) && (n>m))
	{
		printf("%d", n);
	}
	return EXIT_SUCCESS;
}