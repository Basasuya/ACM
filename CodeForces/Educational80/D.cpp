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

const int MAXN = 3e5 + 5;

int dp[260];
int ans[260];
int pos[260];
// int maxx[MAXN][260];
int firstOne(unsigned x) {
    int n=1;
    if(x==0) return -1;
    if ((x>>16) == 0) {n = n+16; x = x<<16;}
    if ((x>>24) == 0) {n = n+8; x = x<<8;}
    if ((x>>28) == 0) {n = n+4; x = x<<4;}
    if ((x>>30) == 0) {n = n+2; x = x<<2;}
    n = n-(x>>31);
    return 31-n;    
}

int main() {
    // printf("%d\n", f1(4));

    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        vector<pair<int, int> > vc;
        
        for(int j = 1; j < (1<<m); ++j) {
            ans[j] = -1;
        }

        for(int i = 0; i < n; ++i) {
            vector<int> vc;
            for(int j = 0; j < m; ++j) {
                int t; scanf("%d", &t);
                vc.push_back(t);
            }

            dp[0] = INF;
            for(int j = 1; j < (1<<m); ++j) {
                int pos = firstOne(j);
                dp[j] = min(dp[j - (1<<pos)], vc[pos]); 
            }
            for(int j = 1; j < (1<<m); ++j) {
                if(ans[j] < dp[j]) {
                    ans[j] = dp[j];
                    pos[j] = i + 1;
                }
            }
        }

        // for(int j = 1; j < (1<<m); ++j) {
        //     debug(j, ans[j], pos[j]);
        // }


        int result = ans[(1<<m) - 1]; int fr = pos[(1<<m) - 1]; int to = pos[(1<<m) - 1];
        for(int i = 1; i < (1<<m) - 1; ++i) {
            if(result < min(ans[i], ans[(1<<m) - 1 -i])) {
                result = min(ans[i], ans[(1<<m) - 1 -i]);
                fr = pos[i];
                to = pos[(1<<m) - 1 -i];
            }
        }

        // debug(result);

        printf("%d %d\n", fr, to);
    }
    return 0;
}