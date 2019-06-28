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
const int MAXN = 301;
int a[MAXN][MAXN];
int R, C, K;
int dp[MAXN][MAXN][MAXN];

int solve() {
    int answer = -1;
    for(int i = 1; i <= R; ++i) {
        for(int j = 1; j <= C; ++j) {
            
            bool flag = true;
            int minn = INF; int maxx = -1;
            for(int k = j; k <= C && flag; ++k) {
                
                minn = min(a[i][k], minn);
                maxx = max(a[i][k], maxx);
                if(maxx - minn > K) {
                    flag = false;
                    break;
                }
                dp[i][j][k] = 1;
            }
        }
    }
    

    for(int i = 1; i <= C; ++i) {
        for(int j = i; j <= C; ++j) {
            int result = 0;
            for(int k = 1; k <= R; ++k) {
                
                if(dp[k][i][j]) result ++;
                else result = 0;
                answer = max(answer, result * (j - i + 1));
            }
        }
    }

    return answer;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d %d %d", &R, &C, &K);
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        
        memset(dp, 0, sizeof(dp));

        printf("Case #%d: ", cas);    
        printf("%d\n", solve());

    }
    return 0;
}

/*

3
1 4 0
3 1 3 3
2 3 0
4 4 5
7 6 6
4 5 0
2 2 4 4 20
8 3 3 3 12
6 6 3 3 3
1 6 8 6 4

*/