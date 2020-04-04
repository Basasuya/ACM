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
// #include <assert.h>
#include <iomanip>
using namespace std;
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char seq[100005];
char result[100005];
int main() {
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        int n;
        scanf("%d %s", &n, seq);
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            if(seq[i] == 'S')
                result[i] = 'E';
            else 
                result[i] = 'S';
        }
  

        printf("Case #%d: ", cas);
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            printf("%c", result[i]);
        }
        printf("\n");

    
    }
    return 0;
}


/*



2
2
SE
5
EESSSESE
*/