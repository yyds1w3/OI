#define LEN 1004
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[LEN], b[LEN], c[LEN], d[LEN];
void clear(int a[]){
    memset(a, 0, sizeof(int) * LEN);
}
void read(int a[LEN]){
    string s;
    s.reserve(LEN);
    cin >> s;

    int len = s.length();
    clear(a);
    for (int i = 0; i < len; ++i){
        a[len - i - 1] = s.at(i) - '0';
    }
}

void print(int a[LEN]){
    int i;
    for (i = LEN - 1; i >= 1; --i){
        if(a[i] != 0) break;
    }
    for (; i >= 0; --i){
        putchar(a[i] + '0');
    }
    putchar('\n');
}

void add(int a[LEN], int b[LEN], int c[LEN]){
    clear(c);

    for (int i = 0; i < LEN; i++){
        c[i] = a[i] + b[i];
        if (c[i] >= 10){
            c[i+1]++;
            c[i] -= 10;
        }
    }
}

void sub(int a[LEN], int b[LEN], int c[LEN]){
    clear(c);

    for (int i = 0; i < LEN; ++i){
        c[i] = a[i] - b[i];
        if (c[i] < 0){
            c[i+1] -= 1;
            c[i] += 10;
        }
    }
}

// b --> int  a --> int[]
void mult_short(int a[LEN], int b, int c[LEN]){
    clear(c);

    for (int i = 0; i < LEN; ++i){
        c[i] = b * a[i];

        if (c[i] >= 10){
            c[i+1] += c[i] / 10;
            c[i] %= 10; 
        }
    }
}

void mult_high(int a[LEN], int b[LEN], int c[LEN]){
    clear(c);

    for (int i = 0; i < LEN; ++i){
        for (int j = 0; j <= i; ++j) 
            // 个位 = 个位 * 个位 ， 百位 = 个位 * 百位 + 十位 * 十位 + 百位 * 个位
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10){
            c[i+1] += c[i] / 10;
            c[i] %= 10; 
        }
    }
}
// last_dg 最后一位的下标 len 除数的长度
// a 12345 b 233 last_dg = 1 比较234 和233
bool greater_eq(int a[LEN], int b[LEN], int last_dg, int len){
    // 1. a 比 b长
    if (a[last_dg + len] != 0) return true;
    // 2. 逐位比较
    for (int i = len-1; i >= 0; --i){
        if (a[last_dg + i] > b[i]) return true;
        if (a[last_dg + i] < b[i]) return false;
    }
    // 3. 相等
    return true;
}

void div(int a[LEN], int b[LEN], int c[LEN], int d[LEN]){
    clear(c);
    clear(d);

    // 1. 确定a,b最高位的下标
    int la, lb;
    for (la = LEN - 1; la >= 0; --la){
        if (a[la] != 0) break; 
    }
    for (lb = LEN - 1; lb >= 0; --lb){
        if (b[lb] != 0) break; 
    }
    if (lb == -1){
        puts("除数不能为0");
        return;
    }

    // 2.c商，d余数
    for (int i = 0; i <= la; ++i) d[i] = a[i];
    for (int i = la - lb; i >= 0; --i){
        // 开始减法
        while (greater_eq(d,b,i,lb+1)){
            for (int j = 0; j < lb + 1; ++j){
                d[i+j] -= b[j];
                if (d[i+j] < 0){
                    d[i+j+1] -= 1;
                    d[i+j] += 10;
                }
            }
            c[i] += 1;
        }
        
    }
}
int main(){
    read(a);
    print(a);
    read(b);
    print(b);
    add(a,b,c);
    print(c);
    sub(a,b,c);
    print(c);
    mult_high(a,b,c);
    print(c);
    div(a,b,c,d);
    print(c);
}