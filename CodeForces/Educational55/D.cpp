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
const int MOD = 998244353;
typedef long long ll;

int a[505];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<pair<int, int> > ans;
        vector<int> tmp; vector<int> tmp2; vector<int> tmp3;

        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i) {
            if(a[i] > 1) {
                tmp.push_back(i);
                tmp3.push_back(a[i]);
            } else tmp2.push_back(i);
        }
        for(int i = 1; i < tmp.size(); ++i) {
            ans.push_back(make_pair(tmp[i], tmp[i - 1]));
            tmp3[i] --; tmp3[i-1] --;
        }
        if(tmp.size() > 2) {
            swap(tmp[1], tmp[tmp.size() - 1]);
            swap(tmp3[1], tmp3[tmp3.size() - 1]);
        }

        int pos = 0;
        if(tmp3.size() > 0 && tmp3[0] > 0 && pos < tmp2.size()) {
            ans.push_back(make_pair(tmp[0], tmp2[pos]));
            pos ++;
            tmp3[0] --;
        } 
        
        if(tmp3.size() > 1 && tmp3[1] > 0 && pos < tmp2.size()) {
            ans.push_back(make_pair(tmp[1], tmp2[pos]));
            pos ++;
            tmp3[1] --;
        }

        int tmpPos = 0; bool suc = true;
        for(int i = pos; i < tmp2.size(); ++i, ++pos) {
            if(tmpPos >= tmp3.size()) {
                break;
            }
            while(tmp3[tmpPos] == 0) {
                tmpPos ++;
                if(tmpPos >= tmp3.size()) {
                    suc = false;
                    break;
                }
            }
            if(!suc) break;
            tmp3[tmpPos] --;
            ans.push_back(make_pair(tmp[tmpPos], tmp2[i]));
        }
        if(pos != tmp2.size()) {
            printf("NO\n");
            continue;
        }

        int Ans = tmp.size() - 1 + (tmp2.size() > 0) + (tmp2.size() > 1);
        printf("YES %d\n", Ans);
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }

    }
    return 0;
}