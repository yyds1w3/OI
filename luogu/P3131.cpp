#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long pre[50001];
int loc[7][2];

void init(int loc[][2]){
    loc[0][0] = 0;
    for (int i = 1; i <= 7; ++i){
        loc[i][0] = INT_MAX;
        loc[i][1] = 1;
    }
}
int main()
{
    int N;
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    init(loc);
    for (int i = 1; i <= N; ++i){
        pre[i] %= 7;
        loc[pre[i]][0] = min(loc[pre[i]][0], i);
        loc[pre[i]][1] = max(loc[pre[i]][1], i); 
    }
    
    for (int i = 0; i < 7; ++i){
        ans = max(ans, loc[i][1]-loc[i][0]);
    }

    cout << ans;

}
