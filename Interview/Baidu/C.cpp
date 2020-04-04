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

const int MAXN = 6005;
int X[MAXN], Y[MAXN];

int main() {
    int n, m, K;
    while(~scanf("%d %d %d", &n, &m, &K)) {
        for(int i = 0; i < K; ++i) {
            scanf("%d %d", &X[i], &Y[i]);
        }

        if(K == 1) {
            double ans = (1.0 * n * Y[0] - 1.0 * m * X[0]) / (n * 1.0 - 2 * X[0]);
            printf("%.4f\n", ans);
            continue;
        }

        if(K == 2) {
            double ans = sqrt(1.0 * (X[0] - X[1]) * (X[0] - X[1]) + 1.0 * (Y[0] - Y[1]) * (Y[0] - Y[1]) ) / 2;
            printf("%.4f\n", ans);
            continue;
        }
        
        double ans = -1;

        vector<int> ord;
        for(int i = 0; i < K; ++i) {
            ord.push_back(i);
        }

        for(int i = 0; i < K; ++i) {
            for(int j = i + 1; j < K; ++j) {
                double xx = (X[i] + X[j]) / 2.0; double yy = (Y[i] + Y[j]) / 2.0;
                double a = (1.0 * n * yy - 1.0 * m * xx) / (n * 1.0 - 2 * xx);
                double b = m - a;
                double tmp = min(a, m - a);
                for(int k = 0; k < K; ++k) {
                    tmp = min(tmp, abs(n * 1.0 * Y[i] + (a - b) * 1.0 * X[i] - n * a) / sqrt(n * 1.0 * n + (a-b) * (a-b)));
                }

                ans = max(ans, tmp);
            }
        }
        // auto cmp = [&](int x, int y) {
        //     if(X[x] != X[y]) return X[x] < X[y];
        //     else return Y[x] < Y[y];
        // };

        // sort(ord.begin(), ord.end(), cmp);
        // for(int i = 0; i < K; ++i) {
        //     ans = min(ans, (X[i] - X[i-1]) / 2.0);
        //     debug((X[i] - X[i-1]) / 2.0);
        // }

        printf("%.4f\n", ans);
        
        
    }
    return 0;
}

/*

10 10 3
2 2
2 5
2 7



*/