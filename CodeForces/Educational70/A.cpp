#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

const int MAXN = 1e5 + 5;
char A[MAXN], B[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s %s", A, B);
        int len1 = strlen(A);
        int len2 = strlen(B);
        int cnt = 0;
        bool flag = true; int tag = -1;
        for(int i = len1-1, j = len2-1, cnt = 0; i >= 0 &&  j >= 0;++cnt) {
            // printf("%d %d\n", i, j);
            if(flag) {
                if(B[j] == '1') {
                    tag = cnt;
                    flag = false;
                } 
            }
            if(!flag){
                ++j;
                if(A[i] == '1') {
                    printf("%d\n", cnt - tag);
                    break;
                }
            }
            --i; --j;
        }
        // printf("hhh");
    }
}