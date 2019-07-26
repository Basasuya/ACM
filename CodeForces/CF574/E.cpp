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


int n, m, a, b;
const int MAXN = 3005;
int val[MAXN][MAXN];
int maxx[MAXN][MAXN];


struct dl {
    deque<int> q, b;
    void push(int x, int y) {
        while (!q.empty() && x < q.back()) {
            q.pop_back();
            b.pop_back();
        }
        q.push_back(x);
        b.push_back(y);
    }
    void pop(int x) {
        while (!q.empty() && x >= b.front()) {
            b.pop_front();
            q.pop_front();
        }
    }
    void clear() {
        while (!q.empty()) {
            q.pop_front();
            b.pop_front();
        }
    }
    int front() {
        return q.front();
    }
} Q;

int main() {
    while(~scanf("%d %d %d %d", &n, &m, &a, &b)) {
        int g0, x, y, z;
        scanf("%d %d %d %d", &g0, &x, &y, &z);
        val[1][1] = g0;
        for(int i = 1; i < n * m; ++i) {
            int t1 = i / m; int t2 = i % m;
            int t3 = (i-1) / m; int t4 = (i-1) % m;
            val[t1 + 1][t2 + 1] = (1ll * val[t3 + 1][t4 + 1] * x + y) % z;
        }

        for(int i = 1; i <= n; ++i) {
            Q.clear();
            for(int j = 1; j <= m; ++j) {
                Q.push(val[i][j], j);
                if(j >= b) {
                    Q.pop(j - b);
                    maxx[i][j - b + 1] = Q.front();
                }
            }
        }
        

        ll result = 0;
        for(int j = 1; j <= m - b + 1; ++j) {
            Q.clear();
            for(int i = 1; i <= n; ++i) {
                Q.push(maxx[i][j], i);
                if(i >= a) {
                    Q.pop(i - a);
                    result = result + Q.front();
                }
            }
        }

        printf("%lld\n", result);
    }
    return 0;
}