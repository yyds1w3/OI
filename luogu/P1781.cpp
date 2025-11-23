#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct st{
    int num;
    string s;
};

bool comp(st a, st b){
    if (a.s.size() != b.s.size()) return a.s.size() > b.s.size();
    int sz = a.s.size();
    for (int i = 0; i < sz; ++i){
        if (a.s[i] != b.s[i]) return a.s[i] > b.s[i];
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    vector<st> v(n+1);
    for (int i = 1; i <= n; ++i){
        v[i].num = i;
        cin >> v[i].s;
    }
    sort(v.begin()+1,v.end(), comp);
    cout << v[1].num << endl << v[1].s;
}