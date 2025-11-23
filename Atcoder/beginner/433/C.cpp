#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    long long ans = 0;

    vector<pair<char, int>> runs;

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && S[j] == S[i]) j++;
        runs.push_back({S[i], j - i});
        i = j;
    }

    for (int i = 0; i + 1 < runs.size(); i++) {
        char d1 = runs[i].first;
        char d2 = runs[i+1].first;

        if (!isdigit(d1) || !isdigit(d2)) continue;
        if (d2 - d1 == 1) {
            ans += min(runs[i].second, runs[i+1].second);
        }
    }

    cout << ans;
    return 0;
}
