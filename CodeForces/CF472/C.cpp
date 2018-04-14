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
const int N = 1e5 + 5;
#define MS(x, y) memset(x, y, sizeof(x))
#define MP(x, y) make_pair(x, y)
const int INF = 0x3f3f3f3f;

int E[N];
int main() {
    int n, U;
    while (~scanf("%d %d", &n, &U)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &E[i]);
        }

        double ans = -1;
        for (int i = 0, rightPoint = 0; i < n; ++i) {
            for (int j = rightPoint + 2; j <= n; ++j) {
                if (j == n || E[j] - E[i] > U) {
                    if (j - i > 2 && E[j - 1] - E[i] <= U) {
                        //	printf("%d %d\n", j, i);
                        ans = max(ans, (E[j - 1] - E[i + 1]) * 1.0 / (E[j - 1] - E[i]));
                    }
                    rightPoint = j - 3;
                    break;
                }
            }
            rightPoint = min(n, rightPoint);
        }

        if (ans == -1)
            printf("-1\n");
        else
            printf("%.9f\n", ans);
    }
    return 0;
}