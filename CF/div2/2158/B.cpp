#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }
    int cnt_odd = 0; // 奇数
    int cnt_even = 0; // 偶数
    
    for (auto const& [val, count] : counts) {
        if (count % 2 != 0) {
            cnt_odd++;
        } else {
            cnt_even++;
        }
    }
    
    // 贪心：尽可能多地选偶频元素
    // 每个被选中的偶频元素，在 p 中至少占 1 个位置
    int k = min(cnt_even, n); // 
    
    // 检查剩余空间 n - k 的奇偶性
    int remainder = n - k; // even元素大于n就为0
    
    if (remainder % 2 != 0) {
        // 如果剩余空间是奇数，我们需要调整
        // 只有当没有奇频元素可用，或者 p 已经被填满了(k==n)没法塞奇频元素时
        // 我们才被迫放弃一个偶频元素
        if (cnt_odd == 0 || k == n) {
            k--;
        }
        // 否则(有奇频元素且有空间)，我们可以用一个奇频元素填补那个奇数空缺
        // k 保持不变
    }
    
    cout << cnt_odd + 2 * k << "\n"; // 每个奇数贡献一个, 偶数能够贡献两个(两边分别奇数)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}