#include <iostream>
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

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int A[MAXN];
int S[MAXN];
int ord[MAXN];
int fa[MAXN];
int Count[MAXN];


int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            fa[i] = -1;
            Count[i] = -1;
            scanf("%d", &A[i]);
        }
        
        int cnt = 0; A[n] = INF;
        for(int i = n-1; i >= 0; --i) {
            ord[A[i]] = i;
            if(A[i] < A[i + 1]) cnt ++;
            else cnt = 1;
            S[i] = cnt;
        }

        ll ans = 0;
        for(int i = 0; i < n; ++i) {   
            int pos = ord[i];
            if(pos != 0 && fa[pos - 1] != -1) {
                int cnt = Count[find(pos - 1)];
                ans += 1ll * S[pos] * cnt;
            }
            ans += S[pos];
            debug(i, pos, S[pos], ans);

            fa[pos] = pos;
            Count[pos] = 1;
            if(pos != 0 && fa[pos - 1] != -1) {
                int t1 = find(pos - 1); int t2 = find(pos);
                Count[t1] += Count[t2];
                fa[t2] = t1;
            }

            if(pos != n-1 && fa[pos + 1] != -1) {
                int t1 = find(pos + 1); int t2 = find(pos);
                Count[t1] += Count[t2];
                fa[t2] = t1;
            }

        } 

        printf("%lld\n", 1ll * n * (n + 1) / 2 - ans);
    }
    return 0;
}