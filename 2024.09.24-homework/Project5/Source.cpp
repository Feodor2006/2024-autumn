#include<iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	scanf_s("%d", &a);
	printf("%s %d %s %d \n", "The next number for the number", a, "is", a + 1);
	printf("%s %d %s %d", "The previous number for the number", a, "is", a - 1);
	return EXIT_SUCCESS;
}