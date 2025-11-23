#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long fastpow(long long a, long long b)
{
    long long result = 1;
    while (b)
    {
        if (b & 1)
        {
            result *= a;
        }
        a *= a;
        b >>= 1;
    }
    return result;
}

int main()
{
    string s;
    long long N;
    int t;
    cin >> s >> N;
    int sz = s.size();
    while (true)
    {
        if (N > sz)
            t = log2((N - 1) / sz);
        else
            break;
        N = (N - 1) % (sz * fastpow(2, t));
        if (N == 0) N += sz * fastpow(2,t);
    }
    cout << s.at(N - 1);
}