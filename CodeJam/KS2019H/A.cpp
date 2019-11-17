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
int A[MAXN];

int tree[MAXN];
int treesize = MAXN - 1;
int Sum(int x) {
    if(x > treesize) x = treesize;
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= x & -x;
    }
    return ans;
}
void Add(int x, int d) {
    // debug(x);
    while(x <= treesize) {
        tree[x] += d;
        x += x & -x;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        memset(tree, 0, sizeof(tree));

        int n;
        scanf("%d", &n);
        int maxx = -1;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }   

        vector<int> result;

        for(int i = 0; i < n; ++i) {
            Add(A[i], 1);
            maxx = max(maxx, A[i]);
            
            int l = 1; int r = maxx;

            while(l <= r) {
                int mid = (l + r) >> 1;
                // debug(Sum(mid) - mid, mid);
                if(i + 1 - Sum(mid - 1) - mid < 0) r = mid - 1;
                else l = mid + 1;
            }

            result.push_back(r);

        }


        printf("Case #%d:", cas);
        for(int i = 0, len = result.size(); i < len; ++i) printf(" %d", result[i]); printf("\n");
    }
    return 0;
}