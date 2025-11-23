#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long sq = 0, rc = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (i == j) sq += (n - i) * (m - j);
            else rc += (n - i) * (m - j);
        }
    }
    cout << sq << " " << rc << endl;
}