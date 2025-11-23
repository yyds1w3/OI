#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
    int N, M;
    cin >> N;

    list<int> l;
    l.push_back(1);

    // 使用unordered_map存储节点值到迭代器的映射，实现O(1)查找
    unordered_map<int, list<int>::iterator> pos_map;
    pos_map[1] = l.begin();

    for (int i = 2; i <= N; ++i)
    { // 注意：应该是i<=N，从2到N
        int k, p;
        cin >> k >> p;

        auto it_k = pos_map[k]; // O(1)时间找到k的位置

        if (p == 0)
        {
            // 在k前面插入i
            auto new_it = l.insert(it_k, i); // insert返回新插入元素的迭代器
            pos_map[i] = new_it;
        }
        else
        { // p == 1
            // 在k后面插入i
            auto next_it = it_k;
            ++next_it; // k的下一个位置
            auto new_it = l.insert(next_it, i);
            pos_map[i] = new_it;
        }
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int k;
        cin >> k;
        // 只有k确实在链表中时才删除
        if (pos_map.find(k) != pos_map.end())
        {
            l.erase(pos_map[k]); // 通过迭代器删除，O(1)时间
            pos_map.erase(k);    // 从map中移除
        }
    }

    // 输出结果
    for (int x : l)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}