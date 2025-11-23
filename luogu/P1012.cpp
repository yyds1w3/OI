#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string x, string y){
    return (x+y) > (y+x);
}
int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; ++i){
        cout << v[i];
    }
}