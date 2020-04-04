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
#define forw(i, l, r) for (int i = l; i < r; ++i)
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

const int MAXN = 505;
// vector<int> skill[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n, s;
        scanf("%d %d", &n, &s);
        map<ll, int> mp;
        map<ll, int> except;
        for(int i = 1; i <= n; ++i) {
            // skill[i].clear();
            vector<int> tmp;
            int times; scanf("%d", &times);
            for(int j = 0; j < times; ++j) {
                int tt; scanf("%d", &tt);
                // tt --;
                tmp.push_back(tt);
            }
            sort(tmp.begin(), tmp.end());
            ll tag = 0;
            int len = tmp.size();
            for(int j = 0; j < len; ++j) {
                tag = tag * (s + 1) + tmp[j];
            } 

            
            for(int j = 1; j < (1<<len) - 1; ++j) {
                ll exceptTag = 0;
                for(int k = 0; k < len; ++k) {
                    if( (j >> k) & 1 ) {
                        exceptTag = exceptTag * (s + 1) + tmp[k];
                    }
                }
                // printf("%lld\n", exceptTag);
                except[exceptTag] ++;
            } 

            // printf("%lld\n\n", tag);
            mp[tag] ++;
        }

        ll ans = 0;
        for(auto it : mp) {
            int tt = except[it.first];
            // debug(it, tt);
            ans += 1ll * (n - it.second - tt) * it.second;
            // debug(ans);
        }

        printf("Case #%d: ", cas);
        printf("%lld\n", ans);
    }
    return 0;
}

/*


100
4 100
4 80 90 100 5
1 90
1 80
3 80 90 100
3 30
4 10 11 12 13
4 10 11 12 13
5 25 26 27 28 29
3 100
1 1
2 1 2
1 1


*/