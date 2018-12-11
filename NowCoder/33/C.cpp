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
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
typedef long long ll;

char seq[100];
int has[10];
// int ans = -1;

string Ans = "-1";
bool smaller(string &A, string &B) {
    if(A == "-1") return 1;
    if(A.length() != B.length()) return A.length() < B.length();
    for(int i = 0; i < A.length(); ++i) {
        if(A[i] != B[i]) 
            return A[i] < B[i];
    }
    return 1;
}
void dfs(int turn, int num) {
    // printf("%d %d\n", turn, num);
    if(turn == 3) {
        if(num % 8 == 0) {
            string tmp = "";
            for(int j = 9; j >= 0; --j) {
                for(int i = 0; i < has[j]; ++i)
                    tmp += to_string(j);
            }
            
            string tt = to_string(num);
            //  printf("%s %d\n", tt.c_str(), turn - tt.length());
            if(tt.length() < turn) {
                int len = turn - tt.length();
                for(int i = 0; i < len; ++i) {
                    tt = '0' + tt;
                    // printf("%s\n", tt.c_str());
                }
            }
            // printf("%s\n", tt.c_str());
            tmp += tt;
            if(tmp[0] == '0') return;
            if(smaller(Ans, tmp)) {
                Ans = tmp;
            }
        }
        return;
    }

    int cnt = 0;
    for(int i = 0; i < 10; ++i) {
        if(!has[i]) continue;
        has[i] --;
        dfs(turn + 1, num * 10 + i);
        has[i] ++;
        cnt ++;
    }

    if(cnt == 0 && num % 8 == 0) {
        string tmp = to_string(num);
        if(smaller(Ans, tmp) && tmp.length() == turn) {
            Ans = tmp;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        Ans = "-1"; 
        memset(has, 0, sizeof(has));
        scanf("%s", &seq);
        bool tag = strlen(seq) < 9;
        
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            has[seq[i] - '0'] ++;
        }
        for(int i = 0; i < 10; ++i) {
            if(!has[i]) continue;
            has[i] --;
            dfs(1, i);
            has[i] ++;
        }

        printf("%s\n", Ans.c_str());
    }
    return 0;
}