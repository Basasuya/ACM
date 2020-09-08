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

const int MAXN = 4e3 + 5;
char color[MAXN];
int val[MAXN];

int B[MAXN][MAXN];
int W[MAXN][MAXN];
int dp[MAXN][MAXN];
int N;

int tree[2][MAXN];

void Update(int pos, int val, int flag) {
    for(int i = pos; i <= N; i += i & -i) {
        tree[flag][i] += val;
    }
}

int Sum(int pos, int flag) {
    int sum = 0;
    for(int i = pos; i; i -= i & -i) {
        sum += tree[flag][i];
    }
    return sum;
}

int main() {
    while(~scanf("%d", &N)) {
        for(int i = 0; i < 2 * N; ++i) {
            char tmp[10];
            scanf("%s %d", tmp, &val[i]);
            color[i] = tmp[0];
        }

        for(int i = 0; i < 2 * N; ++i) {
            if(color[i] == 'B') {
                Update(val[i], 1, 0);
                for(int j = 0; j <= N; ++j) {
                    B[val[i]][j] = i + 1 - Sum(j, 1) - Sum(val[i], 0);
                }
            } else {
                Update(val[i], 1, 1);
                for(int j = 0; j <= N; ++j) {
                    W[j][val[i]] = i + 1 - Sum(j, 0) - Sum(val[i], 1);
                }
            }
        }

        memset(dp, INF, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j <= N; ++j) {
                if(i == 0 && j == 0) continue;

                if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + B[i][j]);
                if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + W[i][j]);
            }
        }

        printf("%d\n", dp[N][N]);
    }
    return 0;
}