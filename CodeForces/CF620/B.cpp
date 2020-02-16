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

char seq[105][55];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        map<string, int> mp;
        vector<pair<string, string> > vc;

        for(int i = 0; i < n; ++i) {
            scanf("%s", seq[i]);
            string tmp = string(seq[i]);
            string re_tmp = tmp;
            reverse(re_tmp.begin(), re_tmp.end());
            if(mp[re_tmp] > 0) {
                mp[re_tmp] --;
                vc.push_back({tmp, re_tmp});
            } else {
                mp[tmp] ++;
            }
        }

        string center; center.clear();
        for(auto it : mp) {
            string item = it.first;
            bool suc = true;
            for(int i = 0, len = item.length(); i < len / 2; ++i) {
                if(item[i] != item[len - 1 - i]) {
                    suc = false;
                }
            }
            if(suc == true) {
                center = item;
                break;
            }
        }

        string lef; lef.clear();
        for(int i = 0, len = vc.size(); i < len; ++i) {
            center += vc[i].second;
        }
        for(int i = vc.size() - 1; i >= 0; --i) {
            lef += vc[i].first;
        }

        string ans = lef + center;

        printf("%d\n", (int)ans.size());
        if(ans.size() != 0) {
            
            printf("%s\n", ans.c_str());
        }
    }
    return 0;
}


/*

3 3
tab
ono
bat

*/