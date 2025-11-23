#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
long long ans = 0;
int times = 0;
int main() {
    int q;
    ifstream fin("../E.in");
    if (!fin){
        cerr << "Err" << endl;
        return 1;
    }

    fin >> q;
    string s1, s2;
    vector<pair<string, int>> v;
    long long n;
    for (int i = 0; i < q; ++i){
        fin >> s1;
        if (s1 == "ADD"){
            fin >> s2 >> n;
            for (auto it = v.begin(); it != v.end();){
                if (it->first == s2){
                    it = v.erase(it);
                }else{
                    ++it;
                }
            }
            v.push_back({s2, n});
        }else if(s1 == "QUERY"){
            fin >> s2;
            for (auto p : v){
                if (p.first.find(s2) == 0){
                    ans += p.second;
                    times++;
                }
            }
            cout << times << " " << ans << endl;
            times = ans = 0;
        }else if(s1 == "DEL"){
            fin >> s2;
            for (auto it = v.begin(); it != v.end();){
                if (it->first == s2){
                    it = v.erase(it);
                }else{
                    ++it;
                }
            }
        }
    }
}
