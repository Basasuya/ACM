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
const int M = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char seq[M];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        if(n == 1) printf("NO\n");
        else {
            bool flag = false; int pos;
            for(int i = 1; i < n && !flag; ++i) {
                if(seq[i] != seq[i-1]) {
                    flag = true;
                    pos = i;
                }
            }

            if(flag) {
                printf("YES\n");
                printf("%c%c\n", seq[pos-1], seq[pos]);
            }
            else printf("NO\n");
        }
    }
    return 0;
}