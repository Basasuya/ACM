#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;


char seq[N];
int prefix[N];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq + 1);
        int ed = 0;
        int n = strlen(seq + 1);
        prefix[0] = 0;
        for(int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1] + seq[i] == '(';
        }

    }
    return 0;
}