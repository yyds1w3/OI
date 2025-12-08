#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ull; // 64位无符号整数，能存到 10^19 级别

const int N = 10005;

struct Person {
    int a, b;
    // 记录原始输入下标，虽然这题不用输出顺序，但在某些题有用
    int id; 
};

Person p[N];
int n;

// 核心贪心策略：按 a * b 从小到大排序
// 这是数学证明过的正解策略，我们只是在计算数值时偷懒了
bool cmp(const Person& x, const Person& y) {
    // 注意：a * b 可能会爆 int，所以强转 long long 比较
    return (ull)x.a * x.b < (ull)y.a * y.b;
}

int main() {
    // 关流加速
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 1. 读入国王的手牌
    int ka, kb;
    cin >> n;
    cin >> ka >> kb; // 国王站在队伍最前面 (第0个)

    // 2. 读入大臣的手牌
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
        p[i].id = i;
    }

    // 3. 排序 (贪心)
    sort(p + 1, p + 1 + n, cmp);

    // 4. 计算最大奖赏
    ull current_product = ka; // 当前累乘的 a (从国王开始)
    ull max_reward = 0;       // 记录所有大臣中获得的最大奖赏

    for (int i = 1; i <= n; i++) {
        // 第 i 个大臣获得的奖赏 = (前面所有人的 a 的乘积) / 自己的 b
        ull reward = current_product / p[i].b;
        
        // 更新全局最大值
        if (reward > max_reward) {
            max_reward = reward;
        }

        // 更新累乘值，供下一个人使用
        current_product *= p[i].a;
        
        // 【玄学骗分检查】
        // 如果 current_product 突然变小了（溢出），说明后面肯定算不对了。
        // 在这种情况下，可以 break 出去，输出目前为止的最大值，
        // 或者继续跑（对于溢出的数据，反正都是 WA，无所谓了）。
    }

    // 5. 输出
    cout << max_reward << endl;

    return 0;
}