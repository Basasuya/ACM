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


int main() {
    int _;
    int D;
    char seq[35];
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        scanf("%d %s", &D, seq);
        set<int> C, S;
        for(int i  = 0, len = strlen(seq); i < len; ++i) {
            if(seq[i] == 'C') C.insert(i);
            else S.insert(i);
        }

        // printf("hhh %s\n", seq);
        int cnt = 0;
        bool suc = false;
        while(1) {
            int damage = 0;
            for(int i  = 0, len = strlen(seq), tmp = 1; i < len; ++i) {
                if(seq[i] == 'C') tmp *= 2;
                else damage += tmp;
            }
            // printf("%d\n", damage);
            if(damage <= D) {
                suc = true;
                break;
            }

            int flag = false;
            for(int len = strlen(seq), i  = len - 1; i >= 1; --i) {
                if(seq[i] == 'S' && seq[i-1] == 'C') {
                    swap(seq[i], seq[i-1]);
                    flag = true;
                    break;
                }
            }
            if(flag == false) break;
            // if(C.empty() || S.empty()) break;
            // int cStart = *C.begin();
            // int sEnd = *(--S.end());
            // if(cStart > sEnd) break;
            // swap(seq[cStart], seq[sEnd]);
            cnt ++;
        }

        if(suc) printf("Case #%d: %d\n", cas, cnt);
        else printf("Case #%d: IMPOSSIBLE\n", cas);   
    }
    return 0;  
}
