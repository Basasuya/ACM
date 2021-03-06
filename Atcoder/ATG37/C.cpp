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

const int N = 3e5 + 5;
int A[N], B[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &B[i]);
        }

        priority_queue <pair<int, int>  > Q;
        for(int i = 0; i < n; ++i) {
            // if(A[i] != B[i])
                Q.push({B[i], i});
        }

        bool flag = true; ll ans = 0;
        while(!Q.empty()) {
            auto tp = Q.top(); Q.pop();
            if(B[tp.second] == A[tp.second]) continue;
            if(B[tp.second] < A[tp.second]) {
                flag = false;
                break;
            }
            int u = tp.second;
            int pr = (u - 1 + n) % n, nx = (u + 1) % n;
            // debug(tp);
            // break;
            if (A[u]>=B[pr]&&A[u]>=B[nx]) {
                if ((A[u]-B[u])%(B[pr]+B[nx])!=0) { flag = false; break; }
                ans+=(B[u]-A[u])/(B[pr]+B[nx]);
                B[u]=A[u]; continue;
            }
            if (B[u]<B[pr]+B[nx])  { flag = false; break; }
            ans+=B[u]/(B[pr]+B[nx]);
            B[u]%=B[pr]+B[nx];
            if (B[u] < A[u]) { flag = false; break; }
            Q.push({B[u],u});
        }

        if(flag == false) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}