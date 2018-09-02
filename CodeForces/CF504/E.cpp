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


string ans, ans2;
char seq[5];
int main() {
    int n;
    
    while(~scanf("%d", &n)) {
        int l = n, r = n;
        ans.clear();
        while(1) {
            printf("? %d %d %d %d\n", 1, 1, l-1, r); fflush(stdout);
            scanf("%s", seq);
            if(seq[0] == 'Y') {
                l --;
                ans += 'D';
            } else {
                r --;
                ans += 'R';
            }

            if(l + r == n + 1) break;
        }

        int cnt = ans.length() - 1;
        
        int l2 = l; int r2 = r;
        l = 1; r = 1;
        int endL = l2;
        ans2.clear();
        while(1) {
            assert(cnt >= 0);
            if(ans[cnt] == 'D') l2 ++;
            else r2 ++;
            cnt --;
        
            if(l == endL) {
            //    printf("%d %d\n", l2, r2);
                for(int i = 0; i < (n+1 - l - r); ++i) ans2 += 'R';
                break;
            }
            else {
                printf("? %d %d %d %d\n", l, r+1, l2, r2); fflush(stdout);
            }
            scanf("%s", seq);
            if(seq[0] == 'N') {
                l ++;
                ans2 += 'D';
            } else {
                r ++;
                ans2 += 'R';
            } 
            if(l + r == n+1) break;
        }

        reverse(ans.begin(), ans.end());
        string ans3 = ans2 + ans;
        printf("! %s\n", ans3.c_str()); 
        fflush(stdout);
    }
    return 0;
}

/*

10
..#.......
...#......
......#...
.#.......#
..........
.........#
.......#..
.......#..
..........
..........

*/