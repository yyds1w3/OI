#include <iostream>
using namespace std;
int f[1001];
int main(){
    f[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= i / 2; ++j)
            f[i] += f[j];
    }
    cout << f[n];
}