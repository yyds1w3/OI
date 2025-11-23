#include <iostream>
#include <vector>
#include <random>
#define MIN(x, y) ((x) < (y) ? x : y)
#define LEN 10000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int size(int *arr)
{
    int i;
    for (i = LEN - 1; i >= 0; --i)
    {
        if (arr[i] != 0)
            break;
    }
    return i + 1;
}
// O(n^2)
void SelctionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr + k, arr + i);
    }
}
// O(n^2)
void BubbleSort(int *arr, int size)
{
    int flag;
    while (size > 1)
    {
        flag = 1;
        for (int i = 0; i < size - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
                flag = 0;
            }
        }
        size--;
        if (flag == 1)
            break;
    }
}

// O(n^2)
void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int base = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > base)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = base;
    }
}

// O(nlogn)
int Parition(int *arr, int left, int right)
{
    int i = left, j = right;
    int base = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= base)
        {
            j--;
        }
        while (i < j && arr[i] <= base)
        {
            i++;
        }
        swap(arr + i, arr + j);
    }
    swap(arr + i, arr + left);
    return i;
}
void QuickSort(int *arr, int left, int right)
{
    while (left < right)
    {
        int pivot = Parition(arr, left, right);
        if (pivot - left < right - pivot)
        {
            QuickSort(arr, left, pivot - 1);
            left = pivot + 1;
        }
        else
        {
            QuickSort(arr, pivot + 1, right);
            right = pivot - 1;
        }
    }
}
// 两个子部分, 取出两个部分中较小的数放在前面
void Merge(int *arr, int left, int mid, int right)
{
    static int tmp[LEN];
    // [left, mid] [mid+1, right]
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= right)
    {
        tmp[k++] = arr[j++];
    }

    for (k = 0; k < LEN; ++k)
    {
        arr[left + k] = tmp[k];
    }
}
// O(nlogn) 相比较快排是稳定的排序,但是会占用O(n)辅助数组的栈空间
void MergeSort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    // 类似后序遍历 左 右 本
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    // 当arr2个元素，则一定排好序了，返回一个排好序的数组a1
    // 当数组a1,a2被返回则a1+a2一定也排好序了
    Merge(arr, left, mid, right);
}
//
void SiftDown(int *arr, int n, int i)
{
    // 因为堆是完全二叉树, l=2*i+1, r=2*i+2,序号从0开始
    int l, r, ma;
    while (true)
    {
        l = 2 * i + 1;
        r = 2 * i + 2;
        ma = i;
        if (l < n && arr[l] > arr[ma])
        {
            ma = l;
        }
        if (r < n && arr[r] > arr[ma])
        {
            ma = r;
        }
        if (ma == i)
            break;
        swap(arr + i, arr + ma);

        i = ma;
    }
}

void HeapSort(int *arr)
{
    // 完全二叉树的叶子节点 n / 2 + 1
    for (int i = size(arr) / 2 - 1; i >= 0; --i)
    {
        SiftDown(arr, size(arr), i);
    }
    for (int i = size(arr) - 1; i >= 0; --i)
    {
        swap(arr, arr + i);
        SiftDown(arr, i, 0);
    }
}
// 先划分0-0.2,0.2-0.4,0.4-0.6....再对每个桶排序
void BucketSort(std::vector<float> &arr)
{
    int k = arr.size() / 2; // k个桶
    std::vector<std::vector<float>> buckets;
    buckets.reserve(k);
    // 假设 num在[0,1)
    for (float num : arr)
    {
        buckets[k * num].push_back(num);
    }

    for (std::vector<float> &bucket : buckets)
    {
        // 排序算法
    }

    int i = 0;
    for (std::vector<float> &bucket : buckets)
    {
        for (float num : bucket)
        {
            arr[i++] = num;
        }
    }
}
// 有序列表才能用二分搜索
int BinarySearch(int *arr, int size, int target)
{
    if (size == 0)
        return -1;
    int i = 0, j = size - 1, m;
    while (i <= j)
    {
        m = i + (j - i) / 2;
        if (arr[m] > target)
            j = m - 1;
        else if (arr[m] < target)
        {
            i = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}

int *GeneratRandArr(int maxSize, int maxValue)
{
    int size = rand() % maxSize + 1;
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % (2 * maxValue + 1) - maxValue;
    }
    return arr;
}

int *CopyArray(int *a, int maxSize)
{
    int *arr = new int[maxSize];
    for (int i = 0; i < maxSize; ++i)
    {
        arr[i] = a[i];
    }
    return arr;
}
int main()
{
    srand(time(0));
    int maxSize = 10;
    int maxValue = 501;
    int times = 20;
    for (int i = 0; i < times; ++i){
        int *arr = GeneratRandArr(maxSize, maxValue);
        int *arr1 = CopyArray(arr, maxSize);
        int *arr2 = CopyArray(arr, maxSize);
        int *arr3 = CopyArray(arr, maxSize);
        BubbleSort(arr1, maxSize);
        InsertionSort(arr2, maxSize);
        QuickSort(arr3, 0, maxSize);
    
        display(arr, maxSize);
        display(arr1, maxSize);
        display(arr2, maxSize);
        display(arr3, maxSize);
        delete (arr);
        delete (arr1);
        delete (arr2);
        delete (arr3);
        std::cout << std::endl;
    }
}
