#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;


long long Pow(long long x, long long y) {
    long long ans = 1;
    while(y) {
        if(y & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    int N, L;
    while(~scanf("%d %d", &N, &L)) {
        if(N == 0 && L == 0) break;
        if(L == 0) {
            printf("0\n");
            continue;
        }

        if(N == 1) {
            printf("%d\n", L);
            continue;
        }

        long long ans = (1ll * Pow(N, L) - 1 + MOD) % MOD * N % MOD * Pow(N - 1, MOD - 2) % MOD;

        printf("%lld\n", ans);

    }
    return 0;
}