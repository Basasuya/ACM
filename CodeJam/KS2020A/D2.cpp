#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <assert.h>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod1=1000000007;
const int mod2=1000000009;

struct node {
    int hash1, hash2, len;
};

struct myCompare {
     bool operator()(const node& l, const node& r)const
     {
        if(l.len != r.len)
            return l.len > r.len;
        if(l.hash1 != r.hash1)
            return l.hash1 < r.hash1;
        return l.hash2 < r.hash2;
     }
};

map<node, int, myCompare> mp;
map<pair<int, int>, pair<int, int> > mp2;
char s[100100];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int _=1; _<=T; _++) {
        int n, k;
        scanf("%d%d", &n, &k);
        mp.clear();
        mp2.clear();
        for(int j=1; j<=n; j++) {
            scanf("%s", s);
            int hash1 = -1;
            int hash2 = -1;
            for(int i=0; s[i]!='\0'; i++) {
                int pre1 = hash1, pre2 = hash2;
                hash1 = (1LL * hash1 * 23 + (s[i] - 'A') + mod1) % mod1;
                hash2 = (1LL * hash2 * 33 + (s[i] - 'A') + mod2) % mod2;
                // cout << hash1 << " " << hash2 << endl;
                node tmp = (node){hash1, hash2, i+1};
                mp[tmp]++;
                mp2[make_pair(hash1, hash2)] = make_pair(pre1, pre2);
            }
        }

        int ans = 0;
        map<node, int, myCompare>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++) {
            // printf("%d %d\n", it->first.len, it->second);
            if(it->second >= k) {
                int num = it->second / k;
                ans += it->first.len * num;
                int hash1 = it->first.hash1;
                int hash2 = it->first.hash2;
                int len = it->first.len;
                while(mp2[make_pair(hash1, hash2)] != make_pair(-1, -1)) {
                    int tmp_hash1 = mp2[make_pair(hash1, hash2)].first;
                    int tmp_hash2 = mp2[make_pair(hash1, hash2)].second;
                    hash1 = tmp_hash1;
                    hash2 = tmp_hash2;
                    len--;
                    node tmp = (node){hash1, hash2, len};
                    if(mp.find(tmp) == mp.end()) assert(0);
                    mp[tmp] -= num * k;
                }
            }
        }
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}