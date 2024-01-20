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
const int MOD = 998244353;
int P[MAXN], Q[MAXN];


ll bit[MAXN << 1];
int bittreesize;
ll bitsum(int x) {
    if(x > bittreesize) x = bittreesize;
    ll ans =0;
    while(x > 0) {
        ans = (ans + bit[x]) % MOD;
        x -= x & -x;
    }
    return ans;
}
void bitadd(int x, int d) {
    while(x <= bittreesize) {
        bit[x] = (bit[x] + d + MOD) % MOD;
        x += x & -x;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &P[i]);
        }
        for(int i = 0; i < k; ++i) {
            scanf("%d", &Q[i]);
        }
        
        bittreesize = k;
        ll ans = 0;
        for(int i = 0; i <= k; ++i) bit[i] = 0;
        for(int i = 0; i < k; ++i) {
            bitadd(Q[i] + 1, 1);
            ans = (ans + bitsum(bittreesize) - bitsum(Q[i] + 1) + MOD) % MOD;
        }

        debug(ans);
        
        ans = ans * n % MOD;
        

        int edge = 2 * n - 1;
        bittreesize = edge;
        for(int i = 0; i <= edge; ++i) bit[i] = 0;
        // build(1, edge, 1);

        for(int i = 0; i < n; ++i) {
            debug(i);
            ans = (ans + bitsum(P[i])) % MOD;

            vector<int> vc;
            vc.push_back(P[i]);
            int two = 2;
            while(two < P[i]) {
                vc.push_back(ceil(P[i] * 1.0 / two));
                two *= 2;
            }
            if (vc.back() != 1) {
                vc.push_back(1);
            }

            // reverse(vc.begin(), vc.end());

            int l = P[i]; int r = P[i] * 2;
            int cnt = k - 1;
            ll tmp = 1ll * k * (k - 1) / 2 % MOD;
            while(l <= edge) {
                debug(l, r, tmp);
                bitadd(r + 1, -tmp); bitadd(l, tmp);
                // update(l, r, tmp, 1, edge, 1);
                tmp = (tmp - cnt + MOD) % MOD;

                cnt = max(cnt - 1, 0);
                l *= 2; r *= 2;
            }
            tmp = 1ll * k * (k + 1) / 2 % MOD;
            cnt = k - 1;
            for(int i = 0, len = (int)vc.size(); i < len - 1; ++i) {
                int r = vc[i] - 1; int l = vc[i + 1];
                
                debug("hhh", l, r, tmp);
                bitadd(r + 1, -tmp); bitadd(l, tmp);
                
                tmp += cnt;
                cnt = max(cnt - 1, 0);
                // update(l, r, 1, edge, 1);
            }
            
            
        }

        printf("%lld\n", ans);
    }
}