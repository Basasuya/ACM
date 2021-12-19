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

const int MAXN = 1e6 + 5;
char seq[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        scanf("%s", seq);

        int ans = INF;
        for(int i = 0; i < n; ++i) {
            if (ans > 2 && i + 1 < n && seq[i] == 'a' && seq[i + 1] == 'a') {
                ans = min(2, ans);
                break;
            } 
            if (ans > 3 && i + 2 < n && seq[i] == 'a' && seq[i + 2] == 'a') {
                ans = min(3, ans);
            }

            if (ans > 4 && i + 3 < n && seq[i] == 'a' && seq[i + 3] == 'a' && seq[i + 1] != seq[i + 2]) {
                ans = min(4, ans);
            }

            if (ans == INF && i + 6 < n && seq[i] == 'a' && seq[i + 3] == 'a' && seq[i + 6] == 'a') {
                int t1 = 0; int t2 = 0;
                for(int j = i + 1; j < i + 6; ++j) {
                    if(seq[j] == 'b') t1 ++;
                    else if(seq[j] == 'c') t2 ++;
                }

                debug(t1, t2);
                if(t1 == t2) {
                    ans = min(ans, 7);
                }
            }
        }

        if(ans == INF) {
            printf("-1\n");
        } else printf("%d\n", ans);

    }
    return 0;
}