#include <iostream>
#include <cstring>
using namespace std;
int a[200001][30];
int b[200001][30];
int ta = 0, tb = 0;
int sa = 0, sb = 0;
int x, k = 0;
int main(){
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;
        for (int j = 1; j <= n ;++j){
            memset(a[j] ,0,sizeof(a[j]));
            cin >> x;
            while(x){
                a[j][k++] = x & 1;
                x >>= 1;
            }
            k = 0;
        }
        for (int j = 1; j <= n ;++j){
            memset(b[j] ,0,sizeof(b[j]));
            cin >> x;
            while(x){
                b[j][k++] = x & 1;
                x >>= 1;
            }
            k = 0;
        }
        for (int w = 29; w >= 0; --w){
            for (int j = 1; j <= n; ++j){
                if (j % 2 == 1 && a[j][w] != b[j][w]){
                    ta = j;
                }
                if (j % 2 == 0 && a[j][w] != b[j][w]){
                    tb = j;
                }
                sa xor_eq a[j][w];
                sb xor_eq b[j][w];
            }   
        
            if (ta > tb && sa != sb){
                cout << "Ajisai" << endl;
                ta = tb = sa = sb = 0;
                break;
            }else if (ta < tb && sa != sb){
                cout << "Mai" << endl;
                ta = tb = sa = sb = 0;
                break;
            }else{
                if (sa == sb && w == 0)
                    cout << "Tie" << endl;
                else if (w == 0){
                        (sa > sb) ? cout << "Ajisai" << endl : cout << "Mai" << endl;
                }
                ta = tb = sa = sb = 0;
            }
        }
        
    }
}  