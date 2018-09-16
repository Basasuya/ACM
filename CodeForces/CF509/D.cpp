#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int x1[N], x2[N];
int main() {
    int n, h;
    while(~scanf("%d %d", &n, &h)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d", &x1[i], &x2[i]);
        }   
        x1[n + 1] = 2000000000;
            
        int tmpAns = 0;
        int tmpLimit = h;
        int ans = -1;
        int pos = 1;
        for(int i = 1; i <= n; ++i) {
            int preLimit, preAns;

            for(int j = pos+1; j <= n + 1; ++j) {
                preLimit = tmpLimit;
                preAns = tmpAns;

                tmpLimit -= x1[j] - x2[j-1];
                tmpAns += x1[j] - x1[j-1];
                if(tmpLimit < 0) {
                    pos = j-1;
                    tmpAns += tmpLimit;
                    break;
                }
            }
            ans = max(tmpAns, ans);
            
            tmpLimit = preLimit + x1[i + 1] - x2[i];
            tmpAns = preAns - x1[i + 1] + x1[i];    
            if(pos == i) {
                tmpAns = 0;
                tmpLimit = h;
            }
        }

        printf("%d\n", ans);
    } 
    return 0;
}