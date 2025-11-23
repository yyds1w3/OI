#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N, A, B, ans = 0, a_g = 0, b_g = 0, a_g_tmp = 0, b_g_tmp = 0;
    cin >> N >> A >> B;
    char s[300001];
    for (int i = 1; i <= N; ++i)
    {
        cin >> s[i];
    }
    s[N + 1] = 'c';
    int l = 1, r = 1, l_tmp = 1;
    s[1] == 'a' ? a_g++ : b_g++;
    while (r < N)
    {
        // 移动右边
        l = l_tmp, a_g = a_g_tmp, b_g = b_g_tmp;
        r++;
        s[r] == 'a' ? a_g++ : b_g++;
        while (b_g >= B)
        {
            s[l] == 'a' ? a_g-- : b_g--;
            l++;
        }
        // 最多1个b, 固定右边, 记录左边
        l_tmp = l, a_g_tmp = a_g, b_g_tmp = b_g;
        while (a_g >= A && b_g < B)
        {
            ans++;
            if (a_g >= A + 1)
            {
                s[l] == 'a' ? a_g-- : b_g--;
                l++;
            }
            else
            {
                r++;
                s[r] == 'a' ? a_g_tmp++ : b_g_tmp++;
                break;
            }
        } // b_g < B
    }

    cout << ans;
}