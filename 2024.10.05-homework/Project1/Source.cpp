#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int k1 = 0;
	int k2 = 0;
	int i = 0;
	scanf_s("%d", &n);
	int b = 0;
	for (i = 1; i <= n; ++i)
	{
		scanf_s("%d", &b);
		if (b == 1)
			++k2;
		if (b == 0)
			++k1;
	}
	if (k1>k2)
		printf("%d", k2);
	if (k2>=k1)
		printf("%d", k1);
	return EXIT_SUCCESS;
}