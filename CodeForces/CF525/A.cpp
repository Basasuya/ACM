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
    int x;
    while(~scanf("%d", &x)) {
        bool suc = false;
        for(int i = 1; i <= x && !suc; ++i) {
            for(int j = i; j <= x && !suc; ++j) {
                if(j % i == 0 && j*i > x && j / i < x) {
                    printf("%d %d\n", j, i);
                    suc = true;
                    break;
                }
            }
        }
        if(!suc) printf("-1\n");
    }
    return 0;
}