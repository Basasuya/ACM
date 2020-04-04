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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;

int P[MAXN], A[MAXN];
vector<int> color[MAXN];
int dp[2][MAXN][MAXN];
// int tmp[MAXN];
int fl = 0;
int N, K;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)  {
        
        
        scanf("%d %d", &N, &K);
        for(int i = 0; i < MAXN; ++i) color[i].clear();
        for(int i = 1; i <= N; ++i) scanf("%d", &P[i]);
        for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);

        for(int i = 1; i <= N; ++i) {
            color[A[i]].push_back(P[i]);
        }
        for(int i = 0; i < MAXN; ++i) {
            sort(color[i].begin(), color[i].end());
        }

        vector<int> dolist;
        for(int i = 0; i < MAXN; ++i) {
            if(color[i].empty()) continue;
            dolist.push_back(i);
        }

        int len = dolist.size();
        
        memset(dp, INF, sizeof(dp));
        dp[0][0][0] = 0; dp[1][len + 1][0] = 0;
        for(int k = 1; k <= len; ++k) {
            int x = dolist[k - 1];
            for(int i = 0; i <= K; ++i) {
                if(dp[0][k - 1][i] == INF) continue;
                for(int j = 0, length = color[x].size(); j < length; ++j) {
                    if(j + i + 1 > K) break;
                    dp[0][k][i + j + 1] = min(dp[0][k][i + j + 1], dp[0][k - 1][i] + color[x][j] * 2);
                }
                dp[0][k][i] = min(dp[0][k][i], dp[0][k - 1][i]);
            }
        }

        
        for(int k = len; k >= 1; --k) {
            int x = dolist[k - 1];
            for(int i = 0; i <= K; ++i) {
                if(dp[1][k + 1][i] == INF) continue;
                for(int j = 0, length = color[x].size(); j < length; ++j) {
                    if(j + i + 1 > K) break;
                    dp[1][k][i + j + 1] = min(dp[1][k][i + j + 1], dp[1][k + 1][i] + color[x][j] * 2);
                }
                dp[1][k][i] = min(dp[1][k][i], dp[1][k + 1][i]);
            }
        }

        int ans = INF;
        for(int i = 1; i <= len; ++i) {
            int x = dolist[i-1];
            for(int j = 0, length = color[x].size(); j < length; ++j) {
                for(int k = 0; k <= K - j - 1; ++k) {
                    ans = min(1ll * ans, 1ll * dp[0][i - 1][k] + 1ll * dp[1][i + 1][K - k - j - 1] + color[x][j]);
                }
            }
        }


        printf("Case #%d: ", cas);    
        printf("%d\n", ans);
    }
    return 0;
}

/*


3
4 3
1 2 4 9
3 3 2 3
4 3
1 2 3 4
1 8 1 8
6 6
4 3 3 1 3 10000
1 2 8 9 5 7

*/