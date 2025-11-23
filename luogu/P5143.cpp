#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double ans = 0;
struct st{
    int x, y, z;
}a[50000];
bool comp(st x, st y){
    return x.z > y.z;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a, a+n, comp);
    for (int i = 0; i < n-1; ++i){
        ans += sqrt((a[i+1].x-a[i].x)*(a[i+1].x-a[i].x) + (a[i+1].y-a[i].y)*(a[i+1].y-a[i].y) + (a[i+1].z-a[i].z)*(a[i+1].z-a[i].z));
    }
    printf("%.3lf", ans);
}