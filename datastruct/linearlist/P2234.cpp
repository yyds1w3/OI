#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    set<int> s;
    int n, x, ans = 0;

    // 使用安全的边界值
    s.insert(INT_MAX);
    s.insert(INT_MIN);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (s.size() == 2)
        { // 只有边界值，插入第一个元素
            ans += x;
            s.insert(x);
        }
        else
        {
            auto right = s.lower_bound(x);
            // 如果元素已存在，距离为0，不需要累加
            if (*right != x)
            {
                auto left = right;
                left--;
                // 使用long long避免溢出
                long long dist_left = (long long)x - *left;
                long long dist_right = (long long)*right - x;
                ans += min(abs(dist_left), abs(dist_right));
                s.insert(x);
            }
        }
    }

    cout << ans << endl;
    return 0;
}