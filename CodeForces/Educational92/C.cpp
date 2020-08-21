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
    int T;
    scanf("%d", &T);
    while(T --) {
        vector<vector<int>> cha(10, vector<int>());
        int max_pos = -1; int max_num = -1;

        scanf("%s", seq);

        int n = strlen(seq);
        
        for(int i = 0; i < n; ++i) {
            int target = seq[i] - '0';
            cha[target].push_back(i);

            int siz = cha[target].size();

            if(siz > max_num) {
                max_num = siz;
                max_pos = target;
            }
        }

        int ans = n - max_num;

        // debug(ans);

        for(int i = 0; i < 10; ++i) {
            for(int j = i + 1; j < 10; ++j) {
                if(cha[i].empty() || cha[j].empty()) continue;

                int x = i; int y = j;
                if(cha[x][0] > cha[y][0]) swap(x, y);

                int tmp_ans = 0;
                
                int now = 0;
                while(1) {
                    int t1 = cha[x][now];
                    int t2 = lower_bound(cha[y].begin(), cha[y].end(), t1) - cha[y].begin();
                    if(t2 == cha[y].size()) break;
                    tmp_ans += 2;
                    now = lower_bound(cha[x].begin(), cha[x].end(), cha[y][t2]) - cha[x].begin();
                    if(now == cha[x].size()) break;
                    // debug(now);
                }


                ans = min(ans, n - tmp_ans);
            }
        }

        printf("%d\n", ans);
    }
}