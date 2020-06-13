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
    int A, B, C, D;
    while(~scanf("%d %d %d %d", &A, &B, &C, &D)) {
        ll ans = 0;
        auto solve = [&](int fr, int to) {
            return 1ll * (B - fr + 1 + B - to + 1) * (to - fr + 1) / 2;
        };

        for(int i = C; i <= D; ++i) {
            int st = i - C + 1; int ed = i - B + 1;
            
            if(ed < A) {
                ans += 1ll * (B - A + 1) * (ed - st + 1);
            } else if(ed <= B) {
                if(st < A) {
                    ans += 1ll * (B - A + 1) * (A - st);
                    ans += solve(A, ed);
                    // ans += 1ll * (B - A + 1 + B - ed + 1) * (ed - A + 1) / 2;
                } else {
                    ans += solve(st, ed);
                    // ans += 1ll * (B - st + 1 + B - ed + 1) * (ed - st + 1) / 2;
                }
            } else {
                if(st < A) {
                    ans += 1ll * (B - A + 1) * (A - st);
                    // ans += 1ll * (B - A + 1) * (B - A + 1);
                    ans += solve(A, B);
                } else if(st <= B) {
                    ans += solve(st, B);
                    // ans += 1ll * (B - st + 1 + 1) * (B - st + 1) / 2;
                }
            }

            // debug(st, ed, i);
            
            // st = max(st, A);
            // ed = max(ed, A);

            
            // if(st <= B) {
            //     ed = min(ed, B);
            //     debug(st, ed);
            //     ans += 1ll * (B - ed + 1 + B - st + 1) * (ed - st + 1) / 2;
            // }
        }

        printf("%lld\n", ans);
    }
    return 0;
}