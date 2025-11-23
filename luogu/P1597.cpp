#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, token;
    cin >> s;
    stringstream ss(s);
    vector<string> tokens;
    map<char, int> m = {{'a', 0}, {'b', 0}, {'c', 0}};
    char ch;
    while (getline(ss, token, ';'))
        tokens.push_back(token);

    for (auto it = tokens.begin(); it != tokens.end(); ++it){
        token = *it;
        ch = token.at(3);
        if (ch >= 'a' && ch <= 'z'){
            m[token.at(0)] = m[ch];
        }else
            m[token.at(0)] = ch - '0';
    }
    cout << m['a'] << ' ' << m['b'] << ' ' << m['c'];
}