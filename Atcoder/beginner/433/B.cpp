#include <iostream>
using namespace std;
int a[101];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        int ans = -1;
        for (int j = 1; j <= i - 1; ++j){
            if (a[j] - a[i] > 0){
                ans = max(j, ans);
            }
        }
        cout << ans << endl;
    }
}