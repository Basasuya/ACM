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
// const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char S[M];
int n;
int X, Y;
pair<int, int> Unzip(char x) {
    switch(x) {
        case 'U': return make_pair(0, 1);
        case 'D': return make_pair(0, -1);
        case 'L': return make_pair(-1, 0);
        case 'R': return make_pair(1, 0);
    }
}
bool solve(int num) {
    // printf("%d\n", num);
    if(num > n) return false;
    int tx = 0; int ty = 0;
    for(int i = num + 1; i <= n; ++i) {
        pair<int, int> goNow = Unzip(S[i]);
        tx += goNow.first; ty += goNow.second;
    }

    int l = 1; int r = num + 1;
    while(1) {
        // printf("%d %d %d %d\n", tx, ty,l,r);
        if(abs(X - tx) + abs(Y - ty) <= num) return true;

        if(r == n + 1) break;
        pair<int, int> goNow = Unzip(S[l]);
        tx += goNow.first; ty += goNow.second;
        goNow = Unzip(S[r]);
        tx -= goNow.first; ty -= goNow.second;
        l ++; r ++;
    }

    return false;
}
int Abs(int x) {
    return x > 0 ? x : -x;
}
int main() {
    
    while(~scanf("%d", &n)) {
        scanf("%s", S + 1);
        scanf("%d %d", &X, &Y);

        int tmp1 = 0; int tmp2 = 0;
        for(int i = 1; i <= n; ++i) {
            if(S[i] == 'U' || S[i] == 'D') tmp1 ++;
            else tmp2 ++;
        }
        // printf("%d %d\n", tmp1, tmp2);

        if(Abs(X) + Abs(Y) > n || ( (n & 1) != (Abs(Y + X) & 1) ) ){
            printf("-1\n");
            continue;
        }

        int l = 0; int r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(solve(mid)) {
                // printf(" ok!\n");
                r = mid - 1;
            }
            else {
                // printf("not ok\n");
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}
/*

5
DDDDD
0 3

6
DDDDDD
0 3


3
LRU
0 -1
*/