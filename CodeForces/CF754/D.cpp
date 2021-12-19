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


const int N = 2e5 + 5;
struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}


vector<int> group[2];

void dfs(int x, int pre, int floor) {
    group[floor].push_back(x);

    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if (to == pre) {
            continue;
        }
        dfs(to, x, floor ^ 1);
    } 
}


int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);

        tot = 0;
        for(int i = 0; i <= n; ++i) {
            head[i] = -1;
        }
        group[0].clear();
        group[1].clear();
        vector<int> result(n + 1, 0);

        for(int i = 1; i < n; ++i) {
            int fr, to;
            scanf("%d %d", &fr, &to);
            add(fr, to);
            add(to, fr);
        }

        debug(n);

        dfs(1, 0, 0);

        int choose_small = group[0].size() < group[1].size() ? 0 : 1;
        int cnt1 = 0; int cnt2 = 0;
        int num = group[choose_small].size();

        debug(group[0].size(), group[1].size());

        for(int i = 0; i < 30; ++i) {
            for(int j = 1<<i, len = min((1<<(i+1))-1, n); j <= len; ++j) {
                if ((num >> i) & 1) {
                    result[group[choose_small][cnt1 ++]] = j;
                } else {
                    result[group[choose_small ^ 1][cnt2 ++]] = j;
                }
            }
            if ((1<<(i+1))-1 >= n) break;
        }

        // for(int)


        for(int i = 1; i <= n; ++i) {
            if(i != 1) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}