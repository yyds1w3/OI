#include <iostream>
using namespace std;

string f(){
    int t;
    char ch;
    string s ="", str="";
    while (cin >> ch){
        if (ch == '['){
            cin >> t;
            str = f(); // 解压缩一次
            while(t--){
                s += str;
            }
        }else if (ch == ']'){
            return s;
        }else{
            s += ch;
        }
    }
    return s;
}

int main(){
    cout << f();
    return 0;
}