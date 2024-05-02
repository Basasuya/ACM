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

const int MAXN = 2e5 + 5;
int A[MAXN];
int ST[MAXN][20];
int lg[MAXN];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    lg[1] = 0;
    for(int i = 2; i < MAXN; i++){
        lg[i] = lg[i - 1];
        if((1 << (lg[i] + 1)) == i)
            lg[i]++;
    }

    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        
        for(int st = 0; (1<<st) <= n; ++st) {
            for(int i = 0; i <= n - (1<<st); ++i) {
                if (st == 0) {
                    ST[i][st] = A[i]; continue;
                }
                ST[i][st] = gcd(ST[i][st - 1], ST[i + (1<<(st-1))][st - 1]);
            }
        }

        auto query = [&](int l, int r) {
            int st = lg[r - l + 1];
            return gcd(ST[l][st], ST[r + 1 - (1 << st)][st]);
        };
        
        int pt = 0;
        int maxr = -1;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            while(pt < i && query(pt, i) < i - pt + 1) ++pt;
            if (query(pt, i) == i - pt + 1) {
                if(pt > maxr) {
                    maxr = i;
                    ans ++;
                }
            }
            if(i) printf(" ");
            printf("%d", ans);
        } 
        printf("\n");
    }
    return 0;

}