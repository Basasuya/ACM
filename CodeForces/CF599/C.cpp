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

const int N = 1e6 + 5;
int isPrime[N]; 
int Prime[N];
int primeTot;
int main() {
    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }
    ll n;
    while(~scanf("%lld", &n)) {
        ll tmp = n;
        if(n <= 3) {
            printf("%lld\n", n);
            continue;
        }

        set<ll> st;

        for(int i = 1; i <= primeTot; ++i) {
            if(1ll * Prime[i] * Prime[i] > n) break;
            if(n % Prime[i] == 0) {
                while(n % Prime[i] == 0) {
                    n /= Prime[i];
                }
                st.insert(Prime[i]);
            }
        }
        if(n != 1) {
            st.insert(n);
        }

        if(st.size() == 1) {
            ll fr = *(st.begin());
            if(fr == tmp) printf("%lld\n", tmp);
            else printf("%lld\n", fr);
        } else { 
            ll fr = *(st.begin());
            if(fr == 2) {
                // assert(0);
                printf("%lld\n", 1ll);
            } else {
                // assert(0);
                printf("%lld\n", 1ll);
            }
        }
    }
    return 0;
}