#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
const int N = 25;
vector<int> path;
bool used[N];
int n;
bool is_prime(int x){
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int depth){
    if (depth == n + 1 && (is_prime(path.back() + path[0]))){
        for (int i = 0; i < n; ++i){
            cout << path[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return;
    }
    for (int i = 2; i <= n; ++i){
        if (!used[i] && is_prime(path.back() + i)){
            used[i] = true;
            path.push_back(i);
            dfs(depth+1);
            used[i] = false;
            path.pop_back();            
        }
    }
}
int main(){
    int caseNum = 0;
    while (cin >> n){
        caseNum++;
        if (caseNum > 1) cout << endl;
        cout << "Case " << caseNum << ":" << endl;
        memset(used, 0, sizeof(used));
        path.clear();
        path.push_back(1);
        used[1] = true;
        dfs(2);
    }
}