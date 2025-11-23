#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int h, b;
    cin >> h >> b;
    h > b ? cout << h - b : cout << 0;
}