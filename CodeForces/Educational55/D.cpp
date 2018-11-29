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

int a[505];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<pair<int, int> > ans;
        vector<int> tmp; vector<int> tmp2; vector<int> tmp3;

        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int cnt = 0; int all = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] > 1) {
                tmp.push_back(i);
                cnt ++; 
                tmp3.push_back(a[i]);
            } else tmp2.push_back(i);
        }
        for(int i = 0; i < tmp2.size(); ++i) {
            
        }
        int ans = tmp.size() - 1;
        // if(n - cnt == 1) ans += 1;
        // else if(n - cnt > 1) ans += 2;
        printf("YES %d\n", ans);
        for(int i = 1; i < tmp.size(); ++i) {
            printf("%d %d\n", tmp[i], tmp[i - 1]);
        }
        for(int i = 0; i < tmp2.size(); ++i) {
            if(i) printf("%d %d\n", tmp[0], tmp2[i]);
            else printf("%d %d\n", tmp[tmp.size() - 1], tmp2[i]);
        }
    }
    return 0;
}