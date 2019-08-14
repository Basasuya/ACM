#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int) a.size()
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
template <class T>
int gmax(T &a, T b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
int gmin(T &a, T b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
using namespace std;

const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;
char seq[MAXN];
int dis[15][15];
int answer[15][15];

// struct Node{
//     int fr, to, nx, dis;
// }E[105];
// int head[15]; int tot = 0;
// void add(int fr, int to) {
//     E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
// }
// struct Hode{
//   int po, di;
//   Hode(int a=0, int b=0):po(a), di(b){}
//   bool operator < (const Hode & T) const {
//     return di > T.di;
//   }
// };

// int dis[15], vis[15];
// void dij(int s, int t) {
//   priority_queue<Hode> Q;
//   memset(dis, INF, sizeof(dis));
//   dis[s] = 0;
//   memset(vis, 0, sizeof(vis));
//   Q.push(Hode(s, dis[s]));

//   while(!Q.empty()) {
//     int po = Q.top().po; Q.pop();
//     if(vis[po]) continue;
//     vis[po] =  1;
//     for(int i = head[po]; ~i; i = E[i].nx) {
//       int to = E[i].to;
//       if(dis[to] > dis[po] + E[i].dis) {
//         dis[to] = dis[po] + E[i].dis;
//         Q.push(Hode(to, dis[to]));
//       }
//     }
//   }
// }
int solve(int x, int y) {
    // printf("%d %d\n", x, y);
    memset(dis, INF, sizeof(dis));

    for (int i = 0; i < 10; ++i) {
        dis[i][(i + x) % 10] = 1;
        dis[i][(i + y) % 10] = 1;
    }

    for (int k = 0; k < 10; k++) {
        for (int f = 0; f < 10; f++) {
            for (int t = 0; t < 10; t++) {
                // if (f == t || f == k || t == k) continue;
                if (dis[f][k] != INF && dis[k][t] != INF) {
                    int total = dis[f][k] + dis[k][t];
                    if (total < dis[f][t] || dis[f][t] == INF) {
                        dis[f][t] = total;
                    }
                }
            }
        }
    }
    // printf("%d %d %d\n", x, y, dis[0][8]);
    int sum = 0;
    for (int len = strlen(seq), i = 1; i < len; ++i) {
        if(dis[seq[i-1] - '0'][seq[i] - '0'] == INF) return -1;
        sum += dis[seq[i-1] - '0'][seq[i] - '0'];
    } 
    return sum - strlen(seq) + 1;
}
int main() {
    while (~scanf("%s", seq)) {
        for (int i = 0; i < 10; ++i) {
            for (int j = i; j < 10; ++j) {
                answer[i][j] = solve(i, j);
            }
        }

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (j) printf(" ");
                if (i > j)
                    printf("%d", answer[j][i]);
                else
                    printf("%d", answer[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}