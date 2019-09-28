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

const int MAXN = 7005;
ll A[MAXN];
int B[MAXN];
int has[MAXN];
int du[MAXN];
struct Node{
    int to, nx;
}E[MAXN * MAXN];
int head[MAXN]; int tot = 0; 
void add(int fr, int to) {
    debug(fr, to);
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

long long d[MAXN];
int inq[MAXN];
int cnt[MAXN];
int n;

bool spfa(int s) {
    queue<int> q;
    for(int i = 0; i <= n; ++i) {
        inq[i] = 0;
        cnt[i] = 0;
        d[i] = 1e18;
    }
    d[s]=0;
    inq[s]=1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = head[u]; ~i; i = E[i].nx) {
            int to = E[i].to;
            if(d[to] > d[u] - B[to]) {
                d[to] = d[u] - B[to];
                if(!inq[to]) {
                    q.push(to);
                    inq[to] = 1;
                    // if(++cnt[e.to]>n)
                    //     return false;
                }
            }
        }
    }
    return true;
}

int main() {
    
    while(~scanf("%d", &n)) {
        for(int i = 0; i <= n; ++i) {
            has[i] = 0;
            du[i] = 0;
            head[i] = -1;
        }
        tot = 0;

        map<ll, int> mp;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &A[i]);
            if(mp.find(A[i]) == mp.end()) {
                mp[A[i]] = i;
            }
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &B[i]);
        }

        for(int i = 1; i <= n; ++i) {
            if(mp[A[i]] != i) {
                B[mp[A[i]]] += B[i];
            } else has[i] = 1;
        }

        for(int i = 1; i <= n; ++i) {
            if(has[i] == 0) continue;
            for(int j = i+1; j <= n; ++j) {
                if(has[j] == 0) continue;

                if( (A[i] & A[j]) == A[j]) {
                    add(i, j);
                    du[j] ++;
                } else if( (A[i] & A[j]) == A[i]) {
                    add(j, i);
                    du[i] ++;
                }
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            if(du[i] == 0 && has[i] == 1) {
                add(0, i);
            }
        }

        bool tag = spfa(0);
        if(tag == false) assert(0);

        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(has[i] == 1) {
                 debug(i, d[i]);
                ans = min(ans, d[i]);
            }
        }

        printf("%lld\n", -ans);
    }
    return 0;
}