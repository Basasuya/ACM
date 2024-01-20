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
int A[MAXN];
int in[MAXN];
int pr[MAXN], nx[MAXN];
int n;

bool good(int i) {
    if (i < 1 || i > n) {
        return 0;
    }

    return A[pr[i]] == A[i] - 1 || A[nx[i]] == A[i] - 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        priority_queue <tuple<int, int>  > Q;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }

        pr[1] = 0; nx[0] = 1;
        nx[n] = n + 1; pr[n + 1] = n;
        A[0] = A[1]; A[n + 1] = A[n]; 
        for(int i = 1; i <= n; ++i) {
            pr[i] = i - 1;
            nx[i] = i + 1;
            in[i] = 0;
            if (good(i)) {
                in[i] = 1;
                Q.push(make_tuple(A[i], i));
            }
        }

        while(!Q.empty()) {
            auto max_item = Q.top(); Q.pop();

            int val = get<0>(max_item);
            int pos = get<1>(max_item);

            debug(val, pos);

            int pr_item = A[pr[pos]];
            int nx_item = A[nx[pos]];

            nx[pr[pos]] = nx[pos];
            pr[nx[pos]] = pr[pos];

            if (!in[pr[pos]] && good(pr[pos])) {
                in[pr[pos]] = 1;
                Q.push(make_tuple(A[pr[pos]], pr[pos]));
            }

            if (!in[nx[pos]] && good(nx[pos])) {
                in[nx[pos]] = 1;
                Q.push(make_tuple(A[nx[pos]], nx[pos]));
            }

            

        }

        int bad = 0; int bad_val = -1;
        for(int i = 1; i <= n; ++i) {
            debug(in[i]);
            if (!in[i]) {
                bad += !in[i];
                bad_val = A[i];
            }
        }

        if (bad == 1 && bad_val == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}