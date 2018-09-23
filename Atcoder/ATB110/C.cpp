#include <assert.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int has[30];
char S[N], T[N];

vector<int> vcS[30];
vector<int> vcT[30];
int main() {
    while(~scanf("%s %s", S, T)) {
        for(int i = 0; i < 30; ++i) vcS[i].clear();
        for(int i = 0; i < 30; ++i) vcT[i].clear();
        memset(has, 0, sizeof(has));
        int n = strlen(S);

        for(int i = 0; i < n; ++i) {
            has[S[i] - 'a'] ++;
        }

        // bool hasAll = true;
        // for(int i = 0; i < 26 && hasAll; ++i) {
        //     if(!has[i]) {
        //         hasAll = false;
        //         break;
        //     } 
        // }

        for(int i = 0; i < n; ++i) {
            vcS[S[i] - 'a'].push_back(i);
            vcT[T[i] - 'a'].push_back(i);
        }

        bool flag = true;
        for(int i = 0; i < 26 && flag; ++i) {
            if(vcS[i].empty()) continue;
            for(int j = 1; j < (int)vcS[i].size() && flag; ++j) {
                if(T[vcS[i][j]] != T[vcS[i][0]]) {
                    flag = false;
                }
            }
            flag &= vcS[i].size() == vcT[T[vcS[i][0]] - 'a'].size();
        }

        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}