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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;


struct Node{
    int fr, to, nx, dis;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}
struct Hode{
  int po, di;
  Hode(int a=0, int b=0):po(a), di(b){}
  bool operator < (const Hode & T) const {
    return di > T.di;
  }
};

int dis[N], vis[N];
void dij1(int s, int t) {
  priority_queue<Hode> Q;
  memset(dis, INF, sizeof(dis));
  dis[s] = 0; 
  memset(vis, 0, sizeof(vis));
  Q.push(Hode(s, dis[s]));

  while(!Q.empty()) {
    int po = Q.top().po; Q.pop();
    if(vis[po]) continue;
    vis[po] =  1;
    for(int i = head[po]; ~i; i = E[i].nx) {
      int to = E[i].to;
      if(dis[to] > dis[po] + E[i].dis) {
        dis[to] = dis[po] + E[i].dis;
        Q.push(Hode(to, dis[to]));
      }
    }
  }
}