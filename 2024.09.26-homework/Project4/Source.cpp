#include<iostream>
int main(int argc, char* argv[])
{
	int a1 = 0;
	int b1 = 0;
	int c1 = 0;
	int a2 = 0;
	int b2 = 0;
	int c2 = 0;
	scanf_s("%d", &a1);
	scanf_s("%d", &b1);
	scanf_s("%d", &c1);
	scanf_s("%d", &a2);
	scanf_s("%d", &b2);
	scanf_s("%d", &c2);
	if (a1*b1*c1==a2*b2*c2)
	{
		printf("%s", "Boxes are equal");
	}
	else if ((a1 >= a2) && (b1 >= b2) && (c1 >= c2))
	{
		printf("%s", "The first box is larger than the second one");
	}
	else if ((a1 <= a2) && (b1 <= b2) && (c1 <= c2))
	{
		printf("%s", "The first box is smaller than the second one");
	}
	else
	{
		printf("%s", "Boxes are incomparable");
	}
	return EXIT_SUCCESS;
}