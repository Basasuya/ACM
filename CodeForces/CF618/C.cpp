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

const int MAXN = 1e5 + 5;
int A[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int cnt[30] = {};
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            for(int j = 0; j < 30; ++j) {
                if( (A[i] >> j) & 1 ) {
                    cnt[j] ++;
                }
            }
        }

        int ans = -1; int tag = -1;

        for(int i = 0; i < n; ++i) {
            int tmp = A[i];
            for(int j = 0; j < 30; ++j) {
                if( (A[i] >> j) & 1 ) {
                    cnt[j] --;
                }
            }

            // int tmp = 0;
            for(int j = 0; j < 30; ++j) {
                if ( ( (A[i] >> j) & 1 ) && cnt[j] ) {
                    tmp -= 1 << j;
                }
            }

            if(ans < tmp) {
                ans = tmp;
                tag = i;
            }

            for(int j = 0; j < 30; ++j) {
                if( (A[i] >> j) & 1 ) {
                    cnt[j] ++;
                }
            }
        }

        vector<int> result;
        result.push_back(tag);
        for(int i = 0; i < n; ++i) {
            if(i != tag) result.push_back(i);
        }

        // int tmp = A[result[0]];
        // for(int i = 1; i < n; ++i) {
        //     tmp = (tmp | A[result[i]]) - A[result[i]];
        // }
        // debug(tmp);

        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", A[result[i]]);
        }
        printf("\n");

    }
    return 0;
}