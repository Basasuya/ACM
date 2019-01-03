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
const int N = 2e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
typedef long long ll;


int main() {
    int T;
    scanf("%d", &T);
    // int x = 0;
    while(T --) {
        int x; scanf("%d", &x);
        // x ++;
        if(x == 179) {
            printf("360\n");
            continue;
        }
        bool flag = false;
        for(int i = 3; i <= 180; ++i) {
            if(((x * i) % 180 == 0) && ((x * i) / 180 <= i-2) && ((x * i) / 180 > 0) ) {
                printf("%d\n", i);
                flag = true;
                break;
            }
        }
        // if(!flag) printf("hhh\n");
    }
}