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
 
const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 5;
int A[MAXN];
// int dp[MAXN];
 
ll solve(vector<int> & vc) {
    ll sum = 0;
    int n = vc.size();

    vector<int> count;
    for(int i = 0; i < n; ++i) {
        sum += vc[i] / 2;
        vc[i] %= 2;
        if(vc[i]) count.push_back(i);
    }

    if(count.size() == 0) return sum;
 
    // debug(count);
    // int pre = 0;
    vector<int> pre;
    int tag = 1;
    pre.push_back(count[0]);
    for(int i = 1, len = count.size(); i < len; ++i) {   
        if(pre.size() == 0) pre.push_back(count[i]);
        else if((count[i] - pre.back()) % 2 == tag) { 
            sum ++;
            pre.pop_back();
            // tag ^= 1;
        } else pre.push_back(count[i]);

        // debug(pre);
        // else if()
    }

    return sum;
}
 
int main() {
    int n;
    while(~scanf("%d", &n)) {
        // memset(dp, 0, sizeof(dp));
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
 
        vector<int> tmp;
        for(int i = 0; i < n; ++i) {
            tmp.push_back(A[i]);
        }
 
        // vector<>
        
 
        // debug(sum, dp[n-1]);
 
        printf("%lld\n", solve(tmp));
 
    }
    return 0;
}


/*


100
494 493 483 483 482 479 469 455 452 448 446 437 436 430 426 426 423 418 417 413 409 403 402 398 388 386 384 379 373 372 366 354 353 347 344 338 325 323 323 322 310 306 303 302 299 296 291 290 288 285 281 274 258 254 253 250 248 248 247 243 236 235 233 227 227 223 208 204 200 196 192 191 185 184 183 174 167 167 165 163 158 139 138 132 123 122 111 91 89 88 83 62 60 58 45 39 38 34 26 3

*/