#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
const int N = 105;
const ll INF = 1e18;
 
char S[N], T[N];
int main() {
	while(~scanf("%s %s", S, T)) {
		int len = strlen(S);
		bool flag = false;
		for(int i = 0; i < len && !flag; ++i) {
			bool flag2 = true;
			for(int j = 0; j < len && flag2; ++j) {
				if(S[j] != T[(j + i) % len]) {
					flag2 = false;
				}
			}
			if(flag2) flag = true; 
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
