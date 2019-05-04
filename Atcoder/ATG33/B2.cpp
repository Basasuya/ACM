#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int s, int len, string foo, string bar, char add, char sub) {
  int l = 1, r = n;
  for (int i = len - 1; ~i; --i) {
    if (bar[i] == add) {
      --l;
    } else if (bar[i] == sub) {
      ++r;
    }
    l = max(l, 1);
    r = min(r, n);
    if (foo[i] == add) {
      --r;
    } else if (foo[i] == sub) {
      ++l;
    }
    if (l > r) {
      return false;
    }
  }
  return l <= s && s <= r;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int r, c, n, x, y;
  string foo, bar;
  cin >> r >> c >> n >> x >> y >> foo >> bar;
  cout << (solve(r, x, n, foo, bar, 'D', 'U') && solve(c, y, n, foo, bar, 'R', 'L') ? "YES" : "NO") << "\n";
  return 0;
}
