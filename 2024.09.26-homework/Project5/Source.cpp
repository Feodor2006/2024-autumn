#include<iostream>
int main(int argc, char* argv[])
{
	int l1 = 0;
	int w1 = 0;
	int h1 = 0;
	int l2 = 0;
	int w2 = 0;
	int h2 = 0;
	int lc = 0;
	int wc = 0;
	int hc = 0;
	scanf_s("%d", &l1);
	scanf_s("%d", &w1);
	scanf_s("%d", &h1);
	scanf_s("%d", &l2);
	scanf_s("%d", &w2);
	scanf_s("%d", &h2);
	scanf_s("%d", &lc);
	scanf_s("%d", &wc);
	scanf_s("%d", &hc);
	if ((h1+h2<=hc && (l1<=lc || wc) && (l2<=lc || wc) && (w1<=wc || lc) && (w2<=wc || lc)) || (h1+h2>hc && h1<=hc && h2<=hc && (l1+l2<=lc || wc) && w1<=wc && w2<=wc) || (h1+h2>hc && h1<=hc && h2<=hc && l1<=lc && l2<=lc && (w1+w2<=lc || wc)))
	{
		printf("%s", "YES");
	}
	else
	{
		printf("%s", "NO");
	}
	return EXIT_SUCCESS;
}