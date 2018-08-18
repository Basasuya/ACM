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
const int N = 2e5+5;

char A[N], B[N];

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        scanf("%s %s", A, B);
        if(n == m+1) {
            int flag = 1;
            int ok = 0;
            int j = 0;
            for(int i = 0; i < n && flag; ++i, ++j) {
                if(A[i] == '*') {
                    ok = 1;
                    --j;
                    continue;
                }
                if(A[i] != B[j]) flag = 0;
            }
            flag &= ok;
            flag &= j == m;
            printf("%s\n", flag? "YES": "NO");
            continue;
        }
        if(n > m) {
            
            printf("NO\n");
            continue;
        }
        int res = m - n;
        int flag = 1;
        int j = 0;
        for(int i = 0; i < n && flag; ++i, ++j) {
       //     printf("%c %c\n", A[i], B[j]);
            if(A[i] == '*') {
                j += res;
            } else if(A[i] != B[j]) flag = 0;
        }
        flag &= j == m;

        printf("%s\n", flag? "YES": "NO");
    }
    return 0;
}