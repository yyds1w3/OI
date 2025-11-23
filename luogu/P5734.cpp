#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, op1, op2, op3;
    string O_str, OP_str, s;
    cin >> q >> O_str;
    getline(cin, s);
    for (int i = 0; i < q; ++i)
    {
        getline(cin, s);
        stringstream ss(s);
        ss >> op1;
        switch (op1)
        {
        case 1:
            ss >> OP_str;
            O_str += OP_str;
            cout << O_str << endl;
            break;
        case 2:
            ss >> op2 >> op3;
            O_str = O_str.substr(op2, op3);
            cout << O_str << endl;
            break;
        case 3:
            ss >> op2 >> OP_str;
            O_str.insert(op2, OP_str);
            cout << O_str << endl;
            break;
        case 4:
            ss >> OP_str;
            cout << (int)O_str.find(OP_str);
            break;
        default:
            break;
        }
    }
}
