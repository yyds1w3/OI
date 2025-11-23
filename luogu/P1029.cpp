#include <iostream>

using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i){
        if (a * b % i == 0 && gcd(i, a * b / i) == a){
            ans++;
        }
    }
    cout << ans;
}