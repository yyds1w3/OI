#include <iostream>
#include <cmath>
using namespace std;
long long ans = 0;
int main() {
    for (int i = 1; i <= 114; ++i){
        for (int j = 1; j <= 514; ++j){
            if (i*i/114.0/114.0 + j*j/514.0/514.0 < 1) 
                ans++;
        }
    }
    cout << 4 * ans + 2*113+1 + 2*513+1 - 1;
}
