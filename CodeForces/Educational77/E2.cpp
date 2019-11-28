#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    int n;
    vector<int> A;
    scanf("%d", &n);
    int l = 0;
    while ((1 << l) != n) l++;
    int f = -1;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == -1) {
            f = i;
            continue;
        }
        A.push_back(f != -1 ? a : 0);
    }
    reverse(A.begin(), A.end());
    const ll inf = 1e18;
    ll dp[20] = {};
    int cnt[20] = { n / 2 };
    for (int i = 1; i < l; i++) cnt[i] = cnt[i - 1] + (1 << l - i - 1);
    for(int i= 0; i < l; ++i) printf("%d ", cnt[i]); printf("\n");
    for (int i = 1; i < l; i++) dp[i] = inf;
    dp[0] = A[0];
    for (int i = 1; i < int(A.size()); i++) {
        ll nxt[20] = {};
        for (int j = 0; j < l; j++) nxt[j] = inf;
        for (int j = 0; j < l; j++) {
            if (i + 1 <= cnt[j]) 
                nxt[j] = min(nxt[j], dp[j]);
            nxt[j + 1] = min(nxt[j + 1], dp[j] + A[i]);
        }
        for (int j = 0; j < l; j++) dp[j] = nxt[j];
        printf("round %d: ", i); for(int j = 0; j < l; ++j) printf("%d ", dp[j]); printf("\n");
    }
    printf("%lld\n", dp[l - 1]);
}