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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int isPrime[N]; 
int Prime[N];
int primeTot;
ll Mul[N];

vector<pair<int, int> > vc;


ll Pow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

ll C(int x, int y) {
    if(y == 0) return 1;
    return 1ll* Mul[x] * Pow(Mul[y] * Mul[x - y] % MOD, MOD - 2) % MOD;
}

int main() {
    int n, m;
    primeTot = 0;
    Mul[1] = 1; Mul[0] = 1;
    for(int i = 2; i < N; ++i) {
        Mul[i] = 1ll* Mul[i-1] * i % MOD;
    }
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }


    while(~scanf("%d %d", &n, &m)) {
        int M = m;
        vc.clear();

        for(int i = 1; i <= primeTot; ++i) {
            if(M % Prime[i] == 0) {
                int cnt = 0;
                while(M % Prime[i] == 0) {
                    M /= Prime[i];
                    cnt ++;
                }
                vc.emplace_back(Prime[i], cnt);
            }
            if(1ll*Prime[i]*Prime[i] > M) break;
        }
        if(M != 1) {
            vc.emplace_back(M, 1);
        }

        ll ans = 1;
        for(int i = 0; i < (int)vc.size(); ++i) {
            ans = (ans * C(n + vc[i].second - 1, n - 1)) % MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}