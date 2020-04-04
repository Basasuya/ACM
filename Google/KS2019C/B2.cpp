#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int ground[301][301];
int dp[301][301][301];
int main() {
    std::ios:: sync_with_stdio(false);
    int T;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        int R, C, K;
        cin >> R >> C >> K;
        for (int i = 0; i < R; i ++) {
            for (int j = 0; j < C; j++) {
                cin >> ground[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int r = 0; r < R; r++) {
            for (int i = 0; i < C; i ++) {
                int minval = ground[r][i];
                int maxval = ground[r][i];
                for (int j = i; j < C; j++) {
                    minval = min(minval, ground[r][j]);
                    maxval = max(maxval, ground[r][j]);
                    if (maxval - minval > K) {
                        break;
                    }
                    dp[r][i][j] = 1;
                }
            }
        }
        int ans = 0;
        for (int c1 = 0; c1 < C; c1++) {
            for (int c2 = c1; c2 < C; c2++) {
                int acc = 0;
                for (int r = 0; r < R; r++) {
                    if (dp[r][c1][c2] == 0) {
                        acc = 0;
                    } else {
                        acc ++;
                    }
                    ans = max(ans, (c2 - c1 + 1) * acc);
                }
            }
        }
        cout << "Case #" << TT << ": " << ans << endl;
    }
    return 0;
}