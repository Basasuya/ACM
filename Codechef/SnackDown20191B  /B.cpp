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
const int N = 1e4+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int A[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T -- ) {
        int k, n;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(A[i] != 1) {
                cnt ++;
            }
        }
        printf("%s\n", (cnt <= k) ? "YES" : "NO");
    }
    return 0;
}