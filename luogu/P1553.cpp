#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int split = 0;
    int type = 0; // 0--整数 1--小数 2--分数 3-- %
    int sign = 0;
    int o = 0;
    cin >> s;
    for (int i = 0; i < (int)s.length(); ++i){
        if (s[i] == '.'){
            split = i;
            type = 1;
        }
        if (s[i] == '/'){
            split = i;
            type = 2;
        }
        if (s[i] == '%'){
            split = i;
            type = 3;
        }
    }
    switch (type){
    case 0:
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] != '0' || (s[i] == '0' && sign == 1)){
                cout << s[i];
                sign = 1;
                o = 1;
            }
        }
        if (!o)
            cout << "0";
        break;
    case 1:
        for (int i = split - 1; i >= 0; --i){

            if (s[i] != '0' || (s[i] == '0' && sign == 1)){
                cout << s[i];
                sign = 1;
                o = 1;
            }
        }
        if (!o)
            cout << "0";
        cout << ".";
        sign = 0;
        o = 0;
        for (int i = s.length() - 1; i > split; --i){
            for (int j = i; j > split; --j){ // (split, i]不全为0，可打印i即使i为0
                if (s[j] != '0')
                    sign = 1;
            }
            if (s[i] != '0' || (s[i] == '0' && sign == 1)){
                cout << s[i];
                o = 1;
            }
            sign = 0;
        }
        if (!o)
            cout << "0";
        break;
    case 2:
        for (int i = split - 1; i >= 0; --i)
        {
            if (s[i] != '0' || (s[i] == '0' && sign == 1))
            {
                cout << s[i];
                sign = 1;
                o = 1;
            }
        }
        if (!o)
            cout << "0";
        cout << "/";
        sign = 0;
        o = 0;
        if (stoi(s.substr(split + 1, string::npos)) == 0) // [split+1,end]
            cout << "0";
        for (int i = s.length() - 1; i > split; --i)
        {
            if (s[i] != '0' || (s[i] == '0' && sign == 1))
            {
                cout << s[i];
                sign = 1;
                o = 1;
            }
        }
        if (!o)
            cout << "0";
        break;
    case 3:
        for (int i = split - 1; i >= 0; --i)
        {
            if (s[i] != '0' || (s[i] == '0' && sign == 1))
            {
                cout << s[i];
                sign = 1;
                o = 1;
            }
        }
        if (!o)
            cout << "0";
        cout << "%";
        break;
    default:
        break;
    }
}