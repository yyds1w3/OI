#include <iostream>
#include <cmath>
using namespace std;

void f(int x){
    int flag = 0;
    while (x){
        int t = log2(x);
        if (flag) cout << "+";
        if (t == 1){
            cout << "2";
        }else if(t == 0){
            cout << "2(0)";
        }else{
            cout << "2(";
            f(t);
            cout << ")";
        }
        x -= pow(2, t);
        flag = 1;
        
    }
}

int main(){
    int n;
    cin >> n;
    f(n);
    return 0;

}