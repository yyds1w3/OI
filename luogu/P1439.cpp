#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int mp[N];
int b[N];  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mp[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> x;
        b[i] = mp[x];
    }
    vector<int> tail;
    if (n > 0) tail.push_back(b[1]);

    for (int i = 2; i <= n; i++) {
        if (b[i] > tail.back()) {
            tail.push_back(b[i]);
        } 
        else {
            int idx = lower_bound(tail.begin(), tail.end(), b[i]) - tail.begin();
            tail[idx] = b[i]; 
        }
    }

    cout << tail.size() << endl;
    return 0;
}