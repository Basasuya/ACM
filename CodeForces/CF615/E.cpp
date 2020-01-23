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
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        vector<vector<int> > vc(n, vector<int> ());
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int t; scanf("%d", &t);
                vc[i].push_back(t);
            }
        }

        int ans = 0;
        for(int j = 0; j < m; ++j) {
            map<int, int> mp;
            // map<int, int> has;
            int tmpAns = n;
            for(int i = 0; i < n; ++i) {
                int tmp = vc[i][j];
                int y = (tmp - 1) % m; int x = (tmp - 1) / m;
                if(x >= n) continue;
                if(y == j) {
                    int step = (i - x + n) % n; 
                    mp[step] ++;
                    // if(has.count(vc[i][j])) {
                    //     has[vc[i][j]] = min(has[vc[i][j]], step);
                    // } else {
                    //     has[vc[i][j]] = step;
                    // }
                }
            }

            // debug(has);

            // for(auto item : has) {
            //     mp[item.second] ++;
            // }
            
            // int tmp = 0;
            for(auto item : mp) {
                // tmp += item.second;
                tmpAns = min(tmpAns, item.first + (n - item.second));
            }
            ans += tmpAns;
        }
        printf("%d\n", ans);
    }
    return 0;
}