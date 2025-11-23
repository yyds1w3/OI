#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int a[10001]; // n!
int b[10001]; // s

void init(string s, int *a){
    int sz = s.size(); 
    for (int i = 1; i <= sz; ++i){
        a[sz-i] = s.at(i);
    }
}

int size_array(int *a){
    int i = 10001;
    while (a[i] == 0){
        i--;
    }
    return i+1;
    
}
void add(int *a, int *b){
    for (int i = 0; i < 10001; ++i){
        a[i] += b[i];
        if (a[i] >= 10){
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
    }

}

void mult_int(int *a, int b){
    for (int i = 0; i < 10000; ++i){
        a[i] *= b;
    }
    for (int i = 0; i < 10000; ++i){
        if (a[i] >= 10){
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
    }
}

void display(int *a){
    int i = size_array(a);
    for (int j = i - 1; j >= 0; --j){
        cout << a[j];
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; ++i){
        mult_int(a, i);
        add(b, a);
    }
    display(b);
}