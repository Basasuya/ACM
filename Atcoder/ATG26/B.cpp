#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
 
 
ll gcd(ll x, ll y) {
	if(y == 0) return x;
	else return gcd(y, x%y);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T --) {
		ll A, B, C, D;
		scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
		int fl = 1;
		if(fl && A >= B && D >= B) fl = 1;
		else fl = 0;
 
		ll backStep = D % B;
	//	printf("%lld\n", backStep);
		if(fl && C < B && backStep) {
			ll tt = gcd(backStep, B);
			
			ll x = A % B;
			x += (B - x - 1) / tt * tt;
		//	printf("%lld %lld\n", tt, x);
			if(x <= C && x + backStep >= B) fl = 1;
			else fl = 0;
		}
		if(fl && backStep == 0) {
			ll x = A % B;
			if(x <= C) fl = 1;
			else fl = 0;
		}
 
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}