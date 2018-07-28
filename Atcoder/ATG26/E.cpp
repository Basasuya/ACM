#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
typedef long long LL;
using namespace std;
const int N = 3e3 + 5;

char seq[N * 2];
int locAll[N * 2];
int locA[N];
int locB[N];
int dp[N][N];
int n;
string toString(int num[]) {
    string tmp;
    for(int i = 1; i <= 2*n; ++i) {
        if(num[locAll[i]]) 
            tmp += seq[i];
    }
    return tmp;
}

int main() {
    while(~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        scanf("%s", seq + 1);
        for(int i = 1, cntA = 0, cntB = 0; i <= 2*n; ++i) {
            if(seq[i] == 'a') {
                locA[++cntA] = i;
                locAll[i] = cntA;
            } else {
                locB[++cntB] = i;
                locAll[i] = cntB;
            }
        }
        dp[n][n] = 1;

        for(int i = n-1; i >= 1; --i) {
            dp[i][i] = 1;
            if(locA[i] < locB[i]) {
                int Max = 0;
                for(int j = locA[i]; j <= locB[i]; ++j) {
                    if(locAll[j] < i)
                        continue;
                    Max = max(Max, locAll[j]);
                }
                for(int j = locB[i]+1; j <= 2*n; ++j) {
                    if(locAll[j] > Max)
                        dp[i][locAll[j]] = dp[Max + 1][locAll[j]];
                }
            } else {
                int tot = 0, Max = 0;
                for(int j = locB[i]; j <= locA[i]; ++j) {
                    if(locAll[j] < i)
                        continue;
                    if(locAll[j] != i) tot ++;
                    Max = max(Max, locAll[j]);
                    dp[i][locAll[j]] = 1;
                }    

                for(int j = locA[i]+1; j <= 2*n; ++j) {
                    if(seq[j] == 'b') {
                        if(tot == 0) {
                            dp[i][locAll[j]] = dp[Max+1][locAll[j]];
                        } else {
                            dp[i][locAll[j]] = 1;
                            tot ++;
                        }
                    } else {
                        if(tot == 0) {
                            dp[i][locAll[j]] = dp[Max+1][locAll[j]];
                        } else {
                            dp[i][locAll[j]] = 1;
                            Max = max(Max, locAll[j]);
                            tot --;
                        }
                    }
                }
                
            }
            if(toString(dp[i]) < toString(dp[i + 1])) {
                memcpy(dp[i], dp[i + 1], sizeof(dp[i + 1]));
            }
        }

        printf("%s\n", toString(dp[1]).c_str());

    }
    return 0;
}