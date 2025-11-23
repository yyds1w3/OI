#include <iostream>
using namespace std;

long long binary_pow(long long a, long long b, long long p){
    long long result = 1;
    while(b){
        if (b & 1){
            result *= a;
            result %= p;
        }
        a *= a;
        a %= p;
        b >>= 1;
    }
    return result;
}
int main() {
    long long a,b,p;
    cin >> a >> b >> p;
    long long ans = binary_pow(a,b,p);
    printf("%ld^%ld mod %ld=%ld\n", a,b,p,ans);
}
