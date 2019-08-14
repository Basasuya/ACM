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
// #define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
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
char S[MAXN], T[MAXN];
vector<int> pos[30];
int Tpos[MAXN], Tpos2[MAXN];
int main() {
    while(~scanf("%s %s", S, T)) {
        for(int i = 0; i < 30; ++i) pos[i].clear();
        int lenS = strlen(S);
        int lenT = strlen(T);
        for(int i = 0; i < lenS; ++i) {
            pos[S[i] - 'a'].push_back(i);
        }
        for(int i = 0, pre = -1; i < lenT; ++i) {
            vector<int>& tmp = pos[T[i] - 'a'];
            int x = upper_bound(tmp.begin(), tmp.end(), pre) - tmp.begin();
            Tpos[i] = x == (int)tmp.size() ? -1 : tmp[x];
            pre = Tpos[i];
        }

        // for(int i = 0; i < 30; ++i) {
        //     reverse(pos[i].begin(), pos[i].end());
        // }

        for(int i = lenT - 1, pre = lenS; i >= 0; --i) {
            vector<int>& tmp = pos[T[i] - 'a'];
            // debug(tmp); debug(pre);
            int x = lower_bound(tmp.begin(), tmp.end(), pre) - tmp.begin();
            x --;
            Tpos2[i] = x == -1 ? x : tmp[x];
            pre = Tpos2[i];
        }
        // for(int i = 0; i < lenT; ++i) {
        //     printf("%d %d: ", Tpos[i], Tpos2[i]);
        // } printf("\n");
        int ans = -1;
        for(int i = 0; i < lenT; ++i) {
            if(i == 0 && Tpos2[i] != -1) ans = max(ans, Tpos2[i]);
            if(i == lenT-1 && Tpos[i] != -1) ans = max(ans, lenS - Tpos[i] - 1);
            if(i && Tpos[i-1] != -1 && Tpos2[i] != -1) ans = max(ans, Tpos2[i] - Tpos[i-1] - 1);
        }

        printf("%d\n", ans);
    }
    return 0;
}