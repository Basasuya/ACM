#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6e5+5;
const int M = 3e6+5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
 
char seq[N];
int has[30];
ll ans = 0;
 
int nx[M][27];
int sum[M];
int tot;
void insert(string tmp) {
//	cout << tmp << endl;
	int rt = 0;
	for(int i = 0; i < tmp.length(); ++i) {
		int tar = tmp[i] - 'a';
		if(nx[rt][tar] == -1) {
			nx[rt][tar] = ++tot;
			sum[tot] = 0;
		}
		rt = nx[rt][tar];
	}
	sum[rt] ++;
}
int search(string tmp) {
//	cout << "hh" << tmp << endl;
	int rt = 0;
	for(int i = 0; i < tmp.length(); ++i) {
		int tar = tmp[i] - 'a';
		if(nx[rt][tar] == -1) {
			return 0;
		}
		rt = nx[rt][tar];
	}
	return sum[rt];
}
 
 
int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(nx, -1, sizeof(nx));
		sum[0] = 0;
		tot = 0;
		memset(has, 0, sizeof(has));
 
 
		scanf("%s", seq);
		for(int i = 0; i < n; ++i) {
			has[seq[i] - 'a'] ++;
		}
		bool flag = true;
		for(int i = n; i < 2*n && flag; ++i) {
			has[seq[i] - 'a'] --;
			if(has[seq[i] - 'a'] == -1) {
				flag = false;
			}
		}
		if(!flag) {
			printf("0\n");
			continue;
		}
 
		
		int largeNum = 1<<n;
		for(int i = 0; i < largeNum; ++i) {
			string tmp1; string tmp2;
			for(int j = 0; j < n; ++j) {
				if( (i >> j) & 1 ) {
					tmp1 += seq[j];
				} else tmp2 += seq[j];
			}
			tmp1 += 'z'+1;
			tmp1 += tmp2;
			insert(tmp1);
		}
 
		ll ans = 0;
		for(int i = 0; i < largeNum; ++i) {
			string tmp1, tmp2;
			for(int j = 0; j < n; ++j) {
				if( (i >> j) & 1 ) {
					tmp1 += seq[j + n];
				} else tmp2 += seq[j + n];
			}
			reverse(tmp1.begin(), tmp1.end());
			reverse(tmp2.begin(), tmp2.end());
			tmp1 += 'z'+1;
			tmp1 += tmp2;
 
			ans += search(tmp1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}