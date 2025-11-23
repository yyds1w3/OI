#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    char d , e;
    cin >> a >> b >> c;
    bool flag = 0; 
    while (cin >> e){
        if (e =='-'){
            flag = 1;
            continue;
        }
        if (flag){
            if (e > d && ((e <='9' && d >='0') || (e <='z' && d >= 'a'))){
                if (c == 1){
                    for (int i = d+1; i < e; ++i)
                    {
                        char p = i;
                        if (a == 2){
                            p -= 32;
                        } else if (a == 3){
                            p = '*';
                        }
                        for (int j = 0; j < b; ++j)
                            cout << p;
                    }
                }else if (c == 2){
                    for (int i = e-1; i > d; --i)
                    {
                        char p = i;
                        if (a == 2){
                            p -= 32;
                        } else if (a == 3){
                            p = '*';
                        }
                        for (int j = 0; j < b; ++j)
                            cout << p;
                    }       
                }
            }else{
                cout << "-";
            }
        }
        cout << e;
        d = e;
        
    }
}   