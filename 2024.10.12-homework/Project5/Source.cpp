#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int x = 0;
	int i = 0;
	int a[1000] = { 0 };
	int k = 0;
	scanf_s("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	{
		scanf_s("%d", &x);
	}
	k = a[0];
	for (i = 0; i <= n; ++i)
	{
		if (abs(a[i] - x) < abs(k - x) || abs(a[i] - x) == abs(k - x) && a[i] < k)
		{
			k = a[i];
		}
	}
	printf("%d", k);
	return EXIT_SUCCESS;
}