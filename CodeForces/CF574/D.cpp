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
const int MOD = 998244353;
int a[MAXN];
int has[15];
int sum[15];
ll sum2[15];
ll ten[25];

ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll getSum2(int x) {
    if(x <= 0) return 0;
    else return sum2[x];
}

int getSum(int x) {
    if(x <= 0) return 0;
    else return sum[x];
}

int main() {
    int n;
    ten[0] = 1;
    for(int i = 1; i < 25; ++i) {
        ten[i] = ten[i-1] * 10 % MOD;
        // printf("%lld\n", ten[i]);
    }
    while(~scanf("%d", &n)) {
        memset(has, 0, sizeof(has));

        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        for(int i = 0; i < n; ++i) {
            int tmp = a[i];
            int cnt = 0;
            while(tmp) {
                cnt ++;
                tmp /= 10;
            }
            has[cnt] ++;   
        }
        
        sum[0] = 0;
        for(int i = 1; i < 15; ++i) {
            sum[i] = sum[i-1] + has[i];
            // printf("%d\n", sum[i]);
        }

        sum2[0] = 0;
        for(int i = 1; i < 15; ++i) {
            sum2[i] = (sum2[i-1] + 1ll * has[i] * ten[i] % MOD) % MOD;
        }

        
        
        ll result = 0;
        for(int i = 0; i < n; ++i) {
            int tmp = a[i];
            int cnt = 1;
            // ll ten = 11;
            while(tmp) {
                int tt = tmp % 10;
                result = (result + tt * getSum2(cnt - 2) % MOD * ten[cnt - 1] % MOD) % MOD;
                result = (result + tt * (n - getSum(cnt - 2)) % MOD * ten[cnt * 2 - 2] % MOD) % MOD;

                result = (result + tt * getSum2(cnt - 1) % MOD * ten[cnt - 1] % MOD) % MOD;
                result = (result + tt * (n - getSum(cnt - 1)) % MOD * ten[cnt * 2 - 1] % MOD) % MOD;
                
                tmp /= 10;
                cnt ++;
                // ten = ten * 100 % MOD;
            }
        }

        printf("%lld\n", result);
    }
    return 0;
}