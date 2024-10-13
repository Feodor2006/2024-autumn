#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int t = 0;
	int a = 0;
	int b = 0;
	int i = 0;
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf_s("%d", &t);
		if (t > 0)
		{
			++a;
		}
		else
		{
			a = 0;
		}
		if (a > b)
		{
			b = a;
		}
	}
		printf("%d", b);
	return EXIT_SUCCESS;
}