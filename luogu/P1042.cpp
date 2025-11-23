#include <iostream>

using namespace  std;
int a[2];
int main(){
    char c;
    string s;
    while (cin >> c){
        s += c;
        if (c == 'E')
            break;
    }
    for (char c : s){
        if (c == 'W'){
            a[0]++;
        }
        if (c == 'L'){
            a[1]++;
        }
        if (a[0] >= 11 && a[0] - a[1] >= 2){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }else if(a[1] >= 11 && a[1] - a[0] >= 2){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }else if(c == 'E'){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }
    }
    cout << endl;
    for (char c : s){
        if (c == 'W'){
            a[0]++;
        }
        if (c == 'L'){
            a[1]++;
        }
        if (a[0] >= 21 && a[0] - a[1] >= 2){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }else if(a[1] >= 21 && a[1] - a[0] >= 2){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }else if(c == 'E'){
            cout << a[0] << ":" << a[1] << endl;
            a[0] = a[1] = 0;
        }
    }

    
}
