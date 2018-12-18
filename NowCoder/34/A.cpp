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

char seq[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%s", &seq);
        int len = strlen(seq);
        if( (seq[len - 1] - '0') % 2 == 0) printf("%s\n", seq);
        else {
            seq[len - 1] --;
            printf("%s\n", seq);
        }
    }
    return 0;
}