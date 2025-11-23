#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[3];
bool b[10] = {0};
int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    bool flag = 0;
    int j, k;
    for (int i = 100; i <= 999; ++i){
        if (a[0] == 0 || a[1] == 0 || a[2] == 0) break;
        if (i % a[0] == 0) j = i * a[1] / a[0]; 
        else continue;
        if (j % a[1] == 0) k = j * a[2] / a[1]; 
        else continue;
        if (k >= 1000) continue;
        int tpi = i, tpj = j, tpk = k;
        for (int l = 1; l <= 3; ++l){
            b[i % 10] = 1, b[j % 10] = 1; b[k % 10] = 1;
            i /= 10, j /= 10, k /= 10;
        }
        i = tpi, j = tpj, k = tpk;
        if (b[1] & b[2] & b[3] & b[4] & b[5] & b[6] & b[7] & b[8] & b[9]){
            cout << i <<" " << j <<" " << k;
            flag = 1;
            cout << endl;
        }
        memset(b, 0, sizeof(b));
    }
    if (!flag) cout << "No!!!";
}