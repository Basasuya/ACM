#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
typedef long long ll;

const int N = 150005;
const int INF = 0x3f3f3f3f;
int A[N];
std::map<ll, std::set<int> > mp;
std::map<int, ll> ans;
int main() {
    int n;
    while(~scanf("%d", &n)) {
        mp.clear();
        ans.clear();
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        for(int i = 0; i < n; ++i) {
            mp[A[i]].insert(i);
        }

        for(auto i = mp.begin(); i != mp.end(); ++i) {
            std::set<int> &target = i->second;
            int cnt = 0; int last;
            for(auto j = target.begin(); j != target.end(); ++j) {
                cnt ++;
                if(cnt % 2 == 0) {
                    mp[i->first * 2].insert(*j);
                }
                last = *j;
            }
            if(cnt % 2) ans[last] = i->first;
        }

        printf("%d\n", (int)ans.size());
        for(auto i = ans.begin(); i != ans.end(); ++i) {
            printf("%lld ", i->second);
        }
        printf("\n");
    }
    return 0;
}