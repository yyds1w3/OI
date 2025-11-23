#include <iostream>
using namespace std;
int main(){
    int n, a = 0, b, c, s = 0, d, t;
    cin >> n;
    cin >> a >> b;
    d = b - a;
    for (int i = 2; i < n; ++i){
        cin >> c;
        if (d != 0)
            t = d;
        d = c - b;
        if (t * d < 0 && t < d) s++;
        a = b;
        b = c;
    }
    cout << s;
}