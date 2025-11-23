#include <iostream>
using namespace std;
int a[200], b[200];
int k[5][5] = {{0, 0, 1, 1, 0},
               {1, 0, 0, 1, 0},
			   {0, 1, 0, 0, 1},
			   {0, 0, 1, 0, 1},
			   {1, 1, 0, 0, 0}};
typedef struct C{
    int a;
    int b;
    int resa = 0, resb = 0;
    void f(){
        resa += k[a][b];
        resb += k[b][a];
    }
} C;
int main(){
    int N, Na, Nb;
    C c;
    cin >> N >> Na >> Nb;
    for (int i = 0; i < Na; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < Nb; ++i){
        cin >> b[i];
    }
    for (int i = 0; i < N; ++i){
        c.a = a[i%Na];
        c.b = b[i%Nb];
        c.f();
    }
    cout << c.resa << " " << c.resb;
}
