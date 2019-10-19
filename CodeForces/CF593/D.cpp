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
#define mp make_pair
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define bitCount(a)  __builtin_popcount(a)
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MAXN = 1e5 + 5;

int obX[MAXN], obY[MAXN];
vector<int> col[MAXN];
vector<int> row[MAXN];
ll ans;

int stx, edx, sty, edy;
bool suc;
void dfs(int x, int y, int dir) {
    // debug(x, y, dir);
    // if(x >= stx && x <= edx && y >= sty && y <= edy); else return;

    if(dir == 1) {
        int tt = lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin();
        int newY = (tt == row[x].size()) ? edy : row[x][tt] - 1;
        newY = min(newY, edy);
        edy = newY - 1;
        ans += newY - y;
        if(newY - y <= 0 && (x != 1 && y != 1)) return;
        dfs(x, newY, 2);
    } else if(dir == 2) {
        int tt = lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin();
        int newX = (tt == col[y].size()) ? edx : col[y][tt] - 1;
        newX = min(newX, edx);
        edx = newX - 1;
        ans += newX - x;
        if(newX - x <= 0) return;
        dfs(newX, y, 3);    
    } else if(dir == 3) {
        int tt = lower_bound(row[x].begin(), row[x].end(), y) - row[x].begin(); tt --;
        int newY = (tt == -1) ? sty : row[x][tt] + 1;
        newY = max(newY, sty);
        sty = newY + 1;
        ans += y - newY;
        if(y - newY <= 0) return;
        dfs(x, newY, 4);
    } else if(dir == 4) {
        int tt = lower_bound(col[y].begin(), col[y].end(), x) - col[y].begin(); tt --;
        int newX = (tt == -1) ? stx : col[y][tt] + 1;
        newX = max(newX, stx);
        stx = newX + 1;
        ans += x - newX;
        if(x - newX <= 0) return;
        dfs(newX, y, 1); 
    } 
}  

int main() {
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        ans = 1;
        ll correctAns = 1ll * n * m - k;
        stx = 2; edx = n; 
        sty = 1; edy = m;
        

        for(int i = 1; i <= n; ++i) {
            row[i].clear();
            // col[i].clear();
        }
        for(int i = 1; i <= m; ++i) {
            col[i].clear();
        }

        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &obX[i], &obY[i]);
            row[obX[i]].push_back(obY[i]);
            col[obY[i]].push_back(obX[i]);
        }

        

        for(int i = 1; i <= n; ++i) {
            sort(row[i].begin(), row[i].end());
        }
        for(int i = 1; i <= m; ++i) {
            sort(col[i].begin(), col[i].end());
        }


        // for(int i = 1; i <= n; ++i) {
        //     for(int j = 1; j <= m; ++j) {
        //         int tt = lower_bound(row[i].begin(), row[i].end(), j) - row[i].begin();
        //         if(tt == row[i].size() || row[i][tt] != j) printf(".");
        //         else printf("#");
        //     }
        //     printf("\n");
        // }

        dfs(1, 1, 1);


        printf("%s\n", ans == correctAns ? "Yes" : "No" ); 
    }
    return 0;
}


/*


5 5 22
4 1
5 1
1 2
2 2
3 2
4 2
5 2
1 3
2 3
3 3
4 3
5 3
1 4
2 4
3 4
4 4
5 4
1 5
2 5
3 5
4 5
5 5

5 5 19
4 1
5 1
4 2
5 2
1 3
2 3
3 3
4 3
5 3
1 4
2 4
3 4
4 4
5 4
1 5
2 5
3 5
4 5
5 5
*/