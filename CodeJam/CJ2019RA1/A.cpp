#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int N = 405;
int R, C;
struct Node{
    int fr, to, nx, dis;
}E[N * N * 2];
int vis[N];
int cnt[N];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
int ok(int a, int b) {
    int r1 = a / C;
    int c1 = a % C;
    int r2 = b / C;
    int c2 = b % C;
    if(r1 != r2 && c1 != c2 && ( (r1 - c1) != (r2 - c2) ) && ( (r1 + c1) != (r2 + c2) ) ) return 1;
    else return 0; 
}

int choose[405];
int result[405];

bool dfs(int dep, int x) {
    // printf("%d %d\n", dep, x);
    if(dep == R*C) {
        for(int i = 0; i < R * C; ++i) result[i] = choose[i];
        return true;
    } else if(dep == 0) {
        for(int i = 0; i < R * C; ++i) {
            vis[i] = 1;
            choose[dep] = i;
            // for(int j = head[i]; ~j; j = E[j].nx) {
            //     cnt[E[j].to] --;
            // }
            if(dfs(dep + 1, i)) 
                return true;
            // for(int j = head[i]; ~j; j = E[j].nx) {
            //     cnt[E[j].to] ++;
            // }
            vis[i] = 0;
        }
    } else {
        pair<int, int> mov[405];
        int tot2 = 0;
        for(int i = head[x]; ~i; i = E[i].nx) {
            // printf("out %d %d\n", i, x);
            int to = E[i].to;
            if(!vis[to]) {
                mov[tot2 ++] = make_pair(cnt[to], to);
            }
        }
        // assert(tot2 < 405 * 405);
        sort(mov, mov + tot2);
        for(int i = 0; i < tot2; ++i) {
            int to = mov[i].second;
            vis[to] = 1;
            choose[dep] = to;
            for(int j = head[to]; ~j; j = E[j].nx) {
                // printf("in %d %d\n", j, to);
                cnt[E[j].to] --;
            }
            if(dfs(dep + 1, to)) 
                return true;
            for(int j = head[to]; ~j; j = E[j].nx) {
                cnt[E[j].to] ++;
            }
            vis[to] = 0;
        }
    }
    return false;
}
int main() {
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        
        scanf("%d %d", &R, &C);

        for(int i = 0; i < R*C; ++i) head[i] = -1, vis[i] = 0, cnt[i] = 0;
        tot = 0;
        for(int i = 0; i < R * C; ++i) {
            for(int j = i + 1; j < R * C; ++j) {
                if(i != j && ok(i, j) ) {
                    add(i, j);
                    cnt[j] ++;
                    add(j, i);
                    cnt[i] ++;
                }
            }
        }

        bool success = dfs(0, -1);
        // printf("hhh\n");

        printf("Case #%d: ", cas);
        printf("%s\n", (success == 0) ? "IMPOSSIBLE" : "POSSIBLE");
        if(success) {
            for(int i = 0; i < R * C; ++i) {
                printf("%d %d\n", (result[i] / C) + 1, (result[i] % C) + 1);
            }
        }
    }
    return 0;
}

/*
2
5 5
20 20
*/



