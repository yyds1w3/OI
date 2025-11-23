#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

// target exist ?
int bs1(int arr[], int size, int target)
{
    int l = 0, r = size - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (target < arr[m])
        {
            r = m - 1;
        }
        else if (target > arr[m])
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}
// the first element >= m
int bs2(int arr[], int size, int target)
{
    int l = 0, r = size - 1, m, ans = -1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (target <= arr[m])
        {
            r = m - 1;
            ans = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

// the last emlement >= m

int bs3(int arr[], int size, int target)
{
    int ans = bs2(arr, size, target + 1) - 1;
    return ans;
}

// 寻找峰值问题
int find_summit(int arr[], int size){
    if (size == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[size-1] > arr[size-2]) return size-1;
    int l = 1, r = size - 2, m;
    while (l <= r){
        m = l + (r - l) / 2;
        if(arr[m] < arr[m-1]){
            r = m - 1;
        }else if(arr[m] < arr[m+1]){
            l = m + 1;
        }else{
            return m;
        }
    }
    return -1;
}

// 生成随机数组
vector<int> genArr(int maxSize, int maxValue)
{
    int size = rand() % maxSize + 1;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (2 * maxValue + 1) - maxValue;
    }
    sort(arr.begin(), arr.end());
    return arr;
}

int main()
{
    srand(time(0));

    const int testTimes = 100000;
    const int maxSize = 20;
    const int maxValue = 20;

    for (int t = 0; t < testTimes; t++)
    {
        vector<int> arr = genArr(maxSize, maxValue);
        int n = arr.size();
        int target = rand() % (2 * maxValue + 1) - maxValue;

        // bs1 对照 STL 查找
        int idx1 = bs1(arr.data(), n, target);
        auto it1 = find(arr.begin(), arr.end(), target);
        int right1 = (it1 == arr.end()) ? -1 : (it1 - arr.begin());
        // bs2 对照 lower_bound
        int idx2 = bs2(arr.data(), n, target);
        int right2 = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        // bs3 对照 upper_bound - 1
        int idx3 = bs3(arr.data(), n, target);
        int right3 = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;

        if (idx1 != right1)
        {
            cout << "bs1 error!" << endl;
            goto print;
        }

        if (idx2 != right2)
        {
            cout << "bs2 error!" << endl;
            goto print;
        }

        if (idx3 != right3)
        {
            cout << "bs3 error!" << endl;
            goto print;
        }

        continue;

    print:
        cout << "Times = " << t << endl;
        cout << "target = " << target << endl;
        cout << "arr: ";
        for (int x : arr)
            cout << x << " ";
        cout << endl;

        cout << "bs1 = " << idx1 << ", right = " << right1 << endl;
        cout << "bs2 = " << idx2 << ", right = " << right2 << endl;
        cout << "bs3 = " << idx3 << ", right = " << right3 << endl;
        cout << "bs2, bs3与标准库找不到元素的返回值实现代码不一样" << endl;
        return 0;
    }

    cout << "All tests passed!" << endl;
}
