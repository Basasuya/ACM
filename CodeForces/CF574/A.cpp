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

const int MAXN = 1005;
int drink[MAXN];
int cnt[MAXN];
int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &drink[i]);
            cnt[drink[i]] ++;
        }

        int oddCnt = 0;
        for(int i = 1; i <= k; ++i) {
            if(cnt[i] % 2 == 1) {
                oddCnt ++;
            }
        }

        printf("%d\n", n - oddCnt / 2);
    }
    return 0;
}