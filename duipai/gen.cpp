/**
 * Ultimate Data Generator for ACM-ICPC
 * Author: Ling
 * Standard: C++17
 * Usage: Compile and run. Redirect output to file if needed.
 */
#include <bits/stdc++.h>
using namespace std;

namespace Gen {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // --- 1. 基础数值生成 ---
    
    // 生成 [l, r] 范围内的随机整数 (long long)
    long long Int(long long l, long long r) {
        if (l > r) swap(l, r);
        return uniform_int_distribution<long long>(l, r)(rng);
    }
    
    // 生成 [l, r] 范围内的随机实数
    double Double(double l, double r) {
        return uniform_real_distribution<double>(l, r)(rng);
    }

    // 生成随机字符 (默认为小写字母)
    char Char(const string& s = "abcdefghijklmnopqrstuvwxyz") {
        return s[Int(0, s.size() - 1)];
    }

    // --- 2. 序列生成 ---

    // 生成长度为 n，范围在 [l, r] 的数组
    vector<long long> Array(int n, long long l, long long r) {
        vector<long long> res(n);
        for(int i=0; i<n; i++) res[i] = Int(l, r);
        return res;
    }

    // 生成 1 ~ n 的随机排列 (Permutation)
    vector<int> Permutation(int n) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), rng);
        return p;
    }

    // 生成长度为 n 的随机字符串
    string String(int n, const string& charset = "abcdefghijklmnopqrstuvwxyz") {
        string res = "";
        for(int i=0; i<n; i++) res += charset[Int(0, charset.size()-1)];
        return res;
    }

    // --- 3. 图论生成 ---

    // 打印边的辅助结构
    struct Edge { int u, v; };

    // 生成 n 个节点的随机树 (确保连通，无环)
    // 策略：对于点 i (2..n)，随机挂在 1..i-1 中任意一点上
    vector<Edge> Tree(int n) {
        vector<Edge> edges;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), rng); // 打乱节点编号，避免生成的数据有编号规律

        for (int i = 1; i < n; i++) {
            int u = p[i];
            int v = p[Int(0, i - 1)];
            edges.push_back({u, v});
        }
        return edges;
    }

    // 生成 n 点 m 边的随机连通图 (无重边，无自环)
    // 策略：先生成树保证连通，再随机加边
    vector<Edge> ConnectedGraph(int n, int m) {
        if (m < n - 1) m = n - 1; // 至少 n-1 条边才能连通
        vector<Edge> edges = Tree(n); // 先拿一棵树
        
        set<pair<int, int>> exist;
        for(auto& e : edges) {
            exist.insert({min(e.u, e.v), max(e.u, e.v)});
        }

        // 补足剩余边
        while ((int)edges.size() < m) {
            int u = Int(1, n);
            int v = Int(1, n);
            if (u == v) continue;
            if (u > v) swap(u, v);
            if (exist.count({u, v})) continue; // 避免重边
            
            exist.insert({u, v});
            edges.push_back({u, v});
        }
        
        shuffle(edges.begin(), edges.end(), rng); // 打乱边的顺序
        return edges;
    }

    // --- 4. 输出辅助 ---
    void Print(long long x) { cout << x << " "; }
    void Print(const string& s) { cout << s << " "; }
    void Println() { cout << "\n"; }
    
    // 打印 vector
    template<typename T>
    void Print(const vector<T>& v) {
        for(int i=0; i<v.size(); i++) cout << v[i] << (i==v.size()-1?"":" ");
        cout << "\n";
    }

    // 打印图
    void Print(const vector<Edge>& edges) {
        for(auto& e : edges) cout << e.u << " " << e.v << "\n";

    }
}

using namespace Gen;

int main() {
    // ⚠️ 在这里修改参数来造数据 ⚠️
    
    // 示例 1: 生成一个 N <= 10^5 的数组题数据
    int N = Int(1, 10000); // 先用小数据 (比如10) 调试逻辑，最后改为 100000
    int B = Int(1, 10000);
    cout << N << " " << B << "\n";
    return 0;
}
