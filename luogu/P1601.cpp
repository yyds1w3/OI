#include <iostream>
using namespace std;

int a[501], b[501];

int sizearr(int *a){
    for (int i = 500; i>= 0; --i){
        if (a[i] != 0){
            return i+1;
        }
    }
    return 1;
}
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    for (int i = 0 ; i<=sz-1; ++i){
        a[i] = s[sz-1 - i] - '0';
    }
    cin >> s;
    sz = s.size();
    for (int i = 0; i<=sz-1; ++i){
        b[i] = s[sz-1 - i] - '0';
    }

    for (int i = 0; i < 500; ++i){
        a[i] += b[i];
        if (a[i] >= 10){
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
    }

    for (int i = sizearr(a) - 1; i >= 0; --i){
        cout << a[i];
    }

}
