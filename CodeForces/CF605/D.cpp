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
int A[MAXN];
int pre[MAXN];
int nex[MAXN];


int main() {
    int n;
    while(~scanf("%d", &n)) {
        // memset(tree, 0, sizeof(tree));

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        int ans = -1;
        for(int i = 0; i < n; ++i) {
            if(i && A[i] > A[i - 1]) pre[i] = pre[i-1] + 1;
            else pre[i] = 1;

            ans = max(ans, pre[i]);
        }

        for(int i = n-1; i >= 0; --i) {
            if(i != n-1 && A[i] < A[i + 1]) nex[i] = nex[i + 1] + 1;
            else nex[i] = 1;
        }
        
        for(int i = 1; i < n-1; ++i) {
            if(A[i-1] < A[i + 1]) ans = max(ans, pre[i-1] + nex[i + 1]);
        }


        printf("%d\n", ans);

    }
    return 0;
}
