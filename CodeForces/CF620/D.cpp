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
        int n; scanf("%d", &n);
        scanf("%s", seq);

        vector<int> ans1(n + 5, 0);
        vector<int> ans2(n + 5, 0);

        vector<int> descent, ascend;
        descent.clear();
        ascend.clear();

        for(int i = 0; i < n - 1; ++i) {
            if(seq[i] == '>') descent.push_back(i);
            else ascend.push_back(i);
        }

        ascend.push_back(n - 1);

        for(int i = 0, len = ascend.size(); i < len; ++i) {
            ans1[ascend[i]] = i;            
        }

        debug(ascend);

        int cnt = 0; int target = (int)ascend.size() - 1;
        for(int i = 0, len = ascend.size(); i < len; ++i) {
            if(i == 0) { cnt ++; continue; }
            if(ascend[i] != ascend[i-1] + 1) {
                int now = ascend[i-1];
                for(int j = 0; j < cnt; ++j) {
                    debug(now, target, cnt);
                    ans2[now --] = target --;
                }
                cnt = 1;
            } else cnt ++;
        }

        int now = ascend[(int)ascend.size() - 1];
        for(int j = 0; j < cnt; ++j) {
            ans2[now --] = target --;
        }

        for(int i = 0, len = descent.size(); i < len; ++i) {
            ans1[descent[i]] = n - 1 - i;
            ans2[descent[i]] = n - 1 - i;
        }



        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans2[i] + 1);
        }
        printf("\n");

        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans1[i] + 1);
        }
        printf("\n");

    }
    return 0;
}


/*** 


给你一个序列，问最不同排列的LIS总和是多少

3
7 >><>><
5 <><>
***/