# 树

## 树上问题
### 树基础
#### 特殊树
- chain(链)
- star(星星)
- binary tree(二叉树)
- full binary tree(完整二叉树) 每个结点的度为 0 / 2
- complte binary tree(完全二叉树) 从左到右填 
- perfect binary tree(完美二叉树) 完美
#### 遍历
- dfs:
  - Preorder  `root->left->right`
  - Inorder   `left->root->right`
  - Postorder `left->right->root`
- [x] [P1827](../../luogu/P1827.cpp)
- bfs:
  - 使用队列
- Morris遍历 优化空间, 感觉用处小
### 树直径
> 最长路径
- [x] [P4016](../../luogu/P4016.cpp)
### 树中心
> 以某(1 / 2)个结点出发的最长链最短
### 树重心
- 定义: 删除某节点后, 剩下的子树节点最大值最小
- 求法: 1. DFS 2. DP
- [ ] [P1364](../../luogu/P1364.cpp)




## 二叉搜索树(BST)

一句话:  左孩子 < 根 < 右孩子 (中序遍历非降)

- 满足完全二叉树:
    1. 对于任何节点p, 左孩子2p, 右孩子2p+1
    2. $depth = \left \lceil log(n) \right \rceil$ n是叶子节点数量
- [x] [P5076](../../luogu/P5076.cpp)
## 平衡树

一句话: 以T为根节点的二叉树的每个结点的左子树和右子树的高度差<= 1,自动维持平衡

-[x] [P1801](../../luogu/P1801.cpp)
### AVL树

一句话: 新增节点高度来自动左旋右旋, 平衡因子
std : set,multiset,map,multimap(不过是红黑树)

### 红黑树

- 根节点，叶节点都是黑色
- 红黑红黑相间
- 任意节点到其可到达的叶节点所经过的黑色节点数量相同
> 频繁插入删除选红黑树
### Treap树


## 线段树
> 作用: 区间查询, 区间修改
- 原数组`a[n]`, 线段树组`d[N]`
- 线段树满足完全二叉树, $depth = \left \lceil log(n) \right \rceil$
- 总结点数量: $N = 2^{depth+1} -1$
- $\frac{N}{n} = \frac{2^{depth+1}-1}{n} < 4$直接N开成4n
- 堆式存储会填补一些无用的叶节点(为了保证完全二叉树)

堆式存储(二进制来看){
        1
   10       11
 100 101 110 111
}
### 猫树

- [x] [P3372](../../luogu/P3372.cpp) 一个模板题目, 用的懒标记, 位运算
- [x] [P3373](../../luogu/P3373.cpp) 加上了乘法标记

## 树状数组(Binary Indexed Tree)
```cpp
lowbit(int x){
  return x & (-x);
}
```
**单点修改, 快速求区间和**
- [P3374](../../luogu/P3374.cpp)
- [P1908](../../luogu/P1908.cpp) 逆序对
- [P1996](../../luogu/P1996.cpp) 相邻元素交换次数使得正序的次数==逆序对

## LCA(Lowest Common Ancestor)
- [P3379](../../luogu/P3379.cpp)
## Tree difference
### 点差分
- [P3128](../../luogu/P3128.cpp) 树上任意两点的路径修改, 求值只需要从上至下求差分的前缀和

### 边差分
- [P3398](../../luogu/P3398.cpp)

# 栈

## 单调栈
- [P5788](../../luogu/P5788.cpp)


# st表
- [P3865](../../luogu/P3865.cpp)

# 链表

## 静态链表 

- [P1160](../../luogu/P1160.cpp) // 用L[]和R[]和exist[]