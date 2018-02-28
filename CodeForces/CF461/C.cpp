#include <cstdio>
#include <cstring>
#include <iostream>

bool boolDisctict(long long number, long long limit) {
    bool aHasReminder[100];
    memset(aHasReminder, 0, sizeof(aHasReminder));
    for (int i = 1; i <= limit; ++i) {
        long long nRemainder = number % i;
        if (aHasReminder[nRemainder] == true) {
            return false;
        }
        aHasReminder[nRemainder] = true;
    }
    return true;
}
int main() {
    long long n, k;
    while (~scanf("%lld %lld", &n, &k)) {
        printf("%s\n", boolDisctict(n, k) ? "Yes" : "No");
    }
    return 0;
}