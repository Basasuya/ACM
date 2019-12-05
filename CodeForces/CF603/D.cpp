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
int fa[MAXN];
int Find(int x) { return fa[x] == x ? fa[x] : (fa[x] = Find(fa[x])); }
vector<int> vc[30];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < 30; ++i) vc[i].clear();
        for(int i = 0; i < n; ++i) fa[i] = i;
        for(int i = 0; i < n; ++i) {
            char tmp[55];
            scanf("%s", tmp);
            for(int j = 0, len = strlen(tmp); j < len; ++j) {
                vc[tmp[j] - 'a'].push_back(i);
            }
        }
        for(int i = 0; i < 26; ++i) {
            if(vc[i].size() < 2) continue;
            
            for(int j = 1; j < vc[i].size(); ++j) {
                int t1 = Find(vc[i][0]); int t2 = Find(vc[i][j]);
                if(t1 != t2) {
                    fa[t2] = t1;
                }
            }
        }

        set<int> st;
        for(int i = 0; i < n; ++i) {
            st.insert(Find(i));
        }

        printf("%d\n", (int)st.size());
        
    }
    return 0;
}