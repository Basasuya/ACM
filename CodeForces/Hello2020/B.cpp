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


int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<int> tag;
        vector<int> firstEle;
        vector<vector<int> > vc;
        int ownOk = 0;

        for(int i = 0; i < n; ++i) {
            int l;
            vector<int> tmp;
            scanf("%d", &l);
            for(int j = 0; j < l; ++j) {
                int x; scanf("%d", &x);
                tmp.push_back(x);
            } 
            vc.push_back(tmp);
            tag.push_back(0);
        }
        
        ll ans = 0;

        for(int i = 0; i < n; ++i) {
            bool suc = true;
            for(int j = 1, len = vc[i].size(); j < len; ++j) {
                if(vc[i][j - 1] < vc[i][j]) {
                    suc = false;
                } 
            }

            if(suc == false && vc[i].size() > 1) { ans += n; ownOk ++; }
            else { tag[i] = 1; firstEle.push_back(vc[i][0]); }
        }

        sort(firstEle.begin(), firstEle.end());

        for(int i = 0; i < n; ++i) {
            if(tag[i] == 1) {
                ans += ownOk;
                int tt = upper_bound(firstEle.begin(), firstEle.end(), vc[i].back()) - firstEle.begin();
                ans += firstEle.size() - tt;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}