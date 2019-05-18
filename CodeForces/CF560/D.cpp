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

const int MAXN = 305;
int d[MAXN];
int a[MAXN];
// const int N = 1e6 + 5;
// int d[MAXN];
// int isPrime[N]; 
// int Prime[N];
// int primeTot;
int main() {
    int t;
    // primeTot = 0;
    // for(int i = 2; i < N; ++i) {
    //     if(!isPrime[i]) {
    //         Prime[++primeTot] = i;
    //     }
    //     for(int j = 2*i; j < N; j += i) {
    //         isPrime[j] = 1;
    //     }
    // }

    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &d[i]);
        sort(d, d + n);
        ll result = 1ll * d[0] * d[n - 1];

        int cnt = 0;
        bool suc = true;
        int edge = sqrt(result);
        for(int i = 2; i <= edge && suc; ++i) {
            if(result % i == 0) {
                a[cnt ++] = i; 
                if(result / i != i) a[cnt ++] = result / i;
                if(cnt > n) {
                    suc = false;
                }
            }
        }
        // if(1ll * edge * edge == result) {
        //     a[cnt ++] = edge;
        // }
        if(cnt != n) suc = false;
        sort(a, a + n);
        for(int i = 0; i < n && suc; ++i) {
            if(a[i] != d[i]) suc = false;
        }

        if(suc) printf("%lld\n", result);
        else printf("-1\n");
        // ll tmp = result;
        // for(int i = 1; i <= primeTot; ++i) {
        //     if()
        // }

    }
    return 0;
}