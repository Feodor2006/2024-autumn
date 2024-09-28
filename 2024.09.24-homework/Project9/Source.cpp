#include<iostream>
int main(int argc, char* argv[])
{
	int h = 0;
	int a = 0;
	int b = 0;
	scanf_s("%d", &h);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("%d", 1+(h-b-1)/(a-b));
	return EXIT_SUCCESS
}