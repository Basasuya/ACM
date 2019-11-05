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
#define mp make_pair
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

char seq[105];
char ans[105];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        scanf("%s", seq);
        int sum[4]; memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; ++i) {
            if(seq[i] == 'R') sum[0] ++;
            else if(seq[i] == 'P') sum[1] ++;
            else sum[2] ++;
        } 
        int all = min(sum[0], b) + min(sum[1], c) + min(sum[2], a);
        // debug(all, n);
        if(all >= ceil(n *1.0/ 2) ) {
            printf("YES\n");
            vector<int> elsePart;
            for(int i = 0; i < n; ++i) {
                if(seq[i] == 'R' && b) { b --; ans[i] = 'P'; } 
                else if(seq[i] == 'P' && c) { c --; ans[i] = 'S'; }
                else if(seq[i] == 'S' && a) { a --; ans[i] = 'R'; }
                else elsePart.push_back(i);
            }
            for(auto it : elsePart) {
                if(a) {
                    a --; ans[it] = 'R';
                } else if(b) { b --; ans[it] = 'P'; }
                else ans[it] = 'S';
            }
            ans[n] = 0;
            printf("%s\n", ans);
        } else printf("NO\n");
    }
    return 0;
}