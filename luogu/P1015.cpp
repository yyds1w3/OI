#include <iostream>
#include <cstring>
using namespace std;
#define LEN 104
int a[LEN], b[LEN], c[LEN];

void clear(int a[]){
    memset(a, 0, sizeof(int) * LEN);
}
void read(int a[]){
    clear(a);
    static char s[LEN];
    scanf("%s", s);
    int i = strlen(s);
    for (int j = i - 1; j >= 0; --j){
        if (s[i-j-1] >= '0' && s[i-j-1] <= '9')
            a[j] = s[i - j - 1] - '0';
        else
            a[j] = s[i - j - 1] - 'A' + 10;
    }
}
void add(int a[], int b[], int c[], int N){
    clear(c);
    for (int i = 0; i < LEN; ++i){
        c[i] += a[i] + b[i];
        if (c[i] >= N){
            c[i+1] += 1;
            c[i] -= N;
        }
    }
}

int len(int a[]){
    int i;
    for (i = LEN - 1; i >= 0; --i){
        if (a[i] != 0) break;
    }
    return i + 1;
}

void reverse(int a[], int b[]){
    clear(b);
    int lena = len(a);
    for (int i = 0; i < lena; ++i){
        b[i] = a[lena - 1 - i];
    }
}
bool huiwen(int a[]){
    int lena = len(a);
    for (int i = 0; i < lena / 2 + 1; ++i){
        if (a[i] != a[lena - 1 - i])
            return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    read(a);
    int i;
    for (i = 0; i < 30; ++i){
        if (i % 2 == 0){
            reverse(a, b);
            add(a,b,c,N);
            if (huiwen(c))
                break;
        }else{
            reverse(c,b);
            add(c,b,a,N);
            if (huiwen(a))
                break;
        }
    }
    if (i == 30) cout << "Impossible!";
    else cout << "STEP=" << i + 1;

}