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
// const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int A[M];
int main() {
    int n; ll T;
    while(~scanf("%d %lld", &n, &T)) {
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);

        ll sum = 0;
        list<int> ls;
        for(int i = 0; i < n; ++i) {
            ls.push_back(A[i]);
            sum += A[i];
        }
        // printf("%lld %lld\n", sum, T);
        
        ll ans = 0; ll ttt = T;
        while(ttt) {
            // printf("%lld %lld %lld\n", ttt, ans, sum);
            if(sum <= ttt) {
                ll times = ttt / sum;
                ttt = ttt % sum;
                ans += 1ll * times * ls.size();
            } else {
                // printf("hh");
                int cnt = 0;
                for(auto it = ls.begin(); it != ls.end();) {
                    int t1 = *it;
                    if(t1 > ttt) {
                        ls.erase(it ++);
                        sum -= t1;
                    } else {
                        cnt ++;
                        ttt -= t1;
                        ans ++;
                        it ++;

                    }
                }
                if(cnt == 0) break;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}