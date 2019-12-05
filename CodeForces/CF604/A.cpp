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

const int MAXN = 1e5 + 5;
char seq[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s", seq);
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            if(seq[i] == '?') {
                char pre = (i == 0) ? 0 : seq[i-1];
                char nex = (i == len-1) ? 0 : seq[i + 1];
                for(int j = 0; j < 3; ++j) {
                    char tmp = 'a' + j;
                    if(tmp != pre && tmp != nex) {
                        seq[i] = tmp;
                        break;
                    }
                }
            }
        }

        bool suc = true;
        for(int i = 1, len = strlen(seq); i < len; ++i) {
            if(seq[i] == seq[i-1]) {
                suc = false;
                break;
            }
        }

        if(suc == false) printf("-1\n");
        else printf("%s\n", seq);
    }
    return 0;
}