#include <iostream>
using namespace std;
int a[20];
bool col[20];
bool d1[50]; // ↘ i - j == c
bool d2[50]; // ↗ i + j == c
int n;
int ans = 0;

void dfs(int i){
    if (i > n){
        if (ans < 3){
            for (int i = 1; i <= n; ++i){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        ans++;
        return;
    }

    for (int j = 1; j <= n; ++j){
        if ((!col[j]) && (!d1[n + i + j]) && (!d2[n + i - j])){
            a[i] = j;
            col[j] = 1;
            d1[n + i + j] = 1;
            d2[n + i - j] = 1;
            dfs(i + 1);
            col[j] = 0;
            d1[n + i + j] = 0;
            d2[n + i - j] = 0;
        }
    }

}

int main(){
    cin >> n;
    dfs(1);
    cout << ans;
}
