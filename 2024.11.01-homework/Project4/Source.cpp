#include <iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    int a[100] = { 0 };
    int sum_pos = 0;
    int p = 1;
    int min_ind = 0;
    int max_ind = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (a[i] > 0)
            sum_pos += a[i];
        if (a[i] > a[max_ind])
            max_ind = i;
        if (a[i] < a[min_ind])
            min_ind = i;
    }
    for (int i = std::min(min_ind, max_ind) + 1; i < std::max(min_ind, max_ind); ++i)
    {
        p *= a[i];
    }
    std::cout << sum_pos << ' ' << p << std::endl;
    return 0;
}