#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s[7];
    string s_ans;
    int s_i[7] = {0};
    map<string, int> m = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"a", 1}, {"both", 2}, {"another", 1}, {"first", 1}, {"second", 2}, {"third", 3}, {"zero", 0}};
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6];
    int a;
    for (int i = 0; i < 7; i++)
    {
        auto m_it = m.find(s[i]);
        if (m_it != m.end()){
            a = m_it->second * m_it->second % 100;
            s_i[i] = a;
        }
    }
    sort(s_i, s_i + 7); // [0, 7)
    for (int i = 0; i < 7; ++i)
    {
        if (s_i[i] != 0){
            s_ans += to_string(s_i[i]);
        }
    }
    cout << s_ans;
}