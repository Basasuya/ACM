#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 
const int INF = 1e9 + 5;
const int P = 3;
 
int N;
vector<int> who;
vector<int> prefix_sums[P];
vector<int> dp[P + 1];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int K[P];
    N = 0;
 
    for (int p = 0; p < P; p++) {
        cin >> K[p];
        N += K[p];
    }
 
    who.assign(N, -1);
 
    for (int p = 0; p < P; p++)
        for (int k = 0; k < K[p]; k++) {
            int a;
            cin >> a;
            a--;
            who[a] = p;
        }
 
    for (int p = 0; p < P; p++) {
        prefix_sums[p].assign(N + 1, 0);
 
        for (int i = 0; i < N; i++)
            prefix_sums[p][i + 1] = prefix_sums[p][i] + (who[i] == p ? 1 : 0);
    }
 
    dp[P].assign(N + 1, INF);
    dp[P][N] = 0;
 
    for (int p = P - 1; p >= 0; p--) {
        dp[p].assign(N + 1, INF);
        dp[p][N] = 0;
        int minimum = INF;
 
        for (int i = N; i >= 0; i--) {
            minimum = min(minimum, i - prefix_sums[p][i] + dp[p + 1][i]);
 
            if (i < N)
                dp[p][i] = minimum - i + prefix_sums[p][i];
            printf("%d %d %d\n", p, i, dp[p][i]);
        }
    }
 
    cout << dp[0][0] << '\n';
}