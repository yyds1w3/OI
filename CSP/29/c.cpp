#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// 开启 IO 加速
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

// 全局变量
int n, q;

// 核心数据结构：Start -> {End, OwnerID}
// 利用 map 自动排序的特性维护区间
map<string, pair<string, int>> mp;

// --- 辅助函数 ---

// 1. 去除冒号，标准化 IP 地址
string parse(string s) {
    string res = "";
    for (char c : s) {
        if (c != ':') res += c;
    }
    return res;
}

// 2. 十六进制加一 (用于计算 next address)
// 比如 "1f" -> "20"
string next_hex(string s) {
    string res = s;
    int len = res.size();
    int carry = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (carry == 0) break;
        int val;
        if (isdigit(res[i])) val = res[i] - '0';
        else val = res[i] - 'a' + 10;
        
        val += carry;
        carry = val / 16;
        val %= 16;
        
        if (val < 10) res[i] = val + '0';
        else res[i] = val - 10 + 'a';
    }
    // 注意：题目保证 N 位，通常不会溢出 N 位，这里不处理溢出空串的情况
    return res;
}

// 3. 十六进制减一 (用于计算 prev address)
// 比如 "20" -> "1f"
string prev_hex(string s) {
    string res = s;
    int len = res.size();
    int borrow = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (borrow == 0) break;
        int val;
        if (isdigit(res[i])) val = res[i] - '0';
        else val = res[i] - 'a' + 10;
        
        val -= borrow;
        if (val < 0) {
            val += 16;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        if (val < 10) res[i] = val + '0';
        else res[i] = val - 10 + 'a';
    }
    return res;
}

// --- 核心操作函数 ---

// 操作 1: 申请地址
void op1(int id, string l, string r) {
    // === 阶段 1: 检查 (Check) ===
    
    // 检查是否有已经被【其他人】占用的区间
    // 找到第一个可能与 [l, r] 相交的区间：右端点 >= l 的区间
    // 但 map 是按 Start 排序的，所以我们找 upper_bound(l) 然后回退
    
    auto it = mp.upper_bound(l);
    if (it != mp.begin()) it--; // 回退到第一个可能覆盖 l 的区间

    // 遍历所有可能的冲突区间
    while (it != mp.end()) {
        string cur_l = it->first;
        string cur_r = it->second.first;
        int cur_id = it->second.second;

        // 如果当前区间已经在 [l, r] 的右边且无交集，停止搜索
        if (cur_l > r) break;

        // 判断是否有交集: max(start1, start2) <= min(end1, end2)
        if (max(l, cur_l) <= min(r, cur_r)) {
            // 规则 A: 被别人占了 -> 失败
            if (cur_id != id) {
                cout << "NO" << "\n";
                return;
            }
        }
        it++;
    }

    // 规则 B: 虽然全是自己的，但如果 [l, r] 已经被【完全】包含在某个旧区间里 -> 失败
    // 因为我们做了严格合并，所以只要找有没有一个区间包含 [l, r] 即可
    it = mp.upper_bound(l);
    if (it != mp.begin()) {
        auto prev = std::prev(it);
        if (prev->second.first >= r && prev->second.second == id) {
            cout << "NO" << "\n";
            return;
        }
    }

    // === 阶段 2: 执行 (Update) ===
    cout << "YES" << "\n";

    string final_l = l;
    string final_r = r;

    // 我们需要找出所有与 [l, r] 【相交】或【相邻】的同 ID 区间，把它们全部吞并
    // 重新定位迭代器
    it = mp.upper_bound(l);
    if (it != mp.begin()) it--; 

    vector<string> to_delete; // 待删除的旧区间 Key

    while (it != mp.end()) {
        string cur_l = it->first;
        string cur_r = it->second.first;
        int cur_id = it->second.second;

        // 优化：如果当前区间起点已经在 r 的右边很远（不相邻），可以提前退出
        // 临界情况：cur_l 刚好是 r 的下一个 (r + 1)，这时候是相邻的，需要合并
        // 所以当 cur_l > r + 1 时才退出
        // 利用 next_hex 计算 r + 1
        string r_plus_1 = next_hex(r);
        if (cur_l > r_plus_1) break;

        // 判断是否需要合并（相交 OR 相邻）且属于同一个人
        bool should_merge = false;
        
        if (cur_id == id) {
            // 情况 1: 相交
            if (max(l, cur_l) <= min(r, cur_r)) should_merge = true;
            // 情况 2: 相邻 (左拼接: cur_r + 1 == l)
            else if (next_hex(cur_r) == l) should_merge = true;
            // 情况 3: 相邻 (右拼接: r + 1 == cur_l)
            else if (next_hex(r) == cur_l) should_merge = true;
        }

        if (should_merge) {
            // 更新超级区间的边界
            if (cur_l < final_l) final_l = cur_l;
            if (cur_r > final_r) final_r = cur_r;
            // 标记删除
            to_delete.push_back(cur_l);
        }
        it++;
    }

    // 执行删除
    for (auto& key : to_delete) {
        mp.erase(key);
    }

    // 插入融合后的新区间
    mp[final_l] = {final_r, id};
}

// 操作 2: 查询单点归属
void op2(string s) {
    auto it = mp.upper_bound(s);
    if (it != mp.begin()) {
        it--;
        // 检查 s 是否落在区间 [start, end] 内
        if (it->second.first >= s) {
            cout << it->second.second << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

// 操作 3: 查询区间归属
void op3(string l, string r) {
    // 检查是否存在一个区间 [Start, End] 完整包含 [l, r]
    // 由于我们做了严格合并，不需要拼凑碎片，只要被某一个大区间包含即可
    auto it = mp.upper_bound(l);
    if (it != mp.begin()) {
        it--;
        if (it->second.first >= r) {
            cout << it->second.second << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main() {
    IOS;
    cin >> n >> q;

    int type;
    int id;
    string s, l, r;

    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> id >> l >> r;
            op1(id, parse(l), parse(r));
        } else if (type == 2) {
            cin >> s;
            op2(parse(s));
        } else if (type == 3) {
            cin >> l >> r;
            op3(parse(l), parse(r));
        }
    }

    return 0;
}