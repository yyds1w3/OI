#include <bits/stdc++.h>
using namespace std;

int is_exist(int x, char* s, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (*(s+i) == x)
            return 1;
    }
    return 0;
}

int main()
{
    char s1[] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w', ' '};
    char s2[] = {'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x'};
    char s3[] = {'c', 'f', 'i', 'l', 'o', 'r', 'v', 'y'};
    char s4[] = {'s', 'z'};
    char x;
    int sum = 0;
    while (cin.get(x))
    {
        if (is_exist(x, s1, 9))
            sum += 1;
        else if(is_exist(x, s2, 8))
            sum += 2;
        else if (is_exist(x, s3, 8))
            sum += 3;
        else if(is_exist(x,s4,2))
            sum += 4;
    }
    cout << sum;
}