#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;

inline int Ceil(int x, int y) {
    int tt = x / y;
    return (tt * y == x)? tt : tt+1;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int res = INF; int pos;
        for(int i = 1; i <= n; ++i) {
            int tmp = i + Ceil(n, i);
            if(tmp < res) {
                res = tmp;
                pos = i;
            }
        }
        for(int i = 1; i <= n; i += pos) {
            for(int j = min(n, i + pos - 1); j >= i; --j) printf("%d ", j);
        }
        printf("\n");
    }
}