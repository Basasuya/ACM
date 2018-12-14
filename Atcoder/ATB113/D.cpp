#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const ll MOD = (1e+9) + 7;

ll memo[10]; // have none continuous 1 
ll dp[101][8];

void dfs(string s)
{
  if(s.size() > 8) return;

  bool f = false;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      if(f) return;
      f = true;
    }else{
      f = false;
    }
  }

  memo[s.size()]++;

  dfs(s + '0');
  dfs(s + '1');
}

int main()
{
  dfs("");
    // for(int i = 0; i < 10; ++i) printf("%d ", memo[i]); printf("\n");
  int h, w, k;
  cin >> h >> w >> k;

  dp[0][0] = 1;

  ll t;
  for(int i = 1; i <= h; i++){
    for(int j = 0; j < w; j++){
      if(j > 0){
        t = memo[max(0, w-1-(j+1))];
        t *= memo[max(0, j-2)];
        t %= MOD;
        dp[i][j] = dp[i-1][j-1] * t % MOD;
      }

      if(j < w-1){
        t = memo[max(0, j-1)];
        t *= memo[max(0, w-1-(j+2))];
        t %= MOD;
        dp[i][j] += dp[i-1][j+1] * t % MOD;
        dp[i][j] %= MOD;
      }

      t = memo[max(0, j-1)];
      t *= memo[max(0, w-1-(j+1))];
      t %= MOD;
      dp[i][j] += dp[i-1][j] * t % MOD;
      dp[i][j] %= MOD;
    }
  }

  cout << dp[h][k-1] << endl;

  return 0;
}
