#include <iostream>
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
int X[MAXN];


int solve(int x, int y) {
    if(x > y) return y;
    else if(x == y) return 0;
    else return y - 1;
}

int has[MAXN];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(has, 0, sizeof(has));
        map<int, ll> m1;
        map<int, ll> m2;
        map<int, int> m3;
        long long tmp = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &X[i]);
            // mp[X[i]] ++;
        }


        for(int i = 1; i < m; ++i) {
            if(X[i] == X[i-1]) continue;

            tmp += abs(X[i] - X[i-1]);
            m1[X[i]] += abs(X[i] - X[i-1]);
            m1[X[i - 1]] += abs(X[i] - X[i-1]);
            m2[X[i]] += solve(X[i], X[i-1]);
            m2[X[i-1]] += solve(X[i-1], X[i]);
            m3[X[i]] ++;
            m3[X[i-1]] ++;

            int t1 = X[i]; int t2 = X[i-1];
            if(t1 > t2) swap(t1, t2);

            has[t1] ++; has[t2 + 1] --;
        }

        for(int i = 1; i <= n; ++i) has[i] += has[i-1];


        vector<ll> result;
        result.push_back(tmp);
        for(int i = 2; i <= n; ++i) {
            ll tmp2 = tmp - m1[i];
            result.push_back(tmp2 + m2[i] - (has[i] - m3[i]) );
        }

        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%lld", result[i]);
        }
        printf("\n");
    }
    return 0;
}