#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int square[10][10], new_square[10][10];

    if (n == 1)
    {
        cout << 7 << endl;
        return 0;
    }

    // 输入原矩阵
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> square[i][j];

    // 用于判断是否相等的宏
    auto check_equal = [&](int x)
    {
        bool is_equal = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (new_square[i][j] != square[i][j])
                {
                    is_equal = false;
                    break;
                }
            }
            if (!is_equal)
                break;
        }
        if (is_equal)
        {
            cout << x << endl;
            exit(0);
        }
    };

    // 1. 顺时针旋转 90°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[n - 1 - j][i];
    check_equal(1);

    // 2. 顺时针旋转 180°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[n - 1 - i][n - 1 - j];
    check_equal(2);

    // 3. 顺时针旋转 270°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[j][n - 1 - i];
    check_equal(3);

    // 4. 水平镜像（左右翻转）
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[i][n - 1 - j];
    check_equal(4);

    // 5. 水平镜像后的旋转组合
    // 水平镜像 + 旋转 90°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[i][n - 1 - j]; // f4
    // f1
    {
        int temp[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[i][j] = new_square[n - 1 - j][i];
        memcpy(new_square, temp, sizeof(temp));
    }
    check_equal(5);

    // 水平镜像 + 旋转 180°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[i][n - 1 - j]; // f4
    // f2
    {
        int temp[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[i][j] = new_square[n - 1 - i][n - 1 - j];
        memcpy(new_square, temp, sizeof(temp));
    }
    check_equal(5);

    // 水平镜像 + 旋转 270°
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            new_square[i][j] = square[i][n - 1 - j]; // f4
    // f3
    {
        int temp[10][10];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[i][j] = new_square[j][n - 1 - i];
        memcpy(new_square, temp, sizeof(temp));
    }
    check_equal(5);

    // 如果都不满足
    cout << 7 << endl;

    return 0;
}
