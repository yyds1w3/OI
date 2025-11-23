#include <iostream>
#include <algorithm>
using namespace std;
int h[200001], b[200001];
int main(){
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> h[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort(h+1, h+1+n);
    sort(b+1, b+1+m);
    int ph = 1, pb = 1;
    while (s < k && pb <= m){
        if (h[ph] <= b[pb]){
            s++;
            ph++;
            pb++;
        }else{
            pb++;
        }
    }
    s >= k ? cout << "Yes" : cout << "No";
}