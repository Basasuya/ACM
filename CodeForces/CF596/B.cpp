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

const int MAXN = 2e5 + 5;
const int MAXM = 1e6 + 5;
int A[MAXN];
int has[MAXM];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            has[A[i]] = 0;
        }
        int ans = k;
        set<int> st;
        for(int i = 0; i < d; ++i) {
            st.insert(A[i]);
            has[A[i]] ++;
        }

        for(int i = d; i <= n; ++i) {
            ans = min(ans, (int)st.size());
            if(i == n) break;
            has[A[i]] ++;
            if(has[A[i]] == 1) st.insert(A[i]);

            has[A[i - d]] --;
            if(has[A[i - d]] == 0) st.erase(A[i - d]);
        }

        printf("%d\n", ans);
    }
    return 0;
}