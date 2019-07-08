#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6 + 1;
int cnt[maxn];
int n, x, ans = 2, dif, ans_t, tmp;
vector<int> v;

int main() {
    scanf("%d", &n);
    if (n <= 2) { printf("%d\n", n); return 0; }
    for (int i = 0; i < n; ++i) { 
        scanf("%d", &x); ++cnt[x]; v.push_back(x);
        ans = max(ans, cnt[x]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    for (int i = 0; i < n - ans; ++i) {
        for (int j = i + 1; j < n - ans + 1; ++j) {
            dif = v[j] - v[i]; ans_t = 2; tmp = v[j] + dif;
            while (tmp < maxn && cnt[tmp]) {
                tmp += dif; ++ans_t;
            }
            ans = max(ans, ans_t);
        }
    }
    printf("%d\n", ans);
    return 0;
}