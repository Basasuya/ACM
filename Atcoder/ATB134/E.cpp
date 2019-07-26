#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
vector<long long> a;
int n;
long long Go(int from, int to, long long ca, long long cb) {
  if (to - from == 1) {
    return 0;
  }
  long long best;
  best = (long long) 1e18;
  for (int i = from + 1; i < to; i++) {
    long long cur = a[i] * (ca + cb) + Go(from, i, ca, ca + cb) + Go(i, to, ca + cb, cb);
    best = min(best, cur);
  }
  return best;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << Go(0, n - 1, 1, 1) + a[0] + a[n - 1] << '\n';
  return 0;
}
