/*
矩阵快速幂模板
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
const int MAXN = 32;
int maxn;
const int MOD = 998244353;
 
//矩阵结构体
struct Matrix{
    long long a[MAXN][MAXN];
    Matrix(){
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++){
                a[i][j]=0;
            }
        }
    }
    void init(){    //初始化为单位矩阵
        memset(a, 0, sizeof(a));
        for(int i=0;i<maxn;++i){
            a[i][i] = 1;
        }
    }
};
 
//矩阵乘法
Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            //ans.a[i][j] = 0;
            for(int k=0;k<maxn;++k){
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= MOD;
            }
        }
    }
    return ans;
}
 
void output(Matrix a){
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            cout << a.a[i][j] << " ";
        }
        cout << endl;
    }
}
//矩阵快速幂
Matrix qpow(Matrix a, long long n){
    Matrix ans;
    ans.init();
    while(n){
        if(n&1) ans = mul(ans, a);
        a = mul(a, a);
        n /= 2;
    }
    return ans;
}
 
 
long long n;
int m;
bool check(int x){
    int cnt=0;
    while(x){
        if(x&1)cnt++;
        x>>=1;
    }
    if(cnt>=(m+1)/2)return true;
    return false;
}
 
int main(){
    cin>>n>>m;
    maxn=1<<m;
    Matrix a;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            if(check(i)&&check(j)&&(i>>1)==(j&((1<<(m-1))-1))){
                a.a[i][j]=1;
            }
        }
    }
    Matrix ans= qpow(a, n-m);
    long long sum=0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            int cnt=0;
            for(int k=1;k<m;k++){
                if(check(((i<<k)|(j>>m-k))&(maxn-1))){
                    cnt++;
                }
            }
            if(cnt==m-1)sum=(sum+ans.a[i][j])%MOD;
        }
    }
    printf("%lld\n",sum);
    return 0;
}