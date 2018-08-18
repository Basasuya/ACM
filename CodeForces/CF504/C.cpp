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
char seq[N];

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        scanf("%s", seq);

        string ans;
        int count = 0;
        int now = k;

        for(int i = 0; i < n; ++i) {
            if(seq[i] == '(') {
                if( (count+2) > now ) {
                    continue;
                }
                count ++;
                ans += '(';
                now --;
            } else {
                count --;
                ans += ')';
                now --;
            }

            if(ans.length() == k) break;
        }

        printf("%s\n", ans.c_str());
    }
    return 0;
}