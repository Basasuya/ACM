#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
#include <unordered_map>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d", &a[i]);
		a[i] &= 1;
	}
	
	vector<int> st;
	forn(i, n){
		if (!st.empty() && a[i] == st.back())
			st.pop_back();
		else
			st.push_back(a[i]);
	}
	
	puts(st.size() <= 1 ? "YES" : "NO");
	return 0;
}