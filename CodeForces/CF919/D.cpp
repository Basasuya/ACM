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

int main() {
    int T;
    ll result = 3796234133329219584ll * 6;
    // printf("%lld\n", result);
    
    scanf("%d", &T);
    ll edge = 2e18;
    while(T --) {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<pair<int, int> > operations;
        vector<ll> sum;
        ll count = 0;
        for(int i = 0; i < n; ++i) {
            int x, y; scanf("%d %d", &x, &y);

            double true_count = count;

            if (count < 0) { /*pass*/ }
            else if (x == 1) { count += 1; true_count += 1; }
            else { count = count * (y + 1); true_count *= (y + 1); }
            
            
            debug(true_count);

            operations.push_back(make_pair(x, y));    
            
            if (count > 0 && true_count < edge) {
                sum.push_back(count);
            } else {
                count = -1;
            }
        }

        sum.push_back(edge);

        // debug(sum);

        for(int i = 0; i < q; i ++) {
            ll k; scanf("%lld", &k);
            if(i) printf(" ");
            while(true) {
                int pos = lower_bound(sum.begin(), sum.end(), k) - sum.begin();
                // debug(k, pos, sum[pos]);
                if(sum[pos] == k && operations[pos].first == 1) {
                    printf("%d", operations[pos].second);
                    break;
                } else {
                    ll init_x = sum[pos - 1];
                    k = (k - 1) % init_x + 1;
                }
            }
        }

        printf("\n");
    }
    return 0;
}