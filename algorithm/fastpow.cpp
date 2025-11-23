#include <random>
#include <iostream>

long long fastpow(int a, unsigned int n)
{
    if (n == 0)
        return 1;
    long long half = fastpow(a, n / 2);
    if (n % 2 == 0 && n > 0)
        return half * half;
    if (n % 2 == 1 && n > 0)
        return half * half * a;
    return 0;
}

int main()
{
    long long c = fastpow(2, 7);
    std::cout << c << " " << (-9 % 8);
    std::uniform_real_distribution();
}