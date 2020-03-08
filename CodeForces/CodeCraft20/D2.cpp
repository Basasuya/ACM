#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
char mp[maxn][maxn];
char ans[maxn][maxn];
 
struct Node{
    int x, y;
    bool operator == (Node b) {
        return (x==b.x && y == b.y);
    }
}a[maxn][maxn];
 
 
int n;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
string dirs = "LRUD";
string undirs = "RLDU";
 
void dfs(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int b = x+dx[i];
        int c = y+dy[i];
        if(b<1 || b>n || c<1 || c>n || ans[b][c]) continue;
        if(a[b][c] == a[x][y])
        {
            ans[b][c] = dirs[i];
            dfs(b, c);
        }
    }
}
 
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        scanf("%d%d", &a[i][j].x, &a[i][j].y);
 
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(a[i][j].x == i && a[i][j].y == j)
    {
        ans[i][j] = 'X';
        dfs(i, j);
    }
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
    {
        if(a[i][j].x == -1 && !ans[i][j])
        {
            for(int k = 0; k < 4; k++)
            {
                int b = i+dx[k];
                int c = j+dy[k];
                if(b<1 || b>n || c<1 || c>n) continue;
                if(a[b][c].x == -1)
                {
                    if(!ans[b][c])
                    {
                        ans[i][j] = undirs[k];
                        ans[b][c] = dirs[k];
                    }
                    else ans[i][j] = undirs[k];
                    break;
                }
            }
 
        }
    }
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!ans[i][j])
            {
                puts("INVALID");
                return 0;
            }
    puts("VALID");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%c", ans[i][j]);
        puts("");
    }
 
    return 0;
}