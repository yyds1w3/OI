#include <iostream>

using namespace std;
int a[200001];
int b[200001];
int ta = 0, tb = 0;
int sa = 0, sb = 0;
int main(){
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;
        for (int j = 1; j <= n ;++j){
            cin >> a[j];
        }
        for (int j = 1; j <= n ;++j){
            cin >> b[j];
        }
        for (int j = 1; j <= n; ++j){
            if (j % 2 == 1 && a[j] != b[j]){
                ta = j;
            }
            if (j % 2 == 0 && a[j] != b[j]){
                tb = j;
            }
            sa xor_eq a[j];
            sb xor_eq b[j];
        }   

        if (ta > tb && sa != sb){
            cout << "Ajisai" << endl;
        }else if (ta < tb && sa != sb){
            cout << "Mai" << endl;
        }else{
            if (sa == sb)
                cout << "Tie" << endl;
            else{
                sa > sb ? cout << "Ajisai" << endl : cout << "Mai" << endl;
            }
        }
        ta = tb = sa = sb = 0;
    }
}  