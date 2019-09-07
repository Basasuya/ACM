#include <iostream>
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
using namespace std;
 
const int MAXN = 1000010;
 
vector<string> c;
vector<vector<bool> > b, d;
int cnt[MAXN];
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
 
	cin >> N >> M;
	c.resize(N);
	for(int i = 0; i < N; i++) cin >> c[i];
 
	b.resize(N);
	d.resize(N);
	for(int i = 0; i < N; i++) {
		b[i].resize(M, false);
		d[i].resize(M, false);
	}
 
	b[0][0] = true;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(c[i][j] == '.') {
		if(i > 0 && b[i - 1][j]) b[i][j] = true;
		if(j > 0 && b[i][j - 1]) b[i][j] = true;
	}
 
	if(!b[N - 1][M - 1]) {
		cout << "0";
		return 0;
	}
	d[N - 1][M - 1] = true;
	for(int i = N - 1; i >= 0; i--) for(int j = M - 1; j >= 0; j--) if(c[i][j] == '.') {
		if(i < N - 1 && d[i + 1][j]) d[i][j] = true;
		if(j < M - 1 && d[i][j + 1]) d[i][j] = true;
	}
 
	/*
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) printf("%d ", int(d[i][j]));
		printf("\n");
	}
	*/
 
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(b[i][j] && d[i][j]) cnt[i + j]++;
	bool ans = false;
	for(int i = 1; i < N + M - 2; i++) if(cnt[i] == 1) ans = true;
	cout << (ans ? 1 : 2);
	return 0;
}