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
#define forw(i, l, r) for (int i = l; i < r; ++i)
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

const int N = 1e6 + 5;
int isPrime[N]; 
int Prime[N];
int primeTot;

long long mlprime[6] = {2, 3, 5, 233, 331};

long long qmul(long long x, long long y, long long mod) {
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) % mod;
}

long long qpow(long long a, long long n, long long mod) {
    long long ret = 1;
    while (n) {
        if (n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}

bool Miller_Rabin(long long p) {
    if (p < 2) return 0;
    if (p != 2 && p % 2 == 0) return 0;
    long long s = p - 1;
    while (! (s & 1)) s >>= 1;
    for (int i = 0; i < 5; ++i) {
        if (p == mlprime[i]) return 1;
        long long t = s, m = qpow(mlprime[i], s, p);
        while (t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if (m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}



int main() {
    // for(int i = 1; i < N; ++i) PrimeA[i] ++, PrimeB[i] ++;

    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        isPrime[i] = 0;
    }
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }

    int T;
    scanf("%d", &T);
    for(int cas=1; cas <= T; ++cas) {
        int L, R;
        int ans = 0;
        scanf("%d %d", &L, &R);
        for(int i = L; i <= R; ++i) {
            int cnt = 0;
            int tmp = i;
            while(tmp % 2 == 0) {
                cnt ++;
                tmp /= 2;
            }
            // assert(tmp < N);
            if(tmp == 1) {
                if(cnt <= 3) ans ++;
            } else {
                if( (tmp < N && isPrime[tmp] == 0) || (tmp >= N && Miller_Rabin(tmp) == true) ){
                    if(cnt <= 2) ans ++;
                } else if(cnt == 1) ans ++;
            } 
        }

        printf("Case #%d: ", cas);
        printf("%d\n", ans);

    }
    return 0;
}