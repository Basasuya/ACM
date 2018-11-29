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

int a[N];
int num[N], pos[N];
int main() {
    int n, c;
    while(~scanf("%d %d", &n, &c)) {
        map<int, int> mp;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int maxNum = -1; int maxPos;
        for(int i = 0; i < n; ++i) {
            mp[a[i]] ++;
            if(mp[a[i]] > maxNum || (mp[a[i]] == maxNum && a[i] == c) ) {
                maxNum = mp[a[i]];
                maxPos = a[i];
            }
            num[i] = maxNum;
            pos[i] = maxPos;
        }
        for()
    }
    return 0;
}