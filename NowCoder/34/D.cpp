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
const int N = 1e3 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;
int A[N];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        sort(A, A + n);

        ll sum = 0;
        int suc = true;
        for(int i = 0; i < n; ++i) {
            if(A[i] <= sum + 1) sum += A[i];
            else  {
                suc = false;
                break;
            }
        }

        printf("%s\n", sum >= m ? "YES" : "NO");
    }
    return 0;
}