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

char seq[1005];
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        scanf("%s", seq);
        int len = strlen(seq);
        sort(seq, seq + len);
        bool flag = false;
        for(int i = 1; i < len; ++i) {
            if(seq[i] != seq[i - 1]) {
                flag = true;
                break;
            }
        }
        if(flag == false) printf("-1\n");
        else printf("%s\n", seq);
    }
    return 0;
}