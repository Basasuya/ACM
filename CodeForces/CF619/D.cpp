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
    int n, m, k;
    while(~scanf("%d %d %d", &n, &m, &k)) {
        vector<pair<int, string> > steps;

        for(int i = 0; i < n - 1; ++i) {
            if(m > 1) steps.push_back({m - 1, string("R")});
            if(m > 1) steps.push_back({m - 1, string("L")});
            steps.push_back({1, string("D")});
        }  

        if(m > 1) steps.push_back({m - 1, string("R")});

        for(int i = 0; i < m - 1; ++i) {
            if(n > 1) steps.push_back({n - 1, string("U")});
            if(n > 1) steps.push_back({n - 1, string("D")});
            steps.push_back({1, string("L")});
        } 

        if(n > 1) steps.push_back({n - 1, string("U")});
        
        // int sum = 4 * n * m - 2 * n - 2 * m;
        // int now_sum = 0;
        // for(int i = 0, len = steps.size(); i < len; ++i) {
        //     now_sum += steps[i].first;
        // }
        // debug(steps, now_sum, sum, (int)steps.size() );
        // assert(now_sum == sum);

        int sum = 4 * n * m - 2 * n - 2 * m;
        if(sum < k) {
            printf("NO\n"); continue;
        }

        vector<pair<int, string> > ans;
        int now_sum = 0;
        for(int i = 0, len = steps.size(); i < len; ++i) {
            now_sum += steps[i].first;
            if(now_sum >= k) {
                int tt = steps[i].first - (now_sum - k);
                ans.push_back({tt, steps[i].second});
                break;
            } else {
                ans.push_back(steps[i]);
            }
        }

        printf("YES\n%d\n", (int)ans.size());
        for(int i = 0, len = ans.size(); i < len; ++i) {
            printf("%d %c\n", ans[i].first, ans[i].second[0]);
        }

    }
    return 0;
}