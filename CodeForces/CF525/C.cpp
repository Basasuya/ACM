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
const int N = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int a[N];
int doo[N];
int main() {
    // freopen("int.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(int i = n - 2; i >= 0; --i) {
            doo[i] = (a[i + 1] - a[i] - 1 + 200500) % 2005;
        }
        doo[n - 1] = (n - a[n - 1] + 200500) % 2005;
        printf("%d\n", n + 1);
        for(int i = 0; i < n; ++i) printf("1 %d %d\n", i + 1, doo[i]); 
        printf("2 %d 2005\n", n);
        
    }
    return 0;
}