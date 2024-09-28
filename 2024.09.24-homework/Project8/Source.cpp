#include<iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf_s("%d", &a);
	b = a / 100;
	c = a / 10;
	c = c % 10;
	d = a % 10;
	a = b + c + d;
	printf("%d", a);
	return EXIT_SUCCESS;
}