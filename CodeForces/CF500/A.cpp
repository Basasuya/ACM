#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int N = 55;

int A[N], B[N];
int Has[1005];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int sum1 = 0, sum2 = 0;
        memset(Has, 0, sizeof(Has));
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]), sum1 += A[i];
        for(int i = 0; i < n; ++i) scanf("%d", &B[i]), sum2 += B[i];

        printf("%s\n", sum1 >= sum2? "Yes" : "No");
    }
    return 0;
}