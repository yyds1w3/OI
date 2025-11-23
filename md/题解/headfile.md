# 输入输出

```cpp
#include <iostream>
#include <iomanip>
#include <ios>
// 控制位数
cout << setprecision(3) << fixed << num << endl; // setprecision是有效数字位数， fixed固定小数点，变为了小数点位数
还有scientfic,hexfloat,default的输出方式
// 控制场宽
cout << setw(3) << x; // 占据3个空格, 默认右对齐
cout << left << setw(3) // 左对齐
// 加速输入输出
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

// cin卡住
cin >> a[i] >> b[i];通常会在最后一个卡住的原因是因为 1 3 的3后面没有空格符号， cin不知道3是你输入的还是3.......是你输入的e'm
```


# memset
```c++
#include <cstring>

```

# bitset
```cpp
bitset<size> bs; // 默认全为0
bs.set() // 全为1
bs.reset() // 全为0
bs[]


```
# algorithm
```cpp
next_permutation(a, a+n); // 返回下一个全排列 1 2 3 --> 1 3 2

```