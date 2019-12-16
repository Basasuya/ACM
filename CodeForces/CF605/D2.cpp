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
int tree[MAXN];
int treesize;
int sum(int x) {
    if(x > treesize) x = treesize;
    int ans = -1;
    while(x > 0) {
        ans = max(ans, tree[x]);
        x -= x & -x;
    }
    return ans;
}
void add(int x, int d) {
    // debug(x);
    while(x <= treesize) {
        tree[x] = max(d, tree[x]);
        x += x & -x;
    }
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(tree, 0, sizeof(tree));

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
        
        vector<int> vc;
        for(int i = 0; i < n; ++i) {
            vc.push_back(A[i]);
        }
        sort(vc.begin(), vc.end());
        vc.erase(unique(vc.begin(), vc.end()), vc.end());
        treesize = vc.size() + 5;

        
        for(int i = 0; i < n; ++i) {
            int x = lower_bound(vc.begin(), vc.end(), A[i]) - vc.begin();
            
            ans = max(ans, sum(x) + nex[i]);

            add(x + 1, pre[i]);
        }

        printf("%d\n", ans);

    }
    return 0;
}

/*

这题适合与两段的情况

*/