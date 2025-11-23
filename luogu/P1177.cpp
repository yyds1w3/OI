#include <iostream>
using namespace std;
#define LEN 100005
int a[LEN];
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *a, int size){
    for (int i = 0; i < size; ++i){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
int size(int *arr){
    int i;
    for (i = LEN - 1; i >= 0; --i){
        if (arr[i] != 0) break;
    }
    return i + 1;
}
void SiftDown(int *arr, int n, int i){
    // 因为堆是完全二叉树, l=2*i+1, r=2*i+2,序号从0开始
    int l,r,ma;
    while (true){
        l = 2 * i + 1;
        r = 2 * i + 2;
        ma = i;
        if (l < n && arr[l] > arr[ma]){
            ma = l;
        }
        if (r < n && arr[r] > arr[ma]){
            ma = r;
        }
        if (ma == i) break;
        swap(arr + i, arr + ma);

        i = ma;
    }
}


void HeapSort(int *arr){
    // 完全二叉树的叶子节点 n / 2 + 1
    for (int i = size(arr) / 2 - 1; i >= 0; --i){
        SiftDown(arr, size(arr), i);
    }
    for (int i = size(arr) - 1; i >= 0; --i){
        swap(arr, arr + i);
        SiftDown(arr, i, 0);
    }
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    HeapSort(a);
    for (int i = 0; i < N; ++i){
        cout << a[i] << " ";
    }
}