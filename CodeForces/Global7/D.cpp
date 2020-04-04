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

const int MAXN = 1e6 + 5;
char seq[MAXN];


int solve(string remain) {
    // cout << remain << endl;
    int n = remain.size();
    vector<int> nex(n + 5, 0);
    int i, j;
    j = nex[0] = -1;
    i = 0;
    while(i < n) {
        while(j != -1 && remain[i] != remain[j]) j = nex[j];
        nex[++i] = ++j;
    }
    return nex[n - 1] + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s", seq);
        int n = strlen(seq);
        
        string origin = string(seq);
        int ans = 0;
        for(int i = 0; i < n / 2; ++i) {
            if(seq[i] == seq[n - i - 1]) {
                ans += 2;
            } else break;
        }

        if(ans == n || ans + 1 == n) {
            printf("%s\n", seq);
            continue;
        }

        string remain;
        for(int i = ans / 2; i < n - ans / 2; ++i) {
            remain += seq[i];
        }

        // debug(remain);

        string reverse_remain = remain;
        reverse(reverse_remain.begin(), reverse_remain.end());


        int t1 = solve(remain + '#' + reverse_remain);
        int t2 = solve(reverse_remain + '#' + remain);

        if(t1 > t2) {
            string result = origin.substr(0, ans / 2) + remain.substr(0, t1) + origin.substr(n - ans / 2, ans / 2);
            printf("%s\n", result.c_str());
        } else {
            string result = origin.substr(0, ans / 2) + remain.substr(remain.length() - t2, t2) + origin.substr(n - ans / 2, ans / 2);
            printf("%s\n", result.c_str());
        }
    }
    return 0;
}