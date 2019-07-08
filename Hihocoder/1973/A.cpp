#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1005;
char mp[MAXN][MAXN];
int result[MAXN][MAXN];
int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                result[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; ++i) {
            scanf("%s", mp[i] + 1); 
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(mp[i][j] == 'B') {
                    result[i][j] = -1;
                }
            }
        }

        // row direction
        for(int i = 1; i <= n; ++i) {
            bool tag = false;
            for(int j = 1; j <= m; ++j) {
                if(mp[i][j] == 'B') {
                    tag = true;
                } else {
                    if(tag) result[i][j] ++;
                }
            }

            tag = false;
            for(int j = m; j >= 1; --j) {
                if(mp[i][j] == 'B') {
                    tag = true;
                } else {
                    if(tag) result[i][j] ++;
                }
            }
        }

        // column direction
        for(int j = 1; j <= m; ++j) {
            bool tag = false;
            for(int i = 1; i <= n; ++i) {
                if(mp[i][j] == 'B') {
                    tag = true;
                } else {
                    if(tag) result[i][j] ++;
                }
            }

            tag = false;
           for(int i = n; i >= 1; --i) {
                if(mp[i][j] == 'B') {
                    tag = true;
                } else {
                    if(tag) result[i][j] ++;
                }
            }
        }
    
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(result[i][j] == -1) printf("B");
                else printf("%d", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}