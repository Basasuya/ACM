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
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;

char seq[N];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<int> ans;
        // vector<int> ans2;

        scanf("%s", seq);
        int tmp = 0; int cntG = 0; int tmp2 = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == 'G') {
                if(tmp2) ans.push_back(-tmp2);
                tmp2 = 0;
                tmp ++;
            }
            else {
                if(tmp) { ans.push_back(tmp); cntG ++; }
                tmp = 0;
                tmp2 ++;
            } 
        }
        
        if(tmp) { ans.push_back(tmp); cntG ++; }
        if(tmp2) ans.push_back(-tmp2);

        int all = 0;
        int tag = 0;
        if(ans[0] < 0) tag ++;
        for(int i = tag; i < ans.size(); i += 2) {
            all = max(all, ans[i]);
            if(i + 2 < ans.size() && ans[i + 1] == -1) all = max(all, ans[i] + ans[i + 2] + (cntG > 2) );
        }
        
        // if(ans.size() == 1) all = ans[0];
        printf("%d\n", all);
    }
    return 0;
}