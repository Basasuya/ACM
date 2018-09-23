#include <algorithm>
#include <iostream>
#include <cstdio>
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
    return 0;
}