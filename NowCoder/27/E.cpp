#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 5e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int isPrime[N];
int primes[N];
int mu[N];
int num;
int k;
void sieve() {
    fill(isPrime, isPrime + N, 1);
    mu[1] = 1, num = 0;
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) primes[num++] = i, mu[i] = -1;
        static int d;
        for (int j = 0; j < num && (d = i * primes[j]) < N; ++j) {
            isPrime[d] = false;
            if (i % primes[j] == 0) {
                mu[d] = 0;
                break;
            } else mu[d] = -mu[i];
        }
    }
}

int Pow(int x, int y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}




void solve(int x) {
    ll ans = 0;
    for(int i = 1; i <= sqrt(x); ++i) {
        if(x % i == 0) {
            ans = (ans + Pow(i, k) * mu[x / i] % MOD + MOD) % MOD;
            if(x / i != i) {
                ans = (ans + Pow(x/i, k) * mu[i] % MOD + MOD) % MOD;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int m;
    sieve();
    while(~scanf("%d %d", &m, &k)) {
        for(int i = 0; i < m; ++i) {
            int q; scanf("%d", &q);
            solve(q);
        }
    }
    return 0;
}