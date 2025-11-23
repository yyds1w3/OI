#include <iostream>
using namespace std;

char a[102][102]; // 外面包一层，避免越界

int main() {
    int n, m;
    cin >> n >> m;

    // 读入
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '?') a[i][j] = '0';
        }
    }

    // 扫描所有雷
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '*') {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (a[i+dx][j+dy] != '*') {
                            a[i+dx][j+dy]++;
                        }
                    }
                }
            }
        }
    }

    // 输出
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
