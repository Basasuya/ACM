#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;
using namespace std;
const int N = 105;

int n, m;
int A[N];
int Has[N];
int solve(int x) {
    if(x == 0)
        return 1;
    int all = 0;
    for(int i = 1; i <= 100; ++i) {
        all += Has[i] / x;
    }
    return all >= n;
}
int main() {
    while(~scanf("%d %d", &n, &m)) {
        memset(Has, 0, sizeof(Has));
        for(int i = 0; i < m; ++i) {
            scanf("%d", &A[i]);
            Has[A[i]] ++;
        }

        
        int l = 0; int r = 100;
        while(l <= r) {
            int mid = (l + r) >> 1;
        //    printf("%d\n", mid);
            if(!solve(mid)) r = mid - 1;
            else l = mid + 1;
        }

        printf("%d\n", l - 1);
    }
    return 0;
}