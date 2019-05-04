
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <utility>
#include<vector>
#include <iostream>
#include<queue>
 
using namespace std;
 
const int N = 2e5 + 5;
 
typedef vector<int>::iterator vi;
typedef pair<int, int> pairii;
vector<int> G[N];
queue<int> que;
 
int lev[N];
int vis[N];
 
pairii bfs(int s)
{
    que.push(s);
    memset(vis, 0, sizeof(vis));
    lev[s] = 1;
    int maxlev = 1;
    int v = s;
    while(!que.empty())
    {
        int cur = que.front();
        if(lev[cur] > maxlev) maxlev = lev[cur], v = cur;
        que.pop();
        vis[cur] = 1;
        for(vi i = G[cur].begin(); i != G[cur].end(); i++)
        {
            if(!vis[*i])
            {
                lev[*i] = lev[cur] + 1;
                que.push(*i);
            }
        }
    }
    pairii ret = make_pair(v, maxlev);
    return ret;
}
 
 
int main()
{
    int n;
    ;
    while(~scanf("%d", &n))
    {
        
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        pairii t1 = bfs(1);
        pairii t2 = bfs(t1.first);

        int diameter = t2.second;
        
        printf("diameter: %d\n", diameter);
        if(diameter % 2) printf("First\n");
        else printf("Second\n");
    }
 
    return 0;
 
}