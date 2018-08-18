#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;

char seq[85];
int Len[2505];
int mp[2][200005];
int has[200005];
int sufLen[2505];

int Get(int flag, int tmp, int cnt) {
    if(has[tmp] == cnt) return mp[flag][tmp];
    else return 0;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
   //     memset(mp, 0, sizeof(mp));
        int ansCnt = -1; int ansPos;
        int maxLen = -1;
        int sumLen = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%s", seq);
            int len = strlen(seq);
            maxLen = max(maxLen, len);
            Len[i] = len;
            sumLen += len + 1;
        }
        Len[n] = INF;

        for(int i = 0; i < n; ++i) {
            sufLen[i] = (i ? sufLen[i-1] : 0) + Len[i] + 1;
        }
        
        int cnt = 0;
        // for(int t1 = 0; t1 < n; ++t1) {
        //     for(int t2 = t1; t2 < n; ++t2) {
            for(int i = maxLen; i <= sumLen; ++i) {
            //    int i = sufLen[t2] - (t1 ? sufLen[t1 - 1] : 0) - 1;
                if(i < maxLen || (sumLen / i < ansCnt) ) continue;
                cnt ++;
            //    std::printf("%d\n", i);
                int j = 0; int ans = -1; 
                int flag = 0;
            //    map<int, int> mp[2];
                // for(int z = 0; z <= i + 1; ++z) {
                //     mp[0][z] = mp[1][z] = 0;
                // }
                while(j < n) {
                    int tmp = 0;         
                    for(int z = 0; z <= i + 1; ++z) {
                        mp[flag ^ 1][z] = 0;
                    }
                    int pre = j;
                //    mp[flag ^ 1].clear();
                    while(tmp + Len[j] <= i && j < n) {
                        tmp += Len[j] + 1;
                        j ++;
                        if(tmp + Len[j] <= i) {
                            mp[flag ^ 1][tmp] = max(max(Get(flag, tmp-1, cnt), Get(flag, tmp, cnt)), Get(flag, tmp+1, cnt)) + 1;
                            has[tmp] = cnt + 1;
                            ans = max(ans, mp[flag ^ 1][tmp]);
                        }
                    }
                    cnt ++;
                    if(pre == j) 
                        break;
                    flag ^= 1;
                    // for(auto it = mp[flag].begin(); it != mp[flag].end(); ++it) {
                    //     printf("%d %d:", it->first, it->second);
                    // }
                    // printf("\n");
                }

            //    printf("%d\n", ans);
                if(ans > ansCnt || (ans == ansCnt && i < ansPos)) {
                    ansCnt = ans;
                    ansPos = i;
                }
            }
        //     }
        // }

        std::printf("%d %d\n", ansPos, ansCnt);
    }
    return 0;
}