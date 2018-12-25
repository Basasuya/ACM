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
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i += k) {
            for(int j = i, cnt = 0; cnt < k && j < n; j ++, ++cnt) {
                printf("%c", cnt + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}