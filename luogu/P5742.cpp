#include <bits/stdc++.h>
using namespace std;

struct student{
    int a;
    int b;
    int c;
    int f(){
        return b * 7 + c * 3;
    }
    void x(){
        if (this->f() >= 800 && b + c > 140)
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }
}q[1001];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> q[i].a >> q[i].b >> q[i].c;
        q[i].x();
    }
}