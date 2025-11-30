#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int N = 10;
vector<int> path;
bool used[N];
int n;

void dfs(int depth){
    if (depth == n + 1) {for (int p : path) cout << setw(5) << p; cout << endl; return;}
    for (int i = 1; i <= n; ++i){
        if (!used[i]){
            path.push_back(i);
            used[i] = true;
            dfs(depth+1);
            used[i] = false;
            path.pop_back();
        }
    }
}
int main(){
    cin >> n;
    dfs(1);
}