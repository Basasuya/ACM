#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
typedef long long LL;
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N];
int b[N];
int c[N * 2]; int tot;
bool solve(double mid) {
    
    for(int i = 1; i <= tot; ++i) {
        mid -= (m + mid) / c[i];
        if(mid < 0) return false;
    }
    return true;
}
int main() {
    while(~scanf("%d %d", &n, &m)) {
        tot = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);

        c[++tot] = a[1];
        for(int i = 2; i <= n; ++i) {
            c[++tot] = b[i];
            c[++tot] = a[i];
        }
        c[++tot] = b[1];

        double l = 0; double r = 1000000001;

        while(l  + 1e-6 < r) {
            double mid = (l + r) / 2;
        //    printf("%.9f\n", mid);
            if(solve(mid)) r = mid;
            else l = mid;
        }

        if( l > 1e9 ) printf("-1\n");
        else printf("%.9f\n", l);
    }
    return 0;
}