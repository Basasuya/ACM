#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int N,M,K;

struct Matrix{
	int a[25][25];
	int n;
	Matrix(int _n=0){
		memset(a,0,sizeof(a));
		n = _n;
	}
	Matrix operator *(const Matrix &T) const{
		Matrix ans = Matrix(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < n; ++k)
					ans.a[i][j] = (ans.a[i][j] + 1ll*a[i][k]*T.a[k][j]%MOD) % MOD;	
		return ans;
	}
};
Matrix operator ^(Matrix x,int y){
	Matrix ans = Matrix(x.n);
	for(int i = 0; i < x.n; ++i) ans.a[i][i] = 1;
	while(y){
		if(y&1) ans=ans*x;
		y >>= 1; x = x*x;
	}
	return ans;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&N,&M,&K);
		Matrix A = Matrix(M*2+1);
		A.a[0][0] = 1;
		Matrix P = Matrix(M*2+1);
		for(int i = 0; i < M; ++i) P.a[i][0] = K*K-K;
		for(int i = 1; i < M; ++i)  P.a[i-1][i] = K;
		P.a[M-1][M*2] = K; P.a[M*2-1][M*2] = K;
		for(int i = M; i < M*2+1; ++i) P.a[i][M] = K*K-K;
		for(int i = M+1; i < M*2; ++i) P.a[i-1][i] = K;

		P = P^N;
		P = A*P;

		int ans = 0;
		for(int i = M; i < M*2+1; ++i) ans = (ans + P.a[0][i]) % MOD;
		printf("%d\n",ans);
	}
	return 0;
}
