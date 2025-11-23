#include <iostream>
#include <cmath>
using namespace std;
int a[17];
int main(){
    int n,r;
    cin >> n >> r;
    int index = 16;
    while(index > -1){
        if (index % 2 == 0 && n < pow(r,index) * abs(r) && n > pow(r, index - 2)){
            a[index] = 1;
        }else if(index % 2 == 1 && n > pow(r,index) * abs(r) && n < pow(r, index - 2)){
            a[index] = 1;
        }
        cout << a[index];
        index--;
    }

}