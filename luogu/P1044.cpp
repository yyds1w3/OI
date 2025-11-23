#include <bits/stdc++.h>
using namespace std;

long long g[25][25]; // push <= 20

int main(){
    int n;
    cin >> n;
    g[0][0] = 1;
    for(int p = 0; p <= n; p++){
        for(int q = 0; q <= n; q++){
            if(p > 0) // 至少push过1次
                g[p][q] += g[p-1][q];     // push
            if(q > 0 && q <= p) // 至少pop过一次，pop的次数<= p,非空栈
                g[p][q] += g[p][q-1];     // pop
        }
    }

    cout << g[n][n] << endl;
}
