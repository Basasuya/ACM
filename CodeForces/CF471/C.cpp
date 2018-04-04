#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<long long> oddNumber;
bool isSqaure(long long x) {
    long long t1 = sqrt(x);
    return t1 * t1 == x;
}
void pre() {
    // get the a^p (p = 3,5,7,9)
    oddNumber.clear();
    for (long long i = 2; i < 1000001; ++i) {
        if (!isSqaure(i)) {
            long long initNumber = i * i * i;
            long long multiplyNumber = i * i;
            oddNumber.push_back(initNumber);
            while (1.0 * initNumber * multiplyNumber <= 1e18) {
                initNumber *= multiplyNumber;
                oddNumber.push_back(initNumber);
            }
        }
    }
    sort(oddNumber.begin(), oddNumber.end());
    oddNumber.erase(unique(oddNumber.begin(), oddNumber.end()), oddNumber.end());
}
long long solve(long long number) {
    if (number == 0)
        return 0;
    long long result = upper_bound(oddNumber.begin(), oddNumber.end(), number) - oddNumber.begin();

    result += (long long)sqrt(number);
    return result;
}
int main() {
    int Q;
    pre();
    while (~scanf("%d", &Q)) {
        for (int i = 0; i < Q; ++i) {
            long long L, R;
            scanf("%lld %lld", &L, &R);
            printf("%lld\n", solve(R) - solve(L - 1));
        }
    }
    return 0;
}