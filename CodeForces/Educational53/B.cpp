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

int A[M], B[M];
int pos[M];


int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &B[i]);
        
        for(int i = 1; i <= n; ++i) {
            pos[A[i]] = i;
        }

        vector<int> ans;
        int offset = 0;
        for(int i = 1; i <= n; ++i) {
            int nowPos = pos[B[i]];
            if(nowPos > offset) ans.push_back(nowPos - offset),  offset = nowPos;
            else ans.push_back(0);

           
        }

        for(int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]); printf("\n");

    }
    return 0;
}