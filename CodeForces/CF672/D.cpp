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
int L[MAXN], R[MAXN];
ll Mul[MAXN];
const int MOD = 998244353;
vector<pair<int, int> > vc;


ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll C(int x, int y) {
    if(x < y) return 0;
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}

int main() {
    int n, K;

    Mul[1] = 1; Mul[0] = 1;
    for(int i = 2; i < MAXN; ++i) {
        Mul[i] = 1ll* Mul[i-1] * i % MOD;
    }

    while(~scanf("%d %d", &n, &K)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &L[i], &R[i]);
        }

        vector<tuple<int, int, int>> vc;
        for(int i = 0; i < n; ++i) {
            vc.push_back({L[i], i, 1});
            vc.push_back({R[i] + 1, i, -1});
        }

        sort(vc.begin(), vc.end(), [](tuple<int, int, int>& x, tuple<int, int, int>& y) {
            if(get<0>(x) != get<0>(y)) {
                return get<0>(x) < get<0>(y);
            }
            return get<2>(x) < get<2>(y);
        });

        int cnt = 0;
        ll ans = 0;
        set<int> st;
        set<int> still_in;
        for(int i = 0, len = vc.size(); i < len; ++i) {
            int val = get<1>(vc[i]); int update = get<2>(vc[i]);
            if(update == -1) {
                cnt --;
                st.erase(val);
                still_in.erase(val);
            } else {
                cnt ++;
                st.insert(val);
                still_in.insert(val);

                if(cnt >= K) {
                    int siz = st.size();
                    int siz_ = still_in.size();
                    ans = (ans + C(siz, K) - C(siz - siz_, K) + MOD) % MOD;
                    still_in.clear();
                }
            }
        }

        printf("%lld\n", ans);

    }
    return 0;
}