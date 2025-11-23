#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x + b*x*x + c*x + d;
}

int main(){
    cin >> a >> b >> c >> d;
    double l, r, m;
    double f1, f2, fm;
    int s = 0;
    for (int i = -100; i < 100; ++i){
        l = i;
        r = i+1;
        f1 = f(l);
        f2 = f(r);

        if (!f1){
            cout << setprecision(2) << fixed << double(l) << " ";
            s++;
        }else if (f1 * f2 < 0){
            while (r - l > 0.001)
            {
                m = (l + r) / 2;
                fm = f(m);
                if (f1 * fm < 0){
                    r = m;
                }
                if (fm * f2 < 0){
                    l = m;
                }
            }
            cout << setprecision(2) << fixed << double(r) << " ";
            s++;
        }
        if (s == 3) break;

    }
}