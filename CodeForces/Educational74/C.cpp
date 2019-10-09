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

const int MAXN = 2e5 + 5;
int A[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int h, n;
        scanf("%d %d", &h, &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        vector<int> vc;
        int cnt = 1;
        for(int i = 1; i < n; ++i) {
            if(A[i] == A[i - 1] - 1) cnt ++;
            else {
                vc.push_back(cnt);
                cnt = 1;
            }
        }
        vc.push_back(cnt);

        // debug(vc);

        int ans = 0;
        if(vc.size() == 1) {
            if( (vc[0] % 2 == 0) && A[n-1] != 1) printf("1\n");
            else printf("0\n");
            continue;
        }

        if(vc[0] % 2 == 0) ans ++;
        for(int i = 1; i < vc.size(); ++i) {
            if(vc[i] % 2) ans ++;
        }

        if(vc[vc.size() - 1] % 2 == 1 && A[n-1] == 1) ans --;

        printf("%d\n", ans);
    }
    return 0;
}