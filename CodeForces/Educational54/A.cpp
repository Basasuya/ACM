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

char s[N], t[N];
int main() {
    int n;
    while(~scanf("%d %s", &n, s)) {
        int tag = strlen(s) - 1;
        for(int i = 0, len = strlen(s); i < len - 1; ++i) {
            if(s[i] > s[i + 1]) {
                tag = i;
                break;
            }
        }
        int cnt = 0;
        for(int i = 0; i < strlen(s); ++i) {
            if(i == tag) continue;
            t[cnt ++ ] = s[i];
            // printf("%c", s[i]);
        }
        t[cnt] = 0;
        printf("%s\n", t);
    }
    return 0;
}