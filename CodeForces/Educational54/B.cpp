#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

int isPrime[N]; 
int Prime[N];
int primeTot;
int main() {
    ll n;
    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }
    while(~scanf("%lld", &n)) {
        ll prime = -1;
        for(int i = 1; i <= primeTot; ++i) {
            if(n % Prime[i] == 0) {
                prime = Prime[i];
                break;
            }
            // if(1ll * Prime/[i] * Prime[i] >= n) break;
        }
        if(prime == -1) prime = n;
        // ll tt = n / prime;
        // if(prime)
        printf("%lld\n", 1 + (n - prime) / 2);
    }
    return 0;
}