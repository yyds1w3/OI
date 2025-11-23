#include <iostream>
using namespace std;
long long ans = 0;
int main(){
    for (int i = 1; i < 350235; ++i){
        int t = i;
        while (i){
            if (i % 10 == 7){
                ans += t;
                i = t;
                break;
            }
            i /= 10;
        }
        i = t;
    }
    cout << ans;
}