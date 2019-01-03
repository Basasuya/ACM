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
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

char seq[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        int sum; bool suc; bool flag; int pos;

        sum = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == '(') sum ++;
            else sum --;
        }

        if(sum != 2 && sum != -2) {
            printf("0\n");
            continue;
        }

        flag = true; suc = true; sum = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == '(') sum ++;
            else sum --;

            if(sum < 0 && flag) {
                flag = false;
                pos = i + 1;
                sum += 2;
            }

            if(sum < 0) {
                suc = false;
                break;
            }
        }

        suc &= (sum == 0);

        if(suc) {
            printf("1\n");
            continue;
        } else if(sum == 0) {
            printf("0\n"); continue;
        }

        flag = true; pos = 0; sum = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == '(') sum ++;
            else sum --;
            if(sum < 0) {
                flag = false;
                break;
            }
            if(sum >= 2 && seq[i] == '(') pos ++;
        }

        if(!flag) printf("0\n");
        else printf("%d\n", pos);

        
    }
    return 0;
}

