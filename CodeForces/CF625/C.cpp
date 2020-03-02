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

char seq[105];
int tag[105];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        // list<int> Li;
        // vector<vector<int> > vc(30, vector<int>());
        memset(tag, 0, sizeof(tag));
        vector<int> character_cnt(30, 0);
        // int n = strlen(seq);
        for(int i  = 0; i < n; ++i) {
            // Li.push_back(seq[i] - 'a');
            // vc[seq[i] - 'a'].push_back(i);
            character_cnt[seq[i] - 'a'] ++;
            tag[i] = 1;
        }

        for(int i = 25; i >= 0; --i) {
            if(!character_cnt[i] || i == 0) continue;
            vector<int> vc;
            vector<int> pos;

            for(int j = 0; j < n; ++j) {
                if(tag[j]) {
                    vc.push_back(seq[j] - 'a');
                    pos.push_back(j);
                }   
            }

            bool flag = false;
            for(int j = 0, len = vc.size(); j < len; ++j) {
                if(vc[j] == i - 1) { flag = true; continue; }

                if(flag && vc[j] == i) tag[pos[j]] = 0;
                if(flag && vc[j] != i) flag = false;
            }

            flag = false;
            for(int j = (int)vc.size() - 1; j >= 0; --j) {
                if(vc[j] == i - 1) { flag = true; continue; }

                if(flag && vc[j] == i) tag[pos[j]] = 0;
                if(flag && vc[j] != i) flag = false;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(tag[i] == 0) ans ++;
        }

        printf("%d\n", ans);


    }
    return 0;
}