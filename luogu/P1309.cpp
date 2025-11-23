#include <iostream>
#include <algorithm>
#include <vector>
typedef struct Competor
{
    int index, s, w;
}Competor ;
bool cmp(Competor x, Competor y){
    if (x.s != y.s) return x.s > y.s;
    return x.index < y.index;
}
using namespace std;
Competor C[200001];
vector<Competor> Win, Lose;
int main(){
    int N, R, Q;
    Win.reserve(100001);
    Lose.reserve(100001);
    cin >> N >> R >> Q;
    N *= 2;
    for (int i = 1; i <= N; ++i){
        C[i].index = i;
        cin >> C[i].s;
    }
    for (int i = 1; i <= N; ++i){
        cin >> C[i].w;
    }

    sort(C+1, C+1+N, cmp);
    for (int i = 0; i < R; ++i){
        for (int j = 1; j <= N; j += 2){
            if (C[j].w > C[j+1].w) {
                C[j].s++;
                Win.push_back(C[j]);
                Lose.push_back(C[j+1]);
            }
            else{
                C[j+1].s++;
                Win.push_back(C[j+1]);
                Lose.push_back(C[j]);
            }    
        }
        int a = 0, b = 0, k = 1;
        while (k <= N){
            if (a < Win.size() && (b >= Lose.size() || cmp(Win[a], Lose[b]))) {
                C[k++] = Win[a++];
            } else {
                C[k++] = Lose[b++];
            }           
        }
        Win.clear();
        Lose.clear();
    }

    cout << C[Q].index;

    
}

