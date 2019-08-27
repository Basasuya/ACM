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

int A[55][55];
int B[55][55];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &A[i][j]);
                B[i][j] = 0;
            }
        }

        vector<pair<int, int> > ans;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(A[i][j] == 1 && A[i + 1][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j + 1] == 1) {
                    ans.push_back(make_pair(i, j));
                }
            }
        } 

        for(int k = 0, len = ans.size(); k < len; ++k) {
            int i = ans[k].first; int j = ans[k].second;
            B[i][j] = 1;
            B[i + 1][j] = 1;
            B[i][j + 1] = 1;
            B[i + 1][j + 1] = 1;
        }

        bool flag = true;
        for(int i = 1; i <= n && flag; ++i) {
            for(int j = 1; j <= m && flag; ++j) {
                if(A[i][j] != B[i][j]) {
                    flag = false;
                }
            }
        }

        if(flag == false) printf("-1\n");
        else {
            printf("%d\n", (int)ans.size());
            for(int i = 0, len = ans.size(); i < len; ++i) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }

    }
    return 0;
}