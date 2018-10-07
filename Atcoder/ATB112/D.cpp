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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

// int isPrime[N]; 
// int Prime[N];
// int primeTot;
int main() {
    // primeTot = 0;
    // for(int i = 2; i < N; ++i) {
    //     if(!isPrime[i]) {
    //         Prime[++primeTot] = i;
    //     }
    //     for(int j = 2*i; j < N; j += i) {
    //         isPrime[j] = 1;
    //     }
    // }

    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        int ans = -1;
        for(int i = 1; i <= sqrt(m); ++i) {
            if(m % i == 0) {
                int tt = m / i;
                if(tt >= n) ans = max(ans, i);
                if(i >= n) ans = max(ans, tt);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}