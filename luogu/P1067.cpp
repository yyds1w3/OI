#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool first = true;
    for (int i = n; i >= 0; --i) {
        int a;
        cin >> a;
        if (a == 0) continue; //跳过 0 系数

        // 处理符号
        if (!first) {
            if (a > 0) cout << "+";
        }

        // 处理系数
        if (i == 0) {
            // 常数项
            cout << a;
        } else {
            if (a == -1) cout << "-";
            else if (a != 1) cout << a;

            // 输出 x 部分
            if (i == 1) cout << "x";
            else cout << "x^" << i;
        }

        first = false;
    }

    // 如果全部是 0
    if (first) cout << 0;

    return 0;
}
