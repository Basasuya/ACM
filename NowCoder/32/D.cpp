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
const int N = 2e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

// struct Node{
//     int fr, to, nx, dis;
// }E[N];
// int head[N]; int tot = 0; 
int f[N];
// void add(int fr, int to, int dis) {
//     E[tot].fr = fr; E[tot].to = to; E[tot].nx = head[fr]; E[tot].dis = dis; head[fr] = tot ++;
// }
int find(int x) {
    return f[x] == x ? x : (f[x] = find(f[x]));
}

// bool cmp(Node &a, Node &b) {
//     return a.dis < b.dis;
// }
const int M = 1e6 + 5; 
// int Dis[1000005];
// int Cnt[1000005];
vector<pair<int, int> > Dis[M];
int vis[N];

int tag[M];
int main() {
    int n, m, p;
    while(~scanf("%d %d %d", &n, &m, &p)) {
        // map<int, int> Dis, Cnt;
        // // for(int i = 1; i <= n; ++i) f[i] = i;
        // memset(head, -1, sizeof(head)); tot = 0;
        // memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++i) f[i] = i;
        int maxW = -1;
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            Dis[w].push_back(make_pair(u, v));
            maxW = max(maxW, w);
            // add(v, u, w);
        }
        int mstCnt = 0;
        int ans = 0;
        int cost = 0;
        map<int, int> Ban;
        for(int i = 1; i <= maxW; ++i) {
            if(Dis[i].size() == 0) continue;
            int cntTag = 0;
            for(int j = 0; j < Dis[i].size(); ++j) {
                int u =  Dis[i][j].first; int v =  Dis[i][j].second; 
                int t1 = find(u); int t2 = find(v);
                if(t1 != t2) tag[j] = 1, cntTag ++;
                else tag[j] = 0;
            }
            int cntNow = 0;
            for(int j = 0; j < Dis[i].size(); ++j) {
                if(!tag[j]) continue;
                int u =  Dis[i][j].first; int v =  Dis[i][j].second; 
                int t1 = find(u); int t2 = find(v);
                if(t1 != t2) {
                    vis[u] = i; vis[v] = i;
                    f[t1] = t2;
                    mstCnt ++;
                    cntNow ++;
                    cost += i;
                } else if(vis[u] == vis[v] && vis[v] == i) {
                    vis[u]
                }
            }
            if(cntNow == cntTag) ans += cntNow;
            if(mstCnt == n - 1) break;
        }
        // printf("%d\n", cost);
        printf("%d\n", ans);

        // for(int j = 1; j <= m; ++j) {
        //     int minPos; int minNum = INF; int minCnt = 0;
        //     for(int i = head[j]; ~i; i = E[i].nx) {
        //         if(E[i].dis < minNum) {
        //             minNum = E[i].dis;
        //             minCnt = 1;
        //             minPos = i;
        //         } else if(E[i].dis == minNum){
        //             minCnt ++;
        //         }
        //     }
        //     if(minCnt == 1) {
        //         cnt[minPos] ++;
        //     }
        // }
        // int ans = 0;
        // for(int i = 0; i < tot; ++i) {
        //     if(cnt[i]) ans ++;
        // }
        // printf("%d\n", ans);

        // memset(f, -1, sizeof(f));
        // sort(E, E  + tot, cmp);
        // int cnt = 0;
        // for(int i = 0; i < tot; ++i) {
        //     int u = E[i].fr; int v = E[i].to; int w = E[i].dis;
        //     int t1 = find(u); int t2 = find(v);
        //     if(t1 != t2) {
        //         f[t1] = t2;
        //         cnt ++;
        //         Cnt[w] ++;
        //         printf("%d %d\n", u, v);
        //     } 
        //     if(cnt == n-1) break;
        // }
        // int ans = 0;
        // for(auto it = Dis.begin(); it != Dis.end(); ++it) {
        //     int pos = it->first;
        //     if(Dis[pos] == Cnt[pos] && Cnt[pos] != 0) ans += Dis[pos];
        // }
        // printf("%d\n", ans);
    }
    return 0;
} 