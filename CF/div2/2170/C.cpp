#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 1;
typedef long long ll;
ll A[N], B[N];
int main(){
    int t, n;
    ll k;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> A[i];
        }
        for (int i = 1; i <= n; ++i){
            cin >> B[i];
        }
        sort(A+1, A+n+1);
        sort(B+1, B+n+1);
        int l = 1, r = n;
        int ans = 0;
        while (l <= n && r >= 1){
            if ((B[r] + 1) * A[l] + B[r] <= k){
                ans++;
                l++;
                r--;
            }else{
                r--;
            }
        }
        cout << ans << endl;     
        memset(A+1, 0, n * sizeof(int));
        memset(B+1, 0, n * sizeof(int));
    }
}