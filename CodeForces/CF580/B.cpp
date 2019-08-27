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

const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int neg = 0; int pos = 0; int mid = 0; ll ans = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] < 0) ans += -1 - a[i], neg ++;
            else if(a[i] > 0) ans += a[i] - 1, pos ++;
            else mid ++;
        }
        if(mid) ans += mid;
        else if( neg % 2 == 1) ans += 2;
        printf("%lld\n", ans);
    }
    return 0;
}