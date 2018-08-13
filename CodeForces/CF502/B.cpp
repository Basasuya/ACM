#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5+5;

char A[N], B[N];
int has[5];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s %s", A, B);
        for(int i = 0; i < n; ++i) {
            has[(A[i] == '1') * 2 + (B[i] == '1')] ++;
        }

        printf("%lld\n", 1ll*has[2]*has[0] + 1ll*has[3]*has[0] + 1ll*has[2]*has[1]);
    }
    return 0;
}