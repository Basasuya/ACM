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

const int MAXN = 105;
int p[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        // int p;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        bool flag = true;
        for(int i = 1; i < n; ++i) {
            if(p[i-1] % n + 1 != p[i]) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            printf("YES\n"); continue;
        }

        flag = true;
        for(int i = 1; i < n; ++i) {
            if( (p[i-1] - 2 + n) % n + 1 != p[i]) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            printf("YES\n"); 
        } else printf("NO\n");
    }
    return 0;
}