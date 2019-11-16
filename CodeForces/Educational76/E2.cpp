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

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;


int main() {
    int k1, k2, k3;
    while(~scanf("%d %d %d", &k1, &k2, &k3)) {
        int n = k1 + k2 + k3;
        vector<int> cntr(n + 5, 0);
        vector<int> cntl(n + 5, 0);
        vector<int> cntMin(n + 5, INF);


        set<int> s1, s2, s3;
 
        for(int i = 0; i < k1; ++i) {
            int x; scanf("%d", &x);
            s1.insert(x);
        }
 
        for(int i = 0; i < k2; ++i) {
            int x; scanf("%d", &x);
            s2.insert(x);
        }
 
        for(int i = 0; i < k3; ++i) {
            int x; scanf("%d", &x);
            s3.insert(x);
        }

        for(int i = n; i >= 1; --i) {
            if(s1.count(i) || s2.count(i)) cntr[i] ++;
            cntr[i] += cntr[i + 1];
        }

        for(int i = 1; i <= n; ++i) {
            if(s1.count(i) || s3.count(i)) cntl[i] ++;
            cntl[i] += cntl[i - 1];
        }

        cntMin[0] = 0;
        for(int i = 1, tmp = 0; i <= n; ++i) {
            if(s2.count(i)) tmp ++;
            else if(s1.count(i)) tmp --;

            cntMin[i] = min(cntMin[i-1], tmp);
        }

        int ans = INF;
        for(int i = 0; i <= n; ++i) {
            ans = min(ans, cntMin[i] + cntl[i] + cntr[i + 1]);
        }

        printf("%d\n", ans);
    
    }
    return 0;
}