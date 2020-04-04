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
using namespace std;
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

void solve(){
	int F = 4;
	int n, b, fake_f;
	cin >> n >> b >> fake_f;
	// assert(fake_f >= F);
	for(int f = 0; f < F; f++){
		string g;
		for(int i = 0; i < n; i++){
			g += (char)('0' + ((i >> f) & 1));
		}
		cout << g << '\n' << flush;
	}
	vector<int> answers(n-b);
	for(int f = 0; f < F; f++){
		string res;
		cin >> res;
		for(int i = 0; i < n-b; i++){
			answers[i] ^= (res[i] - '0') << f;
		}
        // for(int i = 0; i < n - b; ++i) {
        //     printf("%d ", answers[i]);
        // } printf("\n");
	}
	vector<int> broken;
	int z = 0;
	for(int i = 0; i < n-b; i++){
		while((z & 15) != answers[i]){
			cout << z << ' ';
			z++;
		}
		z++;
	}
	while(z < n){
		cout << z << ' ';
		z++;
	}
	cout << '\n';
	cout << flush;
	int res;
	cin >> res;
}


int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve();
	}
}

/*
1000
5 2 10

01010
00110
00001
00000
00000
100
010
001
000
000
answer(0 3)
000
010
001
000
000
answer(0 3)

2 1 10
answer(0)



*/