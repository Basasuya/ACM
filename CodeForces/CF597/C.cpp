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

const int MAXN = 1e5 + 5;
char seq[MAXN];
const int MOD = 1e9 + 7;
int fib[MAXN];
int main() {
    fib[2] = 2; fib[3] = 3;

    
    while(~scanf("%s", seq)) {
        int len = strlen(seq);
        bool suc = true;
        int cnt = 0;
        ll ans = 1;
        
        for(int i = 4; i <= len; ++i) {
            fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        }

        for(int i = 0; i < len; ++i) {
            if(seq[i] == 'm' || seq[i] == 'w') {
                suc = false; break;
            } else if(i == 0 || seq[i] == seq[i-1]) {
                cnt ++;
            } else if(seq[i] != seq[i-1]) {
                if( (seq[i-1] == 'n' || seq[i-1] == 'u') && cnt >= 2 ) {
                    ans = ans * fib[cnt] % MOD;
                }
                cnt = 1;
            }
        }

        if( (seq[len - 1] == 'n' || seq[len - 1] == 'u') && cnt >= 2 ) {
            ans = ans * fib[cnt] % MOD;
        }

        if(suc == false) printf("%d\n", 0);
        else printf("%lld\n", ans);
    }
    return 0;
}