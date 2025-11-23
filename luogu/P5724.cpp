#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    array<int, 100> arr = {0};
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        arr[i] = x;
    }
    sort(arr.begin(), arr.begin() + n);
    cout << *(arr.begin() + n - 1) - *arr.begin();
}