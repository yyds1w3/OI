#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 105;
int n;
vector<int> adj[N];
int in[N];
vector<int> ans;
queue<int> q;
int main(){
    cin >> n;
    for (int u = 1; u <= n; ++u){
        int v;
        while(cin >> v && v != 0){
            adj[u].push_back(v);
            in[v]++;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (in[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u]){
            in[v]--;
            if (in[v] == 0){
                q.push(v);
            }
        }
    }
    for (int a : ans) cout << a << " ";
    
}