#include <iostream>
#include <algorithm>
using namespace std;
int a[4];
int b[4];
int main(){
    a[0] = a[1] = a[2] = 243;
    a[3] = 486;
    for (int i = 0; i < 4; ++i){
        b[0] = a[3] * 2 / 3 + a[1] / 3;
        b[1] = a[0] * 2 / 3 + a[2] / 3;
        b[2] = a[1] * 2 / 3 + a[3] / 3;
        b[3] = a[2] * 2 / 3 + a[0] / 3;
        for (int j = 0; j < 4; ++j){
            a[j] = b[j];
        }
    }
    int p = a[3] / __gcd(a[3], 243);
    int q = 243 / __gcd(a[3], 243);
    cout << p + q;

}