#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

vector<vector<int>> precalc(int n, vector<int> p, vector<int> id) {
    vector<vector<int>> res(n, vector<int>(n));

    for (int l = 0; l < n; l++) {
        vector<int> deg(sz(p));
        for (int i = 1; i < sz(p); i++)
            deg[p[i]]++;

        int val = 0;
        for (int r = l; r < n; r++) {
            int v = id[r];
            while (v != 0 && deg[v] == 0) {
                deg[p[v]]--;
                v = p[v];
                val++;
            }
            res[l][r] = val;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> p(2);
    vector<vector<int>> id(2);
    for (int i = 0; i < 2; i++) {
        int vn;
        cin >> vn;
        p[i].resize(vn);
        for (int v = 1; v < vn; v++) {
            cin >> p[i][v];
            p[i][v]--;
        }
        id[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> id[i][j];
            id[i][j]--;
        }
    }

    vector<vector<vector<int>>> cost(2);
    for (int i = 0; i < 2; i++)
        cost[i] = precalc(n, p[i], id[i]);

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[i] + max(
                cost[0][i][j - 1],
                cost[1][i][j - 1]
            ));
        }
    }

    cout << dp[n] << endl;
}