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
const int MOD = 1e9 + 7;
typedef long long ll;

void Get_Next(char *ttr,int *next,int tlen)
{
    next[0]=-1;
    for(int i=1,j=-1;i<tlen;i++)
    {
        while(j>-1 && ttr[j+1]!=ttr[i])
            j=next[j];
        if(ttr[j+1]==ttr[i])
            j++;
 
        next[i]=j;
    }
}

char seq[N];
int nex[N];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        Get_Next(seq, nex, n);

        // for(int i = 0; i < n; ++i) printf("%d ", nex[i]); printf("\n");

        bool suc = false;
        for(int i = 1, j = -1; i < n; ++i) {
            // printf("%d\n", j);
            while(seq[j + 1] != seq[i]) {
                // printf("%c %c ", seq[j + 1], seq[i]);
                if(seq[i] < seq[j + 1]) { suc = true; break; }
                if(j != -1) j = nex[j];  
                else break;  
            }
            // printf("%d\n\n", j);
            if(suc) break;
            if(seq[j+1] == seq[i])
                j = (j + 1) % n;
            // if(j == n-1) break;
        }


        printf("%s\n", suc ? "YES" : "NO");
    }
    return 0;
}