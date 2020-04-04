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

int B[20];
struct Node{
    int fr, to, nx, dis;
}E[20 << 1];
int head[20]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        memset(head, -1, sizeof(head));
        tot = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &B[i]);   
        }

        for(int i = 1; i < n; ++i) {
            int fr, to; scanf("%d %d", &fr, &to);
            fr --; to --;
            add(fr, to);
            add(to, fr);
        }

        ll ans = 0;
        for(int i = 0; i <= (1<<n) - 1; ++i) {
            set<int> st;
            ll tmp = 0;
            for(int j = 0; j < n; ++j) {
                if( (i >> j) & 1) {
                    st.insert(j);
                    for(int k = head[j]; ~k; k = E[k].nx) {
                        st.insert(E[k].to);
                    }
                }
            }

            for(auto it : st) {
                tmp += B[it + 1];
            }
            ans = max(ans, tmp);
        }


        printf("Case #%d: ", cas);
        printf("%lld\n", ans);
    }
    return 0;
}

/*

3
9
-10 4 -10 8 20 30 -2 -3 7
1 4
2 4
4 3
9 4
9 8
7 5
6 7
7 9
4
-2 20 20 20
1 2
1 3
1 4
5
-5 -10 8 -7 -2
5 4
4 3
3 2
2 1

*/