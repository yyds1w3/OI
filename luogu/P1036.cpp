#include <iostream>
#include <climits>
using namespace std;
int a[25];
int n, k, ans = 0;

bool isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) return 0;
    }
    return 1;
}

void dfs(int i, int sum, int times){
    if (times == k){
        if (isPrime(sum)){
            ans++;
        }
        return;
    }

    for (int j = i; j <= n - k + 1 + times; ++j){
        dfs(j+1, sum+a[j], times+1);
    }
    return;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans;
}