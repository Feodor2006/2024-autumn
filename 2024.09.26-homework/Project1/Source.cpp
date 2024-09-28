#include<iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	if (a == c || b == d || a - c == b - d || c - a == d - b || -(a - c) == b - d || -(c - a) == d - b)
	{
		printf("%s", "YES");
	}
	else
	{
		printf("%s", "NO");
	}
	return EXIT_SUCCESS;
}