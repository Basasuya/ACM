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

const int N = 1e5 + 5;
struct Node{
    int fr, to, nx, dis;
}E[N << 2];
int head[N]; int tot = 0; 

int dfn[N], low[N], belong[N], isbridge[N << 2];
int bcc_cnt, dfn_tim;
int Father[N];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dfn_tim;
    // cout << u <<" "<< dfn[u] << endl;
    for(int i = head[u]; ~i; i = E[i].nx) {
        int v = E[i].to;
        if(!dfn[v]) {
            tarjan(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                isbridge[i] = isbridge[i ^ 1] = 1;
            }
        } else if(dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void dfs(int u) {
    dfn[u] = 1;
    belong[u] = bcc_cnt;
    for(int i = head[u]; ~i; i = E[i].nx) {
        int v = E[i].to;
        if(!isbridge[i] && !dfn[v]) {
            dfs(v);
        }
    }
}


void find_ebcc() {
    dfn_tim = bcc_cnt = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(isbridge,0,sizeof isbridge);
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i])
            tarjan(i,-1);
    }
    memset(dfn, 0, sizeof dfn);
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            bcc_cnt++;
            dfs(i);
        }
    }
}
