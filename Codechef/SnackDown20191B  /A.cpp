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
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int Year[] = {2010, 2015, 2016, 2017, 2019};
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        bool flag = false;
        for(int i = 0; i < 5 && !flag; ++i) {
            if(n == Year[i]) flag = true;
        }

        printf("%s\n", flag ? "HOSTED" : "NOT HOSTED");
    }
    return 0;
}