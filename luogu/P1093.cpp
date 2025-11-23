#include <iostream>
#include <algorithm>
using namespace std;

struct st{
    int yw, sx, yy, zf, id;
}a[301];
bool comp(st a, st b){
    if (a.zf != b.zf) return a.zf > b.zf;
    if (a.yw != b.yw) return a.yw > b.yw;
    return a.id < b.id;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        a[i].id = i;
        cin >> a[i].yw >> a[i].sx >> a[i].yy;
        a[i].zf = a[i].yw + a[i].sx + a[i].yy;
    }
    sort(a+1, a+n+1, comp);
    for (int i = 1; i <= 5; ++i){
        cout << a[i].id << " " << a[i].zf << endl;;
    }
}