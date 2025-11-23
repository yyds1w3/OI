#include <iostream>
#include <algorithm>
using namespace std;
int w[101][2];
int main(){
    int x, n, q;
    cin >> x >> n;
    for (int i = 1; i <= n; ++i){
        cin >> w[i][0];
    }
    cin >> q;
    int t;
    for (int i = 1; i <= q; ++i){
        cin >> t;
        if (w[t][1] == 0){
            x += w[t][0];
            w[t][1] = 1;
        }else{
            x -= w[t][0];
            w[t][1] = 0;
        }
        cout << x << endl;
    }

}