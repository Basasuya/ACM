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

const int N = int(3e5) + 99;

int n, m, k;
int a[N];
long long bst[N];
long long psum[N];

long long sum(int l, int r){
    l = max(l, 0);
	return psum[r] - (l == 0? 0 : psum[l - 1]);
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		psum[i] = a[i] + (i == 0? 0 : psum[i - 1]);
	}

	long long res = 0;
	for(int len = 1; len <= m && len <= n; ++len)
			res = max(res, sum(0, len - 1) - k);
	for(int i = 0; i < n; ++i){
		if(i + 1 >= m){
			long long nbst = sum(i - m + 1, i) - k;
			if(i - m >= 0) nbst += bst[i - m];
			bst[i] = max(bst[i], + nbst);
		}

		for(int len = 0; len < m && i + len < n; ++len)
			res = max(res, bst[i] + sum(i + 1, i + len) - k * (len > 0));
	}	
    for(int i = 0; i < n; ++i) printf("%lld ", bst[i]); printf("\n");

	cout << res << endl;
	return 0;
}                             	