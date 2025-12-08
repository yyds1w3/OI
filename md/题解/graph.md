## DFS

- [x] [P1706](../../luogu/P1706.cpp)
- [x] [UVA524](../../luogu/UVA524.cpp)

## BFS
求边权为1时的最短路径, 第一次碰到的就是最短路径, 按层扩散
时间复杂度$O(V+E)$ $V是点数，E是边数$
- [x] [P1746](../../luogu/P1746.cpp)
- [x] [P1415](../../luogu/P1451.cpp)
- [x] [CF-520-B](../../CF/div2/520.cpp)

## 图的存储
- 邻接表(Adjacency List)
- [x] [P5318](../../luogu/P5318.cpp)

## Dijkstra
> 单点最短路径(边权), 本质是贪心的dp, dist就是dp数组
> Dijkstra 的正确性，本质上就是证明：一旦一个点 $u$ 被从优先队列中取出（即被“结算”），它当前的距离 $d(u)$ 必然是它的最短距离。如果一个路径 $P$ 是最短路径，那么 $P$ 的任何子路径 $P'$ 也是从 $P'$ 起点到 $P'$ 终点的最短路径。这就是最优子结构
- [x] [P4779](../../luogu/P4779.cpp) // Dijklstra
- [x] [P3371](../../luogu/P3371.cpp) // spfa
- [x] [P1629](../../luogu/P1629.cpp) // 反向Dij
- [ ] [P4568](../../luogu/P4568.cpp)

## Floyd
> 任意两点的最短路径
- [x] [P3647](../../luogu/P3647.cpp)

## 并查集(DSU)和Kruskal
- [x] [P3366](../../luogu/P3366.cpp) // 连通各个节点需要的最小代价
- [x] [P1195](../../luogu/P1195.cpp)

### 带权值的并查集
- [x] [Div2-1167-C](../../CF/div2/1167/C.cpp)

## DAG有向无环图(Directed Acyclic Graph)

### 拓扑排序(Topological Sort)
- 入度(In-degree)

### Kahn
遍历每个节点的下一个节点, 如果进度为0就入队
- [x] [P3644](../../luogu/P3644.cpp)

### SCC强连通分量
> 有向图里有一堆点可以互相到达(等同于有环)
### Tarjan求SCC
- [x] [P2863](../../luogu/P2863.cpp)
### 缩点
- [x] [P3387](../../luogu/P3387.cpp)