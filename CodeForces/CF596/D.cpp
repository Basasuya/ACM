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
// #define mp make_pair
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

const int MAXN = 1e5 + 5;
int A[MAXN];
int isPrime[MAXN]; 
int Prime[MAXN];
int primeTot;
int P=37,D=1000173169;
int _P=23,_D=998244353;
int Pow[MAXN];
int _Pow[MAXN];

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        memset(isPrime, 0, sizeof(isPrime));
        primeTot = 0;
        for(int i = 2; i < MAXN; ++i) {
            if(!isPrime[i]) {
                Prime[++primeTot] = i;
                isPrime[i] = primeTot;
            }
            for(int j = 2*i; j < MAXN; j += i) {
                isPrime[j] = 1;
            }
        }

        Pow[0] = 1; _Pow[0] = 3;
        for(int i=1;i<=primeTot;i++) Pow[i] = (ll) Pow[i-1] * P % D;
        for(int i=1;i<=primeTot;i++) _Pow[i]=(ll)_Pow[i-1]*_P%_D;


        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        map<pair<int, int>, int> mp;
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            int tmp = A[i];
            int hash1 = 0; int _hash1 = 0;
            int hash2 = 0; int _hash2 = 0;
            // debug(i, A[i]);
            for(int j = 1; j <= primeTot; ++j) {
                
                if(1ll * Prime[j] * Prime[j] > tmp) {
                    break;
                }
                if(tmp % Prime[j] == 0) {
                    int id = isPrime[Prime[j]];
                    int ccnt = 0;
                    while(tmp % Prime[j] == 0) {
                        tmp /= Prime[j];
                        ccnt ++;
                    }
                    // debug(Prime[j], ccnt, id);
                    ccnt %= k;
                    if(ccnt) {
                        hash1 = ( (ll)hash1 + (ll)Pow[id] * ccnt ) % D;
                        _hash1 = ( (ll)_hash1 + (ll)Pow[id] * (k - ccnt) ) % D;
                        hash2 = ( (ll)hash2 + (ll)_Pow[id] * ccnt ) % _D;
                        _hash2 = ( (ll)_hash2 + (ll)_Pow[id] * (k - ccnt) ) % _D;
                    }
                }
            }
            if(tmp != 1) {
                int id = isPrime[tmp];
                // debug(tmp, 1, id);
                hash1 = ( (ll)hash1 + (ll)Pow[id] ) % D;
                _hash1 = ( (ll)_hash1 + (ll)Pow[id] * (k - 1) ) % D;
                hash2 = ( (ll)hash2 + (ll)_Pow[id] ) % _D;
                _hash2 = ( (ll)_hash2 + (ll)_Pow[id] * (k - 1) ) % _D;
            }
            if(mp.find(make_pair(_hash1, _hash2)) != mp.end())
                ans += mp[make_pair(_hash1, _hash2)];
            mp[make_pair(hash1, hash2)] ++;
            // debug(ans);
        }

        printf("%lld\n", ans);
    }
    return 0;
}