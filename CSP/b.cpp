#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAXN = 100005; 
double sum_k[MAXN];     
double sum_theta[MAXN];  

void scale(double &x, double &y, double k){
    x *= k;
    y *= k;
}

void rotate(double &x, double &y, double theta){
    double old_x = x;
    double old_y = y;
    x = old_x * cos(theta) - old_y * sin(theta);
    y = old_x * sin(theta) + old_y * cos(theta);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    sum_k[0] = 1.0;     
    sum_theta[0] = 0.0;

    for (int i = 1; i <= n; ++i){
        int op;
        double val;
        cin >> op >> val;
        
        if (op == 1) {
            sum_k[i] = sum_k[i-1] * val;    
            sum_theta[i] = sum_theta[i-1];  
        } else {   
            sum_k[i] = sum_k[i-1];          
            sum_theta[i] = sum_theta[i-1] + val; 
        }
    }

    for (int k = 0; k < m; ++k){
        int i, j;
        double x, y;
        cin >> i >> j >> x >> y;

        double total_k = sum_k[j] / sum_k[i-1];
        double total_theta = sum_theta[j] - sum_theta[i-1];

        scale(x, y, total_k);
        rotate(x, y, total_theta);

        cout << setprecision(3) << fixed << x << " " << y << "\n";
    }
    
    return 0;
}