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

const int MAXN = 1005;
char seq[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_) {
        int X, Y;
        scanf("%d %d %s", &X, &Y, seq);
        int n = strlen(seq);
        
        seq[n] = 'J';

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == '?') {
                cnt ++;
            } else {
                char fr = i - cnt - 1 < 0 ? 0 : seq[i - cnt - 1];
                char to = seq[i];
                char ans;
                if(fr == 0) ans = to;
                else if(fr != to) {
                    if(X > Y) {
                        if(fr == 'C') ans = 'J';
                        else ans = 'C';
                    } else {
                        if(fr == 'J') ans = 'J';
                        else ans = 'C';
                    }
                } else ans = fr;
                for(int j = i - cnt; j < i; ++j) {
                    seq[j] = ans;
                }
                cnt = 0;
            }
        }
        
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if(seq[i - 1] == 'C' && seq[i] == 'J') ans += X;
            else if(seq[i - 1] == 'J' && seq[i] == 'C') ans += Y;
        }
        
        
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}