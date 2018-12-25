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
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

struct Node{
    int x, y;
}E[5];
bool cmp(Node &a, Node &b) {
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
bool cmp2(Node &a, Node &b) {
    return a.y < b.y;
}
int x[5][2]; 
vector<pair<int, int> > ans;

void solve(Node A, Node B) {
    int stepx = A.x < B.x ? 1 : -1;
    int stepy = A.y < B.y ? 1 : -1;

    while(A.x != B.x) {
        A.x += stepx;
        ans.push_back(make_pair(A.x, A.y));
    }

    while(A.y != B.y) {
        A.y += stepy;
        ans.push_back(make_pair(A.x, A.y));
    }
}
int main() {
    for(int i = 0; i < 3; ++i) {
        scanf("%d %d", &E[i].x, &E[i].y);
    }

    sort(E, E + 3, cmp);
    sort(E + 1, E + 3, cmp2);
    Node tmp;
    tmp.x = min(E[1].x, E[2].x);
    if(E[1].y <= E[0].y && E[0].y <= E[2].y) {
        tmp.y = E[0].y;
    } else if(E[0].y > E[2].y) {
        tmp.y = E[2].y; 
    } else tmp.y = E[1].y;

    ans.push_back(make_pair(E[0].x, E[0].y));
    solve(E[0], tmp);
    solve(tmp, E[1]);
    solve(tmp, E[2]);
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}