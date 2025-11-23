#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
vector<int> v;
void generate_combnition(int a, int b, int x, int now){
    if (b == 0) v.push_back(x);
    else{
        for (int i = now; i < a; ++i){
            generate_combnition(a, b-1, x | (1 << i), i+1);
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    generate_combnition(a, b, 0, 0);
    for (int x : v){
        for (int i = 0; i < a; ++i){
            if (x & (1 << i))
                cout << setw(3) << i+1;
        }
        cout << endl;

    }
}