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
char A[MAXN], B[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        scanf("%s %s", A, B);

        int cnt = 0;
        bool have_one = false;
        

        int one_one = 0, one_zero = 0, zero_one = 0, zero_zero = 0;

        for(int i = 0; i < n; ++i) {
            if(A[i] == '0' && B[i] == '0') {
                zero_zero ++;
            } else if(A[i] == '1' && B[i] == '0') {
                one_zero ++;
            } else if(A[i] == '1' && B[i] == '1') {
                one_one ++;
            } else {
                zero_one ++;
            }
        }

        int ans = INF;


        if (one_one == zero_zero + 1) {
            ans = min(ans, zero_zero + one_one);
        } 
        if (one_zero == zero_one) {
            ans = min(ans, one_zero + zero_one);
        }

        if (ans == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    } 
    return 0;
}

/*


5
5
11010
11010
2
01
11
3
000
101
9
100010111
101101100
9
001011011
011010101

*/