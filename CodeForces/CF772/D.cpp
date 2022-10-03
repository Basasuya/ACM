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
const int MOD = 1e9 + 7;
int A[MAXN];

ll fib[MAXN];


int main() {
    fib[0] = 2; fib[1] = 3;
    for(int i = 2; i < MAXN; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    
    int n, p;
    while(~scanf("%d %d", &n, &p)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            mp[A[i]] = 1;
        }

        vector<int> solve;
        sort(A, A + n);
        for(int i = n - 1; i >= 0; --i) {
            int tmp = A[i];
            bool suc = true;
            while(tmp) {
                if (tmp != A[i] && mp.find(tmp) != mp.end()) {
                    suc = false; break;
                }

                if (tmp % 2) tmp >>= 1;
                else if(tmp % 4 == 0) tmp >>= 2;
                else break;
            }
            if(suc) {
                solve.push_back(A[i]);
            }
        }
        

        ll ans = 0;
        for(int& x : solve) {
            int tmp = x; int cnt = 0;
            while(tmp) {
                tmp >>= 1; 
                cnt ++;
            }

            if (p >= cnt) {
                debug(x, fib[p - cnt]);
                ans = (ans + fib[p - cnt] + MOD - 1) % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}