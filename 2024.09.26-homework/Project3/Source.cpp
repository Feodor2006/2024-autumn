#include<iostream>
int main(int argc, char* argv[])
{
	int x1 = 0;
	int y1 = 0;
	int r1 = 0;
	int x2 = 0;
	int y2 = 0;
	int r2 = 0;
	int l = 0;
	scanf_s("%d", &x1);
	scanf_s("%d", &y1);
	scanf_s("%d", &r1);
	scanf_s("%d", &x2);
	scanf_s("%d", &y2);
	scanf_s("%d", &r2);
	l = sqrt((x1 - x2)*(x1-x2) + (y1 - y2)*(y1-y2));
	if (l > r1 + r2)
	{
		printf("%s", "NO");
	}
	else if (l <= r1 + r2)
	{
		printf("%s", "YES");
	}
	return EXIT_SUCCESS;
}