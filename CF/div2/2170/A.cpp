// p + p - n + p - 1 + p + 1 + p + n

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5;
int n, t;
ll A[N];
ll ans, MaxAns;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        for (int j = 1; j <= n * n; ++j){
            A[j] = j;
        }
        for (int j = 1; j <= n * n; ++j){
            ans = A[j];
            if (j % n != 1)
                ans += A[j-1];
            if (j % n != 0)
                ans += A[j+1];
            if (j / n != 0)
                ans += A[j - n];
            if (j / n != n - 1)
                ans += A[j + n];
            MaxAns = max(ans, MaxAns);
        }
        cout << MaxAns << endl;

    }
}   





