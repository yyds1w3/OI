#include <iostream>
#include <cstring>
using namespace std;
int a[1001], b[1001], c[1001];
void pluss(int *a, int *b, int *c){
    memset(c, 0, sizeof(int) * 1001);
    for (int i = 0; i < 1001; ++i){
        c[i] += a[i] + b[i];
        if (c[i] >= 10){
            c[i+1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
int sizearr(int *a){
    for (int i = 1000; i >= 0; --i){
        if (a[i] != 0) return i+1;
    }
    return 1;
}

void display(int *a){
    int sz = sizearr(a);
    for (int i = sz - 1; i >= 0; --i){
        cout << a[i];
    }
}
int main(){
    int m, n;
    cin >> m >> n;
    n = n - m + 1;
    a[0] = 1; b[0] = 1;
    for (int i = 3; i <= n; ++i){
        if (i % 3 == 0) pluss(a, b, c);
        else if (i % 3 == 1) pluss(b, c, a);
        else if (i % 3 == 2) pluss(c, a, b);    
    }
    if (n % 3 == 1) display(a);
    if (n % 3 == 2) display(b);
    if (n % 3 == 0) display(c);
    
}