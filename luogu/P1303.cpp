#include <iostream>
using namespace std;
const int N = 2000;
int a[N], b[N], c[N*2];

int sizearr(int *arr, int len){
    for(int i = len-1; i >= 0; --i)
        if(arr[i] != 0) return i+1;
    return 1;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int sa = s1.size(), sb = s2.size();

    for(int i = 0; i < sa; ++i) a[i] = s1[sa-1-i]-'0';
    for(int i = 0; i < sb; ++i) b[i] = s2[sb-1-i]-'0';

    // 大整数乘法
    for(int i = 0; i < sa; ++i)
        for(int j = 0; j < sb; ++j)
            c[i+j] += a[i]*b[j];

    // 进位处理
    for(int i = 0; i < sa+sb; ++i){
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }

    int len = sizearr(c, sa+sb+1);
    for(int i = len-1; i >= 0; --i) cout << c[i];
    cout << endl;
}
