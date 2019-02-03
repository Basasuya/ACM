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
const int MOD = 1e9 + 7;
typedef long long ll;

char seq[505][505];
int n;

bool legal(int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

int ok(int x, int y) {
    
}

int main() {
    
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) scanf("%s", seq[i]);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans += ok(i, j);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}