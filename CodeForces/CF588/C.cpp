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

// int mp[10][10];
int fr[100], to[100];
int n, m;

int solve(int x, int y) {
    map<int, int> id;
    for(int i = 1, cnt = 2; i <= 7; ++i) {
        if(i == x || i == y) {
            id[i] = 1;
        } else id[i] = cnt ++;
    }
    set<pair<int, int> > st;
    for(int i = 0; i < m; ++i) {
        int a = id[fr[i]]; int b = id[to[i]];
        if(a > b) swap(a, b);
        st.insert(make_pair(a, b));
    }
    return (int)st.size();
}
int main() {
    
    while(~scanf("%d %d", &n, &m)) {
        // memset(mp, 0, sizeof(mp));
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &fr[i], &to[i]);
            // mp[fr[i]][to[i]] = 1;
        }

        if(m == 0) {
            printf("0\n");
        } else if(n <= 6) {
            printf("%d\n", m);
        } else {
            int ans = -1;
            for(int i = 1; i <= 7; ++i) {
                for(int j = i + 1; j <= 7; ++j) {
                    ans = max(ans, solve(i, j));
                }
            }
            printf("%d\n", ans);
        }

    }
    return 0;
}