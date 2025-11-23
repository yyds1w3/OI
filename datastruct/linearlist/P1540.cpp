// #include <iostream>
// using namespace std;
// typedef struct queue
// {
//     int a[101];
//     int size = 0;
//     int l = 1, r = 1;

//     queue(int size = 0, int l = 1, int r = 1) : size(size), l(l), r(r) {}
//     int get_size(){
//         return size;
//     }
//     int full(){
//         return l == r;
//     }
//     void push(int value){
//         a[r] = value;
//         r = (r % size) + 1;
//     }
//     void pop(){
//         l = (l % size) + 1;
//     }
//     bool exist(int value){
//         if (l < r){
//             for (int i = l; i < r; ++i){
//                 if (a[i] == value)
//                     return true;
//             }
//         }if (l == r){
//             for (int i = 1; i <= size; ++i){
//                 if (a[i] == value)
//                     return true;
//             }
//         }if (l > r){
//             for (int i = l; (i % size) != r - 1; ++i){
//                 if (a[i] == value)
//                     return true;
//             }
//         }

//         return false;
//     }
// }queue;

// int main()
// {
//     int M, N, C, ans = 0;
//     cin >> M >> N;
//     queue q(M);
//     cin >> C;
//     q.push(C);
//     ans++;
//     for (int i = 1; i < N; ++i)
//     {
//         cin >> C;
//         if (!q.exist(C)){
//             if (!q.full()){
//                 q.push(C);
//             }else{
//                 q.pop();
//                 q.push(C);
//             }
//             ans++;
//         }
//     }
//     cout << ans;
// }


#include <iostream>
#include <map>
#include <queue>
#include <ios>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[1001];
int main()
{
    IOS;
    queue<int> q;
    int M, N, ans = 0;
    cin >> M >> N;
    for (int i = 1; i <= N; ++i){
        int b;
        cin >> b;
        if (a[b] == 0){
            if (M > 0){
                q.push(b);
                ans++;
                a[b] = 1;
                M--;
            }else{
                int c = q.front();
                q.pop();
                q.push(b);
                ans++;
                a[c] = 0;
                a[b] = 1;
                M--;
            }
        }
    }
    cout << ans;
}