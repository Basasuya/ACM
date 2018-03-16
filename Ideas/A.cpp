#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
#define MS(x, y) memset(x, y, sizeof(x))
#define MP(x, y) make_pair(x, y)
const int INF = 0x3f3f3f3f;

int main() {
    double a, x, y, b, h;
    while (~scanf("%lf %lf %lf %lf %lf", &a, &x, &y, &b, &h)) {
        double hei = (b - a) * (b - x - a) / x * (-4.0) * y / x;
        printf("%.3f\n", hei);
    }
    return 0;
}
