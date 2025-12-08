#include <bits/stdc++.h>
#define down 0.996
using namespace std;

int n;
struct node {
    int x, y, w;
} object[2005];

// 记录全局最优解 (Best Answer)
double best_x, best_y, min_energy;

double energy(double x, double y) {
    double r = 0, dx, dy;
    for (int a = 1; a <= n; a++) {
        dx = x - object[a].x;
        dy = y - object[a].y;
        r += sqrt(dx * dx + dy * dy) * object[a].w;
    }
    return r;
}

void sa() {
    double t = 3000;
    // 探险者坐标 (Current State)
    double now_x = best_x; 
    double now_y = best_y;
    
    while (t > 1e-15) {
        // 在当前探险者周围随机跳
        double ex = now_x + (rand() * 2 - RAND_MAX) * t;
        double ey = now_y + (rand() * 2 - RAND_MAX) * t;
        
        double ew = energy(ex, ey);
        double de = ew - min_energy; // 和全局最优比？不，通常是和当前状态比
        // 但为了简单，我们先跟当前状态比
        double current_energy = energy(now_x, now_y);
        double diff = ew - current_energy;

        // 1. 如果比全局最优还牛，赶紧记录下来！
        if (ew < min_energy) {
            min_energy = ew;
            best_x = ex;
            best_y = ey;
            // 既然这么牛，探险者也过去
            now_x = ex;
            now_y = ey;
        }
        // 2. 如果只是接受概率跳转 (Metropolis)
        else if (ew < current_energy || exp(-diff / t) * RAND_MAX > rand()) {
            now_x = ex;
            now_y = ey;
        }
        
        t *= down;
    }
}

int main() {
    srand(time(0)); // 别忘了随机种子
    cin >> n;
    double sx = 0, sy = 0;
    for (int a = 1; a <= n; a++) {
        scanf("%d%d%d", &object[a].x, &object[a].y, &object[a].w);
        sx += object[a].x;
        sy += object[a].y;
    }
    
    // 初始化
    best_x = sx / n;
    best_y = sy / n;
    min_energy = energy(best_x, best_y);

    // 卡时大法
    while ((double)clock() / CLOCKS_PER_SEC < 0.95) {
        sa();
    }
    
    printf("%.3lf %.3lf\n", best_x, best_y);
    return 0;
}