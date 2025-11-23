#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    int i = 0, j;
    while (i * (i+1) / 2 < N) i++;
    i -= 1;
    j = N - (i * (i + 1) / 2);
    if (i % 2 != 0){
        cout << j << "/" << 2 + i - j; 
    }else{
        cout << i + 2 - j << "/" << j;
    }
    
}