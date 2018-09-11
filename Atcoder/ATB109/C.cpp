#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 5;

int a[N];
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    int n, x;
    while (~scanf("%d %d", &n, &x)) {
        int ans;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            int tt = abs(a[i] - x);
            if (i)
                ans = gcd(ans, tt);
            else
                ans = tt;
        }

        printf("%d\n", ans);
    }
    return 0;
}