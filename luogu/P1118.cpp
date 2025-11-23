    #include <iostream>
    using namespace std;
    int a[13];
    bool used[13];
    int C[13][13];
    int n, sum;

    void dfs(int i, int total){
        // 终止条件
        if (i > n){
            if (total == sum){
                for (int j = 1; j <= n; ++j){
                    cout << a[j] << " ";
                }
                exit(0);

            }
            return;
        }
        // 剪枝
        if (total > sum) return;
        

        for (int j = 1; j <= n; ++j){
            if (!used[j]){
                used[j] = true;
                a[i] = j; 
                dfs(i+1, total + j * C[n-1][i-1]);
                used[j] = false;
            }
        }

    }

    int main(){
        cin >> n >> sum;
        for (int i = 0; i <= n; ++i) C[i][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; ++j){
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        dfs(1, 0);

    }