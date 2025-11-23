    #include <iostream>
    using namespace std;
    char a[10];
    int main(){
        char c;
        int i = 0;
        int ans = 0;
        while(true){
            if (isdigit(c = getchar())){
                if (i < 9)
                    ans += (c - '0') * (i+1);
                a[i++] = c;
            }else if(c == 'X' && i == 9){
                a[i++] = c;
            }
            if (i == 10){
                ans %= 11;
                break;
            }
        }
        if ((ans == a[9] - '0') || (a[9] == 'X' && ans == 10)){
            cout << "Right";
        }else{
            for (int i = 0; i <= 8; ++i){
                cout << a[i];
                if (i == 0 || i == 3 || i == 8) cout << "-";
            }
            ans == 10 ? cout << "X" : cout << ans;
        }
    }