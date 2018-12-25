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

const int N = 1000 * 1000 + 13;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> st;
	
	int mx = *max_element(a, a + n);
	
	forn(i, n){
		if (a[i] == mx) continue;
		
		int j = i - 1;
		while (j + 1 < n && a[j + 1] != mx){
			++j;
			if (!st.empty() && st.back() == a[j]){
				st.pop_back();
			}
			else if (st.empty() || st.back() > a[j]){
				st.push_back(a[j]);
			}
			else{
				puts("NO");
				return 0;
			}
		}
		
		if (!st.empty()){
			puts("NO");
			return 0;
		}
		
		i = j;
	}
	
	puts("YES");
	return 0;
}