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
const int N = 205;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int isPrime[N]; 
int Prime[N];
int primeTot;

bool isSemiPrime(int n) {
    bool suc = false;
    for(int i = 1; i <= primeTot && !suc; ++i) {
        if(Prime[i] > n) break;
        if(n % Prime[i] == 0 && n / Prime[i] != Prime[i]) {
            int tt = n / Prime[i];
            int pos = lower_bound(Prime+1, Prime + primeTot + 1, tt) - Prime;
            // printf("%d %d\n", Prime[pos], tt);
            if(Prime[pos] == tt) {
                suc = true;
            } 
        }
    }
    return suc;
}
int main() {
    int T;
    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }

    // for(int i = 0; i < primeTot; ++i) printf("%d ", Prime[i]); printf("\n");

    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);

        bool suc = false;
        for(int i = 4; i <= n/2 && !suc; ++i) {
            if( isSemiPrime(n - i) && isSemiPrime(i) ) suc = true;
        }
        

        printf("%s\n", suc?"YES" : "NO");
    }
    return 0;
}