#include <iostream>
using namespace std;
int tong[1001];
int main(){
    int n, x, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        tong[x]++;
        if (tong[x] == 1) ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= 1000; ++i){
        if (tong[i] > 0){
            cout << i << " ";
        }
    }
}