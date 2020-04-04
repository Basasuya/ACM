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
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;

vector<pair<int, int> > prepare;
vector<pair<int, int> > solve; 
vector<int> preClip;
vector<int> solveClip;
int result[2005];
char answer[2005];
int main() {
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        int n, b, f;
        scanf("%d %d %d", &n, &b, &f);
        prepare.clear();
        preClip.clear();
        prepare.push_back(make_pair(1, n));
        preClip.push_back(n - b);

        while(1) {
            solveClip.clear();
            solve.clear();
            int flag = false;
            int maxx = -1;
            for(int i = 0, len = prepare.size(); i < len; ++i) {
                int start = prepare[i].first; int end = prepare[i].second;
                // if(end == start) {
                //     solve.push_back(make_pair(start, end));
                // } else {
                    int mid = (start + end) / 2;
                    solve.push_back(make_pair(start, mid));
                    solve.push_back(make_pair(mid + 1, end));
                // }
                maxx = max(maxx, end - start);
            }
            if(maxx == 1) flag = true;

            for(int i = 0, len = solve.size(); i < len; ++i) {
                int start = solve[i].first; int end = solve[i].second;
                for(int j = start; j <= end; ++j) {
                    printf("%d", (i % 2 == 0) ? 0 : 1);
                }
            }
            printf("\n");
            fflush(stdout);
            scanf("%s", answer);
            for(int i = 0, len = preClip.size(), pre = 0; i < len; ++i) {
                int pos = pre + preClip[i];
                for(int j = pre, endJ = pre + preClip[i]; j < endJ; ++j) {
                    if(answer[j] == '1') {
                        pos = j;
                        break;
                    }
                }
                solveClip.push_back(pos - pre);
                solveClip.push_back(preClip[i] - pos + pre);
                pre += preClip[i];
            }

            if(flag == true) break;

            // assert(solve.size() == solveClip.size());
            // for(int i = 0, len = solve.size(); i < len; ++i) {
            //     int start = solve[i].first; int end = solve[i].second; int val = solveClip[i];
            //     printf("%d %d %d: ", start, end, val);
            // } printf("\n");

            prepare.swap(solve);
            preClip.swap(solveClip);
        }

        assert(solve.size() == solveClip.size());

        for(int i = 0, len = solve.size(); i < len; ++i) {
            int start = solve[i].first; int end = solve[i].second; int val = solveClip[i];
            if(start == end) {
                if(val == 1) {
                    result[start] = 1;
                } else {
                    result[start] = 0;
                }
            }
        }
        for(int i = 1, fir = true; i <= n; ++i) {
            if(result[i] == 0) {
                if(fir) fir = false;
                else printf(" ");
                printf("%d", i - 1);
            } 
        }
        printf("\n");
        fflush(stdout);

        int basa;
        scanf("%d", &basa);
    }
    return 0;
}

/*
1000
5 2 10
answer(0 3)
2 1 10
answer(0)



*/