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

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        ll x;
        scanf("%lld", &x);
        int cnt = 0; int tt = 0;
        ll tmp = x;
        int pos = -1;
        while(x) {
            if(x % 2 == 1) {
                cnt ++;
                if(pos == -1) pos = tt;
            }  
            x /= 2;
            tt ++;
        }
        // printf("%d\n", cnt);
        if( (cnt == 2 && pos != 0) || (cnt == 1 && tmp >= 4)) printf("YES\n");
        else printf("NO\n");


    }
    return 0;
}