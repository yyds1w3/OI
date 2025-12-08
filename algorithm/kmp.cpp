#include <iostream>
#include <vector>
#include <string>
using namespace std;
void kmp(string s, string p){
    int n = s.length();
    int m = p.length();

    s = ' ' + s;
    p = ' ' + p;
    vector<int> next(m + 1);
    // i 表示后半部分, j 表示前半部分
    for (int i = 2, j = 0; i <= m; ++i){ // 构建next[2, m]
        while (j > 0 && p[i] != p[j+1]){  // 匹配失败且有回退资本, 后缀与前缀不匹配
            j = next[j]; // 复活点
        }
        if (p[i] == p[j+1]){ // 匹配成功
            j++;
        }
        next[i] = j; //保存复活点
    }
    for (int i = 1, j = 0; i <= n; ++i){
        while (j > 0 && s[i] != p[j + 1]){
            j = next[j];
        }
        if (s[i] == p[j+1]){
            j++;
        }
        if (j == m){
            cout << i - m + 1 << '\n';
            j = next[j];
        }
    }

}