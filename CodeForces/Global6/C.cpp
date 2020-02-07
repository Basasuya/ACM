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

int ans[505][505];

int gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    int r, c;
    while(~scanf("%d %d",&r,&c)) {
        if(r == 1 && c == 1) {
            printf("0\n");
            continue;
        }
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ans[i][j] = 1;
            }
        }

        if(r == 1 || c == 1) {
            if(r == 1) { for(int i = 0; i < c; ++i) ans[0][i] = i + 2; }
            else { for(int i = 0; i < r; ++i) ans[i][0] = i + 2; }
        } else {
            for(int i = 0; i < r; ++i) {
                for(int j = 0; j < c; ++j) {
                    ans[i][j] *= (i + 1);
                }
            }

            for(int j = 0; j < c; ++j){
                for(int i = 0; i < r; ++i) {
                    ans[i][j] *= (j + 1 + r);
                }
            }
        }


        // set<int> st;
        // for(int i = 0; i < r; ++i) {
        //     int tt = ans[i][0];
        //     for(int j = 1; j < c; ++j) {
        //         tt = gcd(tt, ans[i][j]);
        //     }
        //     st.insert(tt);
        // }

        // for(int j = 0; j < c; ++j){
        //     ll tt = ans[0][j];
        //     for(int i = 1; i < r; ++i) {
        //         tt = gcd(tt, ans[i][j]);
        //     }
        //     st.insert(tt);
        // }

        // debug(st);
        // printf("%d %d\n", (int)st.size(),  *(--st.end()));


        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(j != 0) printf(" ");
                printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}