#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> v;
const int N = 1e2 + 1;
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        int dx, dy;
        cin >> dx >> dy;
        v.push_back({dx, dy});
    }
    for (int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < n; ++j){
            x += v[j].first;
            y += v[j].second;
        }
        cout << x << " " << y << '\n';
    }
}