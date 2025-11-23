#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<int> x;
bool used[10];
int n;
void dfs(int depth, vector<int> x){
    if (depth == n+1){
        v.push_back(x);
    }else{
        for (int i = 1; i <= n; ++i){
            if (!used[i]){
                used[i] = 1;
                x.push_back(i);
                dfs(depth+1, x);
                x.pop_back();
                used[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n;
    dfs(1, x);
    for (vector<int> x : v){
        for (int y : x){
            cout << setw(5) << y;
        }
        cout << endl;
    }
}