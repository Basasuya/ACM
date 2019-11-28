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

const int MAXN = 3e5 + 5;
int A[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        bool suc = false;
        set<int> val;
        multiset<pair<int, int> > money;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            if(suc == true) { val.insert(i); money.insert(make_pair(A[i], i)); } 
            if(A[i] == -1) suc =true;
        }

        ll ans = 0;

        int cnt = n;
        while(1) {
            cnt /= 2;
            int times;
            if(val.size() <= cnt) times = val.size();
            else times = cnt;
            
            
                debug("round", times);
            if(times) {
                int tt = *(--val.end());
                money.erase(money.find(make_pair(A[tt], tt)));
                val.erase(tt);
                ans += A[tt];
                debug("first erase", tt, A[tt]);
                for(int j = 1; j < times; ++j) {
                    auto tmp = *(--money.end());
                    val.erase(tmp.second);
                    money.erase(tmp);
                    debug("second erase", tmp);
                } 
            }
            if(val.size() == 0) break;
            if(cnt == 1) break;
        }

        printf("%lld\n", ans);
    }
    return 0;
}

/*


8
-1 1 10 10 10 5 6 1


*/