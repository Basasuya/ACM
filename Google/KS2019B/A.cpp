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

const int N = 1e5 + 5;

char seq[N];
int pre[N][30];


int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        int n, q;
        scanf("%d %d", &n, &q);
        scanf("%s", seq);
        for(int i = 0, len = std::strlen(seq); i < len; ++i) {
            for(int j = 0; j < 26; ++j) {
                pre[i][j] = 0;
            }
            pre[i][seq[i] - 'A'] ++;
        }
        for(int i = 1, len = std::strlen(seq); i < len; ++i) {
            for(int j = 0; j < 26; ++j) {
                pre[i][j] += pre[i - 1][j];
            }
        }

        int result = 0;
        int tmp[30];
        for(int i = 0; i < q; ++i) {
            int l, r; scanf("%d %d", &l, &r);
            l --; r--;
            int cntOdd = 0;
            for(int j = 0; j < 26; ++j) {
                tmp[j] = pre[r][j] - ( (l == 0) ? 0 : pre[l - 1][j] );
                if(tmp[j] % 2) cntOdd ++;
            }

            if( (r - l + 1) % 2 == 0 ) {
                if(cntOdd == 0) 
                    result ++;
            } else {
                if(cntOdd == 1) result ++;
            }
        }

        printf("Case #%d: %d\n", cas, result);

    }
    return 0;
}

/*


2
7 5
ABAACCA
3 6
4 4
2 5
6 7
3 7
3 5
XYZ
1 3
1 3
1 3
1 3
1 3
*/