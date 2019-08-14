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

const int MAXN = 4e5 + 5;
ll a[MAXN];

ll gcd(ll x, ll y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }

        ll pre = a[0];
        for(int i = 1; i < n; ++i) {
            pre = gcd(pre, a[i]);
        }

        int ans = 0;
        for(int i = 1; i <= sqrt(pre); ++i) {
            if(pre % i == 0) ans += 2; 
            if(1ll * i * i == pre) ans --;
        }
        printf("%d\n", ans);
        
    }
    return 0;
}