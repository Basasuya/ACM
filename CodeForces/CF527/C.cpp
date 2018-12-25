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

char seq[205][205];
int has[205];
int main() {
    int n;
    scanf("%d", &n);
    while(~scanf("%d", &n)) {
        memset(has, -1, sizeof(has));

        for(int i = 0; i < 2*n - 2; ++i) {
            scanf("%s", seq[i]);
        }
        int tag = -1; int tag2;
        for(int i = 0; i < 2*n-2; ++i) {
            if(strlen(seq[i]) == n - 1) {
                if(tag == -1) tag = i;
                else tag2 = i;
                // break;
            }
        }

        for(int i = 0; i < 2*n-2; ++i) {
            int len = strlen(seq[i]);
            if(has[len] == -1 && len < n - 1) {
                bool flag = true;
                for(int j = 0; j < len && flag; ++j) {
                    if(seq[tag][j] != seq[i][j])
                        flag = false;
                }
                if(flag) {
                    has[len] = i;
                }
            }
        }

        bool suc = true;
        for(int i = 1; i <= n - 2; ++i) {
            if(has[i] == -1) {
                suc = false;
                break;
            }
        }

        for(int i = 0; i < 2*n-2; ++i) {
            if(i == tag);
            else {
                int len = strlen(seq[i]);
                if(has[len] != i) {
                    bool flag = true;
                    for(int j = 0; j < len && flag; ++j) {
                        if(seq[tag2][n - 1 - len + j] != seq[i][j])
                            flag = false;
                    }
                    if(!flag) suc = false;
                }
            }   
        }

        if(suc) {
            // printf("hhh\n");
            for(int i = 0; i < 2*n-2; ++i) {
                if(i == tag) printf("P");
                else {
                    int len = strlen(seq[i]);
                    if(has[len] == i) printf("P");
                    else printf("S");
                }   
            }
            printf("\n");
            continue;
        }

        memset(has, -1, sizeof(has));
        for(int i = 0; i < 2*n-2; ++i) {
            int len = strlen(seq[i]);
            if(has[len] == -1 && len < n - 1) {
                bool flag = true;
                for(int j = 0; j < len && flag; ++j) {
                    if(seq[tag][n - 1 - len + j] != seq[i][j])
                        flag = false;
                }
                if(flag) {
                    has[len] = i;
                }
            }
        }
        // printf("%d\n", tag);
        for(int i = 0; i < 2*n-2; ++i) {
            if(i == tag) printf("S");
            else {
                int len = strlen(seq[i]);
                if(has[len] == i) printf("S");
                else printf("P");
            } 
        }
        printf("\n");
    }   
    return 0; 
}
/*

5
ba
a
baba
a
aba
abab
ab
aba

aaab

4
a
aa
ab
b
aab
aaa


*/