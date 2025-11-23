#include <iostream>

using namespace std;
int n, kind;
int ans[10000][10];
int tmp[10];
void dfs(int depth, int total){
    if (depth == 10){ // 边界
        if (total == n){ // 满足条件存储值
            for (int j = 0; j < 10; ++j){
                ans[kind][j] = tmp[j];
            }
            kind++;
        }
    }else if (total >= n){ // 剪枝
        return;
    }else{ // 这一步该做什么? 
        for (int i = 1; i <= 3; ++i){
            tmp[depth] = i;
            dfs(depth + 1, total + i);     
        }
    }

}

int main(){
    cin >> n;
    dfs(0, 0);
    cout << kind << endl;
    for (int i = 0; i < kind; ++i){
        for (int j = 0; j < 10; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}