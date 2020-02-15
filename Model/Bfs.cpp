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
priority_queue<int> da; 
priority_queue<int,vector<int>,greater<int> > xiao;

int dir[10][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };
int dir2[10][2] = { {0, - 1}, {0, 1}, {1, 0}, {-1, 0} };
void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));

    while(!Q.empty()) {
        int dx = Q.front().first; int dy = Q.front().second; Q.pop();
        for(int i = 0; i < 4; ++i) {
            int tx = dx + dir[i][0]; int ty = dy + dir[i][1];
            Q.push(make_pair(tx, ty));
        }
    }
    
}



// vector<int> vc[N];

// vc[fr].push_back(to); // 加边

// for(int i = 0; i < vc[x].size(); ++i) { //遍历x的领域
//     int to = vc[x][i];
// }

// ///////

// struct Node{
//     int fr, to, nx, dis;
// }E[N << 1];
// int head[N]; int tot = 0; 
// void add(int fr, int to) {
//     E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
// }
// memset(head, -1, sizeof(head)); tot = 0;
// add(fr, to); // 加边
// for(int i = head[x]; ~i; i = E[i].nx) { //遍历x的领域
//     int to = E[i].to;
// }