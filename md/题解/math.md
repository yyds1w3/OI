[markdown数学公式](https://www.cnblogs.com/bytesfly/p/markdown-formula.html)

# c++的模运算

```cpp
c++ 规定 / 向零取整导致余数可能是负数
assert(5 % 3 == 2);  // 5 / 3 == 1 ... 2
assert(5 % -3 == 2); // 5 / -3 = -1 ... 2
assert(-5 % 3 == -2); // -5 / 3 = -1 ... -2
assert(-5 % -3 == -2); // -5 / -3 = 1 ... -2
但是模严格来说是正数, 所以我们在余数为负数的时候应该加上除数来使得模为正数
```

# 杨辉三角求组合数
[P1358](../../normal/P1358.cpp)
$$
\begin{bmatrix}
1&C_0^n\\ 
1&|1&C_1^n\\
1&|2&1&C_2^n\\
1&|3&3&1&C_3^n\\
1&|4&6&4&1&C_4^n\\
\end{bmatrix}
$$