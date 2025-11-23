#include <iostream>
#include <stack>
#include <ios>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int a[100001], b[100001];

int main()
{
    IOS;
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;

        for (int j = 1; j <= n; ++j)
        {
            cin >> a[j];
        }
        for (int j = 1; j <= n; ++j)
        {
            cin >> b[j];
        }

        stack<int> stk;
        int a_index = 1; // 指向a数组的当前位置
        int b_index = 1; // 指向b数组的当前位置
        bool isValid = true;

        // 模拟栈操作过程
        while (b_index <= n)
        {
            // 如果栈顶元素等于当前b元素，则弹出
            if (!stk.empty() && stk.top() == b[b_index])
            {
                stk.pop();
                b_index++;
            }
            // 如果还有a元素可以压栈
            else if (a_index <= n)
            {
                stk.push(a[a_index]);
                a_index++;
            }
            // 既不能弹出也不能压栈，说明不匹配
            else
            {
                isValid = false;
                break;
            }
        }

        if (isValid && stk.empty())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}