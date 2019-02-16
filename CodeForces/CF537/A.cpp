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
const int N = 1e5 + 5;
// const int M = 2005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

char s[1005], t[1005];
int main() {
    while(~scanf("%s %s", s, t)) {
        // printf("hhh\n");
        for(int i = 0, len = strlen(s); i < len; ++i) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                s[i] = 'a';
            } else s[i] = 'b';
        }
        for(int i = 0, len = strlen(t); i < len; ++i) {
            if(t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') {
                t[i] = 'a';
            } else t[i] = 'b';
        }
        // printf("%s %s\n", s, t);

        bool suc = true;
        suc &= strlen(s) == strlen(t);
        for(int i = 0, len = strlen(t); i < len && suc; ++i) {
            if(s[i] != t[i]) {
                suc = false; break;
            }
        }

        printf("%s\n", suc ? "Yes" : "No");
    }
    return 0;
}