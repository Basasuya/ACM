#include <cstdio>

int numberOfOrders(int limit) {
    int ans = 0;
    for (int i = 1; i <= limit; ++i) {
        for (int j = i; j <= limit; ++j) {
            int a = i;
            int b = j;
            int c = i ^ j;
            if (c <= limit && c >= b && a + b > c) {
                ans++;
                //    printf("%d %d %d\n", a, b, c);
            }
        }
    }
    return ans;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", numberOfOrders(n));
    }
    return 0;
}