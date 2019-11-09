#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
double dp[maxn*maxn];
int idx[maxn][maxn];
int ladders[maxn*maxn];
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i%2){
                idx[i][j]=(i*10+9-j);
            }else{
                idx[i][j]=(i*10+j);
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int x;scanf("%d",&x);
            ladders[idx[i][j]]=idx[i-x][j];
        }
    }
    dp[0]=0;
    for(int i=1;i<6;i++)
        dp[i]=6;
    for(int i=6;i<100;i++){
        double sum = 0;
        for(int step=1;step<=6;step++){
            sum = sum + min(dp[i-step],dp[ladders[i-step]]);
        }
        dp[i]=(sum/6)+1;
    }
    cout<< setprecision(10) << dp[99] << endl;
}