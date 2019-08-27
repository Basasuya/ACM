#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, r;
	cin >> n >> r;
	vector<pair<int, int>> pos, neg;
	for (int i = 0; i < n; ++i) {
		pair<int, int> cur;
		cin >> cur.first >> cur.second;
		if (cur.second >= 0) pos.push_back(cur);
		else {
		    cur.first = max(cur.first, abs(cur.second));
		    neg.push_back(cur);
		}
	}
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), comp);
	
	int taken = 0;
	for (int i = 0; i < int(pos.size()); ++i) {
		if (r >= pos[i].first) {
			r += pos[i].second;
			++taken;
		}
	}
	
	vector<vector<int>> dp(neg.size() + 1, vector<int>(r + 1, 0));
	dp[0][r] = taken;
	for (int i = 0; i < int(neg.size()); ++i) {
		for (int cr = 0; cr <= r; ++cr) {
			if (cr >= neg[i].first && cr + neg[i].second >= 0) {
				dp[i + 1][cr + neg[i].second] = max(dp[i + 1][cr + neg[i].second], dp[i][cr] + 1);
			}
			dp[i + 1][cr] = max(dp[i + 1][cr], dp[i][cr]);
		}
	}
	
	int ans = 0;
	for (int cr = 0; cr <= r; ++cr) ans = max(ans, dp[int(neg.size())][cr]);
	cout << ans << endl;
	
	return 0;
}