#include <iostream>
using namespace std;
char m[10][10];
typedef struct a{
    int pos[2]; // x, y
    int v[2] = {-1, 0}; // x, y
}a;
int ans = 0;
int main(){
    a F, C;
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            cin >> m[i][j];
            if (m[i][j] == 'F'){
                F.pos[0] = i, F.pos[1] = j;
            }
            if (m[i][j] == 'C'){
                C.pos[0] = i, C.pos[1] = j;
            }
        }
    }

    while (!(F.pos[0] == C.pos[0] && F.pos[1] == C.pos[1])){
        if (F.pos[0] + F.v[0] >= 0
        &&  F.pos[0] + F.v[0] <= 9
        &&  F.pos[1] + F.v[1] >= 0
        &&  F.pos[1] + F.v[1] <= 9
        &&  m[F.pos[0] + F.v[0]][F.pos[1] + F.v[1]] != '*'
        ){
            F.pos[0] += F.v[0];
            F.pos[1] += F.v[1];
        }else{
            if (F.v[0] == 0){
                F.v[1] == 1 ? F.v[0] = 1 : F.v[0] = -1;
                F.v[1] = 0;
            }else if (F.v[0] == 1){
                F.v[1] = -1;
                F.v[0] = 0;
            }else{
                F.v[1] = 1;
                F.v[0] = 0;
            }
        }
        if (C.pos[0] + C.v[0] >= 0
        &&  C.pos[0] + C.v[0] <= 9
        &&  C.pos[1] + C.v[1] >= 0
        &&  C.pos[1] + C.v[1] <= 9
        &&  m[C.pos[0] + C.v[0]][C.pos[1] + C.v[1]] != '*'
        ){
            C.pos[0] += C.v[0];
            C.pos[1] += C.v[1];
        }else{
            if (C.v[0] == 0){
                C.v[1] == 1 ? C.v[0] = 1 : C.v[0] = -1;
                C.v[1] = 0;
            }else if (C.v[0] == 1){
                C.v[1] = -1;
                C.v[0] = 0;
            }else{
                C.v[1] = 1;
                C.v[0] = 0;
            }
        }
        ans++;
        if (ans == 10000000) {ans = 0; break;}
    }
    cout << ans;

    

}
