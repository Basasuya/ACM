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

const int MAXN = 2e5 + 5;
char seq[MAXN];
int main() {
    while(~scanf("%s", seq)) {
        int q; scanf("%d", &q);
        int n = strlen(seq);
        vector<vector<int> > vc(30, vector<int> ());
        for(int i = 0; i < n; ++i) {
            vc[seq[i] - 'a'].push_back(i);
        }

        while(q -- ) {
            int l, r;
            scanf("%d %d", &l, &r);
            l --; r --;
            if(r == l) {
                printf("YES\n");
                continue;
            }

            if(r - l + 1 == 3) {
                if(seq[l] == seq[r]) {
                    printf("NO\n");
                    continue;
                }
            }
            
            int cnt = 0;
            for(int i = 0; i < 26; ++i) {
                if(vc[i].size() == 0) continue;
                int pos1 = lower_bound(vc[i].begin(), vc[i].end(), l) - vc[i].begin();
                int pos2 = upper_bound(vc[i].begin(), vc[i].end(), r) - vc[i].begin();
                pos2 --;
                if(pos2 >= pos1) cnt ++;
            }

            debug(cnt);
            if(r - l + 1 > 3 && cnt == 2 && seq[l] == seq[r]) printf("NO\n");
            else if(cnt == 1) printf("NO\n");
            else printf("YES\n");
            
        }

    }
    return 0;
}








int dp[MAXN] // init with -1
void get(int x) {
    if(dp[x] != -1) return dp[x];

    //...calculate dp[x]
    do[x] = tmp;
    return tmp;
}