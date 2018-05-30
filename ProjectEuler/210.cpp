#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const double tiny = 1e-8;


int Ceil(double x) {
    
    int tt = int(x);
 //   printf("%d %.9f\n", tt, x);
    if(tt == x) tt ++;
    return tt;
}

int Floor(double x) {
    int tt = int(x);
    if(tt == x) tt --;
    return tt;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int r, a, b, n;
    while(~scanf("%d %d %d %d", &r, &a, &b, &n)) {
        double leftEdge = a*1.0/b;
        double rightEdge = 2*n - a*1.0/b;
        if(leftEdge > rightEdge) swap(leftEdge, rightEdge); 
        ll sum = 0;
        
        double leftDouble = r + 2*leftEdge;
        int leftInt = ceil(leftDouble);
        
        double rightDouble = r - 2*rightEdge;
        int rightInt = ceil(rightDouble);
        
        sum += 1ll * (rightInt + leftInt) * r;
    //    printf("%d %d %lld\n", leftInt, rightInt, sum);
        double cirRadius = (rightEdge - leftEdge) / sqrt(2);
        // printf("%.3f\n", cirRadius);
        ll tmpSum = 0;
        for(int i = Floor(cirRadius), xShift = 0, edge = Ceil((rightEdge - leftEdge)/2.0); i >= edge; --i) {
            // printf("%d %d\n", i, edge);
            while(1) {
                double tmpRadius = sqrt(1ll* xShift * xShift + 1ll* i * i);
                if(tmpRadius >= cirRadius) break;
                xShift ++;
            } 
            xShift --;
            tmpSum += xShift;
        }
        sum += tmpSum * 8;
        // printf("%lld\n", sum);
        sum += Floor(cirRadius) * 4 + 1;
        // printf("%lld\n", sum);
        sum += Floor((rightEdge - leftEdge)/2.0) * Floor((rightEdge - leftEdge)/2.0) * 4;

        sum -= Floor(n - leftEdge) * 2 + 1;
        printf("%lld\n", sum);
    }
    return 0;
} 