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

const int N = 2005;
int isPrime[N]; 
int Prime[N];
int primeTot;

int main() {
    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[primeTot ++] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }

    int n;
    while(~scanf("%d", &n)) {
    // for(int n = 3; n <= 1000; ++n) {
        int fr = n;
        int to = n + n / 2;
        int pos1 = lower_bound(Prime, Prime + primeTot, fr) - Prime;
        int pos2 = upper_bound(Prime, Prime + primeTot, to) - Prime; pos2 --;

        if(pos1 > pos2) {
            debug("yingyingying\n");
        } else {
            // continue;
            int target = Prime[pos1] - n;
            vector<pair<int, int> > ans;

            for(int i = 0; i < n; ++i) {
                int fr = i; int to = (i + 1 + n) % n;
                ans.push_back({fr, to});
            }

            for(int i = 0; i < target; ++i) {
                int fr = i; int to = (i + n / 2) % n;
                ans.push_back({fr, to});
            }


            printf("%d\n", (int)ans.size());
            for(int i = 0, len = ans.size(); i < len; ++i) {
                printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
            }
        }


    }
    return 0;
}