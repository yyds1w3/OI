#include <iostream>
using namespace std;
int main(){

    int  X, Y, Z;
    cin >> X >> Y >> Z;
    for (int i = 0; i <= 1000; ++i){
        if ((X+i) - (Y+i) * Z == 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}