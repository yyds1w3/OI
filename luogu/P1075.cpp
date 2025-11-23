#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n; 
    cin >> n;
    for (unsigned int i = 3; i <= n; i++){
        if (n % i == 0){
            cout << n / i;
            break;
        }
    }
}