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


int A[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        int sum = 0;
        for(int i = 0; i < n; ++i) sum += A[i];
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int tmp = sum - A[i];
            if(tmp == A[i]) cnt ++;
        }

        printf("%d\n", cnt ? cnt : -1);

    } 
    return 0;
}