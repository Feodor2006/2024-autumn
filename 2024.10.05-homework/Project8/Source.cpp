#include<iostream>
int main(int argc, char* argv[])
{
    int i = 0;
    int j = 0;
    scanf_s("%d", &i);
    scanf_s("%d", &j);
    int swap_i = i;
    int swap_j = j;
    while (swap_j != 0)
    {
        int z = swap_j;
        swap_j = swap_i % swap_j;
        swap_i = z;
    }
    int f0 = 1;
    int f1 = 1;
    int f = 0;
    for (int k = 2; k < swap_i; ++k)
    {
        f = (f0 + f1) % 1000000000;
        f0 = f1;
        f1 = f;
    }
    printf("%d", f1);
    return EXIT_SUCCESS;
}