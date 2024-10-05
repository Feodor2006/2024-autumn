#include<iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int v = 0;
	int s = 0;
	int m = 0;
	int k = 0;
	scanf_s("%d", &n);
	m = -1; k = -1;
	int i = 0;
	for (i = 1; i <= n; ++i)
	{
		scanf_s("%d", &v);
		scanf_s("%d", &s);
		if ((s == 1) && (v > m))
		{
			m = v;
			k = i;
		}
	}
	printf("%d", k);
	return EXIT_SUCCESS;
}