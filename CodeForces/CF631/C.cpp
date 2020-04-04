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

const int MAXN = 1e5 + 5;
int L[MAXN];
int add[MAXN];


int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        ll sum = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &L[i]);
            sum += L[i];
            add[i] = 0;
        }

        if(sum < n) {
            printf("-1\n");
            continue;
        }
        
        bool suc = true;
        for(int i = 0; i < m; ++i) {
            if(L[i] + i > n) {
                suc = false;
                break;
            }
        }

        if(suc == false) {
            printf("-1\n");
            continue;
        }

        vector<ll> suf_L(n + 5, 0);
        for(int i = m-1; i >= 0; --i) {
            suf_L[i] = suf_L[i + 1] + L[i];
        }

        
        for(int i = 0; i < m; ++i) {
            int iter = max(1ll * i, 1ll * n - suf_L[i]);
            if(i) printf(" ");
            printf("%d", iter + 1);
            iter += 1 + add[i];
        }
        printf("\n");

    }
    return 0;
}