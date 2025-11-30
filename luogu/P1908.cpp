#include <bits/stdc++.h>
using namespace std;
#define BIT_METHOD 0
#define MS_METHOD 1
#if BIT_METHOD
const int N = 5e5 + 5;
int n, m;
int tree[N];
int A[N], B[N];

int lowbit(int x){
    return x & (-x);
}

void add(int x, int k){
    while(x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}

int ask(int x){
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B + 1, B + 1 + n);
    int len = unique(B + 1, B + 1 + n) - (B + 1);
    long long ans = 0; 
    
    for (int i = 1; i <= n; ++i) {
        int rank = lower_bound(B + 1, B + 1 + len, A[i]) - B; 
        add(rank, 1); // A[i]进入了Tree[2]
        ans += (i - ask(rank)); // 询问Tree前[1~2]的节点个数和, i - 已经小于等于的就是剩下的大的, 这是截止到i的答案，后面的逆序对要靠i往后移来算
    }
    cout << ans << endl;
    return 0;
}
#endif
#if MS_METHOD
#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int a[N];     // 原数组
int temp[N];  // 临时数组 (归并排序必须)
long long ans = 0; // 记录逆序对数量

// [L, R] 是当前处理的区间
void merge_sort(int L, int R) {
    // 1. 递归边界：只有一个数，不用排
    if (L >= R) return;

    // 2. 分：切成两半
    int mid = (L + R) >> 1; // 相当于 (L+R)/2
    merge_sort(L, mid);     // 排左边
    merge_sort(mid + 1, R); // 排右边

    // 3. 治：合并两个有序数组
    int i = L;        // 左半边指针
    int j = mid + 1;  // 右半边指针
    int k = 0;        // 临时数组指针

    while (i <= mid && j <= R) {
        if (a[i] <= a[j]) {
            // 左边小，正常情况，没逆序对
            temp[k++] = a[i++];
        } else {
            // 右边小 (a[j] < a[i])
            // 【关键】统计逆序对
            // 左边从 i 到 mid 的所有数都比 a[j] 大
            ans += (mid - i + 1);
            
            temp[k++] = a[j++];
        }
    }

    // 4. 扫尾：把剩下一半没放完的直接抄过来
    while (i <= mid) temp[k++] = a[i++];
    while (j <= R) temp[k++] = a[j++];

    // 5. 搬运：把排好序的 temp 倒回原数组 a
    for (int p = 0; p < k; p++) {
        a[L + p] = temp[p];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    merge_sort(1, n);

    cout << ans << endl;
    return 0;
}
#endif