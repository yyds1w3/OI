#include <iostream>
using namespace std;

int a[200000];

long long ans = 0;
int main(){
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;
        for (int j = 0; j < n; ++j){
            cin >> x;
            if (j != 0 && j != n-1 && x == -1) x = 0; 
            a[j] = x;
        }
        if (a[0] == -1 && a[n-1] != -1){
            ans = 0;
            a[0] = a[n-1];
        }else if (a[n-1] == -1 && a[0] != -1){
            ans = 0;
            a[n-1] = a[0];
        }else if (a[n-1] == -1 && a[0] == -1){
            ans == 0;
            a[n-1] = a[0] = 0;
        }{
            ans = abs(a[n-1] - a[0]);
        }
        cout << ans << endl;
        for (int j = 0; j < n; ++j){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}