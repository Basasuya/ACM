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
#define MP make_pair
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
const int INF = 0x3f3f3f3f;
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


char seq[505][505];
int sum[505][505][4];
char color[] = "RGYB";
int n, m, q;


const int DEG = 10; // ceil(log2(max(n,m)))
const int N = 505;
int st[N][N][DEG][DEG];
int lg[N];
void build() {
    lg[1] = 0;
    for(int i = 2;i<N; i++){
        lg[i] = lg[i - 1];
        if((1 << (lg[i] + 1)) == i)
            lg[i]++;
    }
    for(int k = 0; k < DEG; ++k) {
        for(int l = 0; l < DEG; ++l) {
            if(k == 0 && l == 0) continue;
            for(int i = 1; i <= n; ++i) { // if i is 0 to n-1, just change it
                if(i + (1<<k) - 1 > n) break;
                for(int j = 1; j <= m; ++j) { // if j is 0 to m-1, just change it
                    if(j + (1<<l) - 1 > m) {
                        break;
                    }
                    if(k == 0) {
                        st[i][j][k][l] = max(st[i][j][k][l - 1], st[i][j + (1<<(l-1))][k][l - 1]);
                    } else {
                        st[i][j][k][l] = max(st[i][j][k - 1][l], st[i + (1<<(k-1))][j][k - 1][l]);
                    }
                }
            }
        }
    }
}


int query(int x1, int y1, int x2, int y2) { // x2 >= x1 && y2 >= y1
    int k = lg[x2 - x1 + 1];
    int l = lg[y2 - y1 + 1];
    return max(max(st[x1][y1][k][l], st[x1][y2 - (1<<l) + 1][k][l]), max(st[x2 - (1<<k) + 1][y1][k][l], st[x2 - (1<<k) + 1][y2 - (1<<l) + 1][k][l]));
}


int main() {
    
    while(~scanf("%d %d %d", &n, &m, &q)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%s", seq[i] + 1);
        }

        // memset(sum, 0, sizeof(sum));

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int k = 0; k < 4; ++k) {
                    sum[i][j][k] = sum[i][j - 1][k] + sum[i - 1][j][k] - sum[i - 1][j - 1][k] + (seq[i][j] == color[k]);
                }
            }   
        }

        auto ok = [&](int x, int y, int len) {
            if(len == 0) return true;
            if(x - len + 1 < 1 || x + len > n || y - len + 1 < 1 || y + len > m) return false;
            bool t1 = (sum[x][y][0] - sum[x - len][y][0] - sum[x][y - len][0] + sum[x - len][y - len][0]) == len * len;
            bool t2 = (sum[x][y + len][1] - sum[x - len][y + len][1] - sum[x][y][1] + sum[x - len][y][1]) == len * len;
            bool t3 = (sum[x + len][y][2] - sum[x][y][2] - sum[x + len][y - len][2] + sum[x][y - len][2]) == len * len;
            bool t4 = (sum[x + len][y + len][3] - sum[x][y + len][3] - sum[x + len][y][3] + sum[x][y][3]) == len * len;
            return t1 && t2 && t3 && t4;
        };

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int l = 0; int r = n;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(ok(i, j, mid)) {
                        l = mid + 1;
                    } else r = mid - 1;
                }
                st[i][j][0][0] = r;
                // debug(i, j, r);
            }
        }

        build();

        auto ok2 = [&](int x1, int y1, int x2, int y2, int len) {
            if(len == 0) return true;
            int _x1 = x1 + len - 1; int _x2 = x2 - len;
            int _y1 = y1 + len - 1; int _y2 = y2 - len;
            if(_x1 > _x2 || _y1 > _y2) return false;
            if(query(_x1, _y1, _x2, _y2) >= len) return true;
            else return false;
        };

        while(q --) {
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            
            int l = 0; int r = min( (r2 - r1 + 1) / 2, (c2 - c1 + 1) / 2);

            while(l <= r) {
                int mid = (l + r) >> 1;
                if(ok2(r1, c1, r2, c2, mid)) l = mid + 1;
                else r = mid - 1;
            }
            printf("%d\n", 4 * r * r);
        }
    }
    return 0;   
}