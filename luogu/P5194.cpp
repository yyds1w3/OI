#include <iostream>
using namespace std;

int N, C;
long long a[50];
long long p[50];   // 前缀和，用于剪枝
long long ans = 0;  // 当前重量
long long Mans = 0; // 当前最优

void dfs(int i){
    if (ans + p[i] <= Mans){
        return;
    }
    for (int j = i; j >= 1; --j){
        if (ans + a[j] <= C){
            ans += a[j];
            dfs(j-1);
            ans -= a[j];
        }
    }
    Mans = max(Mans, ans);
}

int main(){
    cin >> N >> C;
    for(int i=1; i<=N; ++i){
        cin >> a[i];
        if (a[i] > C){
            N = i - 1;
            break;
        }
        p[i] = p[i-1] + a[i];
    }
    dfs(N);
    cout << Mans;
}
