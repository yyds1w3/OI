#include <bits/stdc++.h>
using namespace std;
stack<num> st;
struct num{
    int c;
    int base;
    int id;
    int p;
    num(int c, int base, int id, int p) : c(c), base(base), id(id), p(p) {}
};
int qpow(int base, int p){
    int result = 1;
    while(p){
        if (p % 2 == 1) result *= base ;
        base *= base;
        p >>= 1;
    }
}
int value(const num& n){
    return n.c *  qpow(n.base, n.p);
}
num dao(num n){
    if (n.p == 0){
        n.c = 0;
    }
    n.c *= n.p;
    n.p--;
    return n;
}
int add_dao(num& u, num& v){
    return value(dao(u)) + value(dao(v));
}
int mult_dao(num& u, num& v){
    return value(dao(v)) * value(v) + value(v) * value(dao(u));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    while(ss >> token){
        if (token == "*"){
            st.push(num(0,0,-1,0));
        }
        else if (token == "+"){

        }else if (token == "-"){

        }
        }else{

        }
    }
    
}