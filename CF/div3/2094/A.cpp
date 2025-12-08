#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s1, s2, s3, s;
    s.resize(3);
    for (int i = 0 ;i < n; ++i){
        cin >> s1 >> s2 >> s3;
        s[0] = s1[0];
        s[1] = s2[0];
        s[2] = s3[0];
        cout << s << endl;
        s1.clear(), s2.clear(), s3.clear();
    }
}