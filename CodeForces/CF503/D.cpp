#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;


int main() {
    int n;
    while(~scanf("%d", &n)) {
        printf("? 1\n");
        fflush(stdout);
        int t1; scanf("%d", &t1);

        printf("? %d\n", 1 + n/2);
        fflush(stdout);
        int t2; scanf("%d", &t2);

        bool flag = t1 > t2;
        if(t1 == t2) {
            printf("! 1\n");
            fflush(stdout);
            continue;
        }

        if(n == 2) {
            printf("! -1\n");
            fflush(stdout);
            continue;
        }

        int l = 1; int r = 1+n/2;

        bool success = false;
        while(l < r - 1) {
            int mid = (l + r) >>1;
            int mid2 = mid + n/2;

            printf("? %d\n", mid);
            fflush(stdout);
            int t1; scanf("%d", &t1);

            printf("? %d\n", mid2);
            fflush(stdout);
            int t2; scanf("%d", &t2);

            if(t1 == t2) {
                success = true;
                printf("! %d\n", mid);
                fflush(stdout);
                break;
            }
            if( (t1 < t2) ^ flag) l = mid;
            else r = mid;
        }

        if(!success) {
            printf("! -1\n");
            fflush(stdout);
        }
    }
    return 0;
}