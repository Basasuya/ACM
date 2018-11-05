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
const int N = 1e4+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

int y[2], m[2], d[2];
int dayOfMonth[2][20] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int tranverse(int x) {
    int result = 0; int mul = 1;
    for(int i = 0; i < 4; ++i){
        result = result*10 + (x % 10);
        x /= 10;
        // mul *= 10;
    }
    return result;
}
bool ok(int year, int mon, int day) {
    bool leap;
    if( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0)) leap = true; else leap = false;
    if(mon < 1 || mon > 12) return false;
    if(day < 1 || day > dayOfMonth[leap][mon]) return false;
    return true;
}

int larger(int mon1, int day1, int mon2, int day2) {
    if(mon1 != mon2) return mon1 > mon2;
    else return day1 >= day2;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%04d-%02d-%02d", &y[0], &m[0], &d[0]);
        scanf("%04d-%02d-%02d", &y[1], &m[1], &d[1]);
        // printf("%d\n", y[1]);
        if(y[0] == y[1]) {
            int tt = tranverse(y[0]);
            int mon = tt / 100;
            int day = tt % 100;
            if(ok(y[0], mon, day) && larger(mon, day, m[0], d[0]) && larger(m[1], d[1], mon, day) ) printf("1\n");
            else printf("0\n");
        } else {
            int ans = 0;
            int tt = tranverse(y[0]);
            int mon = tt / 100;
            int day = tt % 100;
            if(ok(y[0], mon, day) && larger(mon, day, m[0], d[0])) ans ++;

            for(int i = y[0] + 1; i < y[1]; ++i) {
                int tt = tranverse(i);
                int mon = tt / 100;
                int day = tt % 100;
                // printf("%d %d\n", mon, day);
                if(ok(i, mon, day)) ans ++;
            }
            tt = tranverse(y[1]);
            mon = tt / 100;
            day = tt % 100;
            if(ok(y[1], mon, day) && larger(m[1], d[1], mon, day) ) ans ++;
            printf("%d\n", ans);
        }

    }
    return 0;
}

/*


1926-08-16
9999-12-21


*/