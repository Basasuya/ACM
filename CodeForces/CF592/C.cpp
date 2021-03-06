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
#define bitCount(a)  __builtin_popcount(a)
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


ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {            
        x=1; y=0;
        return a;
    }
    ll r=exgcd(b, a%b, x, y);
    ll t=y;
    y=x-(a/b)*y;  
    x=t;
    return r;
}

ll gcd(ll x, ll y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

// ll numberClose(ll x, ll y, ll mod) { // y + mod * t - > x
//     ll tmpY = y % mod;
//     if(tmpY < 0) tmpY += mod;
//     if(tmpY > x) return tmpY; 
//     else return (x - tmpY) / mod * mod + tmpY;
// } 
int main() {
    ll n, p, w, d;
    while(~scanf("%lld %lld %lld %lld", &n, &p, &w, &d)) {
        ll tmp = gcd(w, d);
        if(p % tmp != 0) {
            printf("-1\n"); continue;
        } 

        ll x, y;
        ll r = exgcd(w, d, x, y);
        
        ll minT = ceil(-p / w * y);
        ll maxT = floor(p / d * x);
        maxT = min(maxT, floor( (n * r - p * x - p * y) / (w - d) ));
        if(maxT < minT) {
            printf("-1\n"); continue;
        } 
        debug(minT, maxT, x, y);

        ll _x = (p / r * x - d / r * minT);
        ll _y = (p / r * y + w / r * minT);
        ll _z = n - _x - _y;
        printf("%lld %lld %lld\n", _x, _y, _z);
    }
    return 0;
}