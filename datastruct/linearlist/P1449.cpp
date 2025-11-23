#include <iostream>
using namespace std;

int main()
{
    int a[51] = {0};
    int i = 0;
    string st, s;
    cin >> st;
    for (char ch : st){
        if (ch >= '0' && ch <= '9'){
            s += ch;
        }else if (ch == '.'){
            a[i] = stoi(s);
            s.clear();
            ++i;
        }else if (ch == '@'){
            break;
        }else{
            switch (ch){
            case '+':
                a[i - 2] += a[i - 1];
                i--;
                break;
            case '-':
                a[i - 2] -= a[i - 1];
                i--;
                break;
            case '*':
                a[i - 2] *= a[i - 1];
                i--;
                break;
            case '/':
                a[i - 2] /= a[i - 1];
                i--;
                break;
            default:
                break;
            }
        }
    }
    cout << a[0];
}