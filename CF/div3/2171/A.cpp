#include <iostream>
using namespace std;
int a[101];
int b[101];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 0; 2 * j <= a[i]; ++j){
            if ((a[i] - 2 * j) % 4 == 0){
                b[i]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << b[i] << endl;
    }
}