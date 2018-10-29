#include<cmath>
#include<map>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 505;
const int INF = 0x3f3f3f3f;
#define MP(x, y) make_pair(x, y)

struct Node{
  int fr, to, nx, di, ti;
}E[N*N*2];
int head[N], tot;
void add(int fr, int to, int di, int ti) {
  E[tot].to = to; E[tot].di = di; E[tot].ti = ti; E[tot].nx = head[fr];
  head[fr] = tot ++;
}
vector<int> ans1; int Ans1;
vector<int> ans2; int Ans2;

struct Hode{
  int po, di, ti;
  Hode(int a=0, int b=0, int c=0):po(a), di(b), ti(c){}
  bool operator < (const Hode & T) const {
    if(di != T.di) return di > T.di;
    else return ti > T.ti;
  }
};
struct Tode{
  int po, di, ti;
  Tode(int a=0, int b=0, int c=0):po(a), di(b), ti(c){}
  bool operator < (const Tode & T) const {
    if(ti != T.ti) return ti > T.ti;
    else return di > T.di;
  }
};

int pre[N], vis[N];
int dis[N], tim[N];
void dfs1(int x, int tag) {
  if(x == tag) return;
  dfs1(pre[x], tag);
  ans1.push_back(x);
}
void dfs2(int x, int tag) {
  if(x == tag) return;
  dfs2(pre[x], tag);
  ans2.push_back(x);
}


void dij1(int s, int t) {
  priority_queue<Hode> Q;
  memset(dis, INF, sizeof(dis));
  memset(tim, INF, sizeof(tim));
  dis[s] = 0; tim[s] = 0;
  memset(vis, 0, sizeof(vis));
  Q.push(Hode(s, dis[s], tim[s]));

  while(!Q.empty()) {
    int po = Q.top().po; Q.pop();
    if(vis[po]) continue;
    vis[po] =  1;
    for(int i = head[po]; ~i; i = E[i].nx) {
      int to = E[i].to;
      if(dis[to] > dis[po] + E[i].di) {
        dis[to] = dis[po] + E[i].di;
        tim[to] = tim[po] + E[i].ti;
        pre[to] = po;
        Q.push(Hode(to, dis[to], tim[to]));
      }else if(dis[to] == dis[po] + E[i].di && tim[to] > tim[po] + E[i].ti) {
        tim[to] = tim[po] + E[i].ti;
        pre[to] = po;
        Q.push(Hode(to, dis[to], tim[to]));
      } 
    }
  }
//  printf("Distance = %d: %d", dis[t], s);
  ans1.push_back(s); Ans1 = dis[t];
  dfs1(t, s);
//  printf("\n");
}
void dij2(int s, int t) {
  priority_queue<Tode> Q;
  memset(dis, INF, sizeof(dis));
  memset(tim, INF, sizeof(tim));
  dis[s] = 0; tim[s] = 0;
  memset(vis, 0, sizeof(vis));
  Q.push(Tode(s, dis[s], tim[s]));

  while(!Q.empty()) {
    int po = Q.top().po; Q.pop();
    if(vis[po]) continue;
    vis[po] =  1;
    for(int i = head[po]; ~i; i = E[i].nx) {
      int to = E[i].to;
      if(tim[to] > tim[po] + E[i].ti) {
        dis[to] = dis[po] + 1;
        tim[to] = tim[po] + E[i].ti;
        pre[to] = po;
        Q.push(Tode(to, dis[to], tim[to]));
      }else if(tim[to] == tim[po] + E[i].ti && dis[to] > dis[po] + 1) {
        dis[to] = dis[po] + 1;
        pre[to] = po;
        Q.push(Tode(to, dis[to], tim[to]));
      } 
    }
  }
  ans2.push_back(s); Ans2 = tim[t];
  dfs2(t, s); 
}
int main() {
  int n, m;
  while(~scanf("%d %d", &n, &m)) {
    ans1.clear(); ans2.clear();
    memset(head, -1, sizeof(head));
    tot = 0;

    for(int i = 0; i < m; ++i) {
      int a, b, c, d, e; scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
      add(a, b, d, e);
      if(!c) add(b, a, d, e);
    }
    int s,t; scanf("%d %d", &s, &t);

    dij1(s, t);
    dij2(s, t);
  //  if(s == t) while(1);

    int fl = 1;
    for(int i = 0; i < min(ans1.size(), ans2.size()); ++i) {
      if(ans1[i] != ans2[i]) {
        fl = 0; break;
      }
    }

    if(fl) {
      printf("Distance = %d; Time = %d: ", Ans1, Ans2);
      for(int i = 0; i < ans1.size(); ++i) {
        if(i) printf(" -> ");
        printf("%d", ans1[i]);
      } printf("\n");
    }else {
      printf("Distance = %d: ", Ans1);
      for(int i = 0; i < ans1.size(); ++i) {
        if(i) printf(" -> ");
        printf("%d", ans1[i]);
      }
      printf("\nTime = %d: ", Ans2);
      for(int i = 0; i < ans2.size(); ++i) {
        if(i) printf(" -> ");
        printf("%d", ans2[i]);
      }
      printf("\n");
    }
  }
  return 0;
}