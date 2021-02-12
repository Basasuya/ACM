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

const int MAXN = 1e5 + 5;
int A[MAXN];
int now[MAXN];
int nex[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i <= n; ++i) {
            now[i] = n + 1;
            nex[i] = n + 1;
        }

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            
        }

        for(int i = n - 1; i >= 0; --i) {
            nex[i] = now[A[i]];
            now[A[i]] = i;
        }

        // for(int i = 0; i < n; ++i) printf("%d ", nex[i]); printf("\n");

        int pre_L = n; int pre_R = n;
        A[n] = -1;
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(A[pre_L] != A[i] && A[pre_R] != A[i]) {
                ans ++;
                if(nex[pre_L] < nex[pre_R]) {
                    pre_R = i;
                } else {
                    pre_L = i;
                }
            } else if(A[pre_L] != A[i]) {
                pre_R = i;
            } else if(A[pre_R] != A[i]) {
                pre_L = i;
            } else {
                pre_R = i;
            }
        }   

        printf("%d\n", ans);
    }
    return 0;

}