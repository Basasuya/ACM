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
int A[MAXN];

int dp[MAXN];
int num_count[MAXN];
int B[MAXN];
int C[MAXN];


int main() {
    int T;
    scanf("%d", &T);
    int test_T = 0;
    int test_origin_T = T;

    while(T --) {
        test_T ++;
        vector<int> has;
        int n;
        scanf("%d", &n);
        
        for(int i = 0; i < n + 5; ++i) {
            dp[i] = -1;
            num_count[i] = 0;
            B[i] = 0;
            C[i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            has.push_back(A[i]);
        }
        

        sort(has.begin(), has.end());
        has.erase(unique(has.begin(), has.end()), has.end());

        int siz = has.size();

        auto getPos = [&](int x) { int pos = lower_bound(has.begin(), has.end(), x) - has.begin(); return pos; }; 

        for(int i = 0; i < n; ++i) {
            int num = getPos(A[i]);
            num_count[num] ++;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int x = getPos(A[i]);
            C[x] ++;
            ans = max(ans, C[x] + num_count[x + 1] - C[x + 1]);
            // debug(ans);
        }

        for(int i = 0; i < n; ++i) {
            int x = getPos(A[i]);
            if(dp[x] == -1) {
                dp[x] = 0;
                if(x) {
                    if(B[x - 1] == num_count[x - 1]) {
                        dp[x] += dp[x - 1];
                    } else {
                        dp[x] += B[x - 1];
                    }
                }
            }
            dp[x] ++;
            B[x] ++;

            if(B[x] == num_count[x]) {
                ans = max(dp[x] + num_count[x + 1] - B[x + 1], ans);
            }
        }

        for(int i = 0; i < siz; ++i) {
            debug(dp[i]);
            ans = max(ans, dp[i]);
        }



        // for(int i = 0; i < siz; ++i) {
        //     printf("%d ", dp[i]);
        // } printf("\n");
        // if(test_origin_T < 10) 
        printf("%d\n", n - ans);
        // if(test_T == 53) {
        //     for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");
        // }
    }
    return 0;
}
 
/*
 
9
5
4 7 2 2 9
5
3 5 8 1 7
5
1 2 2 4 5
2
0 1
3
0 1 0
4
0 1 0 0
4
0 1 0 1
4
0 1 0 2
20
16 15 1 10 0 14 0 10 3 9 2 5 4 5 17 9 10 20 0 9
4
0 2 1 2 
*/