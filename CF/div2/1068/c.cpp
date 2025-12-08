#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> uniq = a;
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    vector<ll> candidates;
    for (ll val : uniq) {
        if (k / val > n) continue; 
        bool ok = true;
        for (ll m = val; m <= k; m += val) {
            auto it = lower_bound(uniq.begin(), uniq.end(), m);
            if (it == uniq.end() || *it != m) {
                ok = false;
                break;
            }
        }
        if (ok) {
            candidates.push_back(val);
        }
    }
    vector<ll> b;
    vector<bool> removed(candidates.size(), false);
    for (int i = 0; i < candidates.size(); i++) {
        if (removed[i]) continue;
        ll val = candidates[i];
        b.push_back(val);
        for (ll m = 2 * val; m <= k; m += val) {
            auto it = lower_bound(candidates.begin(), candidates.end(), m);
            if (it != candidates.end() && *it == m) {
                int idx = distance(candidates.begin(), it);
                removed[idx] = true;
            }
        }
    }
    int covered_cnt = 0;
    vector<bool> is_covered(uniq.size(), false);
    for (ll val : b) {
        for (ll m = val; m <= k; m += val) {
            auto it = lower_bound(uniq.begin(), uniq.end(), m);
            if (it != uniq.end() && *it == m) {
                int idx = distance(uniq.begin(), it);
                if (!is_covered[idx]) {
                    is_covered[idx] = true;
                    covered_cnt++;
                }
            }
        }
    }
    if (covered_cnt == uniq.size()) {
        cout << b.size() << "\n";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << (i == b.size() - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}