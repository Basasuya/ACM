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

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, p;
        scanf("%d %d", &n, &p);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        vector<pair<int, int>> vc;
        
        vector<bool> connected(n, false);

        for(int i = 0; i < n; ++i) {
            vc.push_back({A[i], i});    
        }

        sort(vc.begin(), vc.end());

        ll ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(vc[i].first >= p) break;

            int pos = vc[i].second;
            int tt = pos - 1;
            int find = false;
            while(tt >= 0) {
                if(A[tt] % A[pos] == 0 && !connected[tt]) {
                    find = true;
                    ans += vc[i].first;
                    cnt ++;
                    connected[tt] = true;
                } else break;
                tt --;
            }

            tt = pos + 1;
            while(tt < n) {
                if(A[tt] % A[pos] == 0 && !connected[tt - 1]) {
                    find = true;
                    ans += vc[i].first;
                    cnt ++;
                    connected[tt - 1] = true;
                } else break;
                tt ++;
            }

            // if(find) connected[pos] = true;
        }

        ans += 1ll * (n - 1 - cnt) * p;

        printf("%lld\n", ans);


    }
    return 0;
}