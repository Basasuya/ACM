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

char S[N], T[N];
int main() {
    while(~scanf("%s %s", S, T)) {
        string ans = S;
        
        int cursur = 0; int type = 0;
        for(int i = 0, len = strlen(T); i < len; ++i) {
            if(type == 0) {
                if(T[i] == 'h') {
                    assert(!ans.empty());
                    cursur = max(0, cursur - 1);
                }
                else if(T[i] == 'l') {
                    assert(!ans.empty());
                    cursur = min((int)ans.length() - 1, cursur + 1);
                }
                else if(T[i] == 'x') {
                    assert(cursur < ans.length() - 1);
                    if(!ans.empty()) {
                        ans.erase(cursur, 1);
                    }
                }else if(T[i] == 'f') {
                    char tmp = T[i + 1]; ++i;
                    for(int j = cursur + 1; j < ans.length(); ++j) {
                        if(ans[j] == tmp) {
                            cursur = j;
                            // ans.erase(j, 1);
                            break;
                        }
                    }
                } else if(T[i] == 'i') {
                    type = 1;
                }
            } else {
                if(T[i] == 'e') type = 0;
                else {
                    ans.insert(cursur, string(1, T[i]));
                    cursur = cursur + 1;
                }   
            }
            // printf("%s %d\n", ans.c_str(), cursur);
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}

/*

applese
xfllhlia
appe
irtqwqqq
appe
liaaaaae
appe
xxxxxx
appe
xxxiqqq
*/