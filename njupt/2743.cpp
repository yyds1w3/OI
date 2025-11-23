#include <bits/stdc++.h>
using namespace std;

vector<int> comb2; // 0x11 0x101 0x1001 0x10001....
                   // 0x110 0x1010 ....
void gen_combinations() {
    for(int i=0;i<7;i++)
        for(int j=i+1;j<7;j++)
            comb2.push_back((1<<i)|(1<<j));
}
int main() {
    gen_combinations();
    int ans = 0;
    for(int ic0: comb2)
    for(int ic1: comb2)
    for(int ic2: comb2){
        // 检查 ICPC 每周末人数 ≤ 2
        bool ok_ic = true;
        for(int w=0; w<7; w++){
            int cnt = ((ic0>>w)&1) + ((ic1>>w)&1) + ((ic2>>w)&1);
            if(cnt>2){ ok_ic=false; break; }
        }
        if(!ok_ic) continue;
        // 检查 CCPC 每周末人数 <= 2
        for(int cc0: comb2){
            if(ic0 & cc0) continue; // 同周末冲突
            for(int cc1: comb2){
                if(ic1 & cc1) continue;
                for(int cc2: comb2){
                    if(ic2 & cc2) continue;

                    // 检查 CCPC 每周末人数 ≤ 2
                    bool ok_cc = true;
                    for(int w=0; w<7; w++){
                        int cnt = ((cc0>>w)&1) + ((cc1>>w)&1) + ((cc2>>w)&1);
                        if(cnt>2){ ok_cc=false; break; }
                    }
                    if(!ok_cc) continue;

                    ans++; // 满足约束
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
