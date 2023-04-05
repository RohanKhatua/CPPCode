#include <iostream>

int solve(int a, int m, double n)
{
    double x;
    x = ((m * n) - a - m) / (1 - n);
    std::cout << x;
}

int main()
{
    try
    {
        int test;
        std::cin >> test;
        if (!std::cin || test < 1 || test > 150)
            throw -1;
        for (int t = 0; t < test; t++)
        {
            long long a, m;
            double n;
            std::cin >> a >> m >> n;
            if (a < 1 || a > 100000 || m < 1 || m > 100000 || n <= 0 || n == 1 || n > 100000)
                throw -2;
            solve(a, m, n);
        }
    }
    catch (...)
    {
        std::cout << "Invalid input. Please check the question description.\n";
    }
    return 0;
}