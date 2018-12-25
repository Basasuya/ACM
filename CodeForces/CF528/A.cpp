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

char seq[55];
int main() {
    while(~scanf("%s", seq)) {
        int len = strlen(seq);
        vector<char> ans;
        int l = 0; int r = len - 1; 
        bool flag = len % 2;
        for(int i = 0; i < len; ++i) {
            if(flag) {
                ans.push_back(seq[l]); l ++;
            } else {
                ans.push_back(seq[r]); r --;
            }
            flag ^= 1;
        }

        for(int i = ans.size() - 1; i >= 0; --i) printf("%c", ans[i]); printf("\n");
    }
    return 0;
}