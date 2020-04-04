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

ll R[10];

int main() {
    int T; int w;
    scanf("%d", &T);
    scanf("%d", &w);
    while(T --) {
    
        printf("200\n"); fflush(stdout);

        ll tmp;
        scanf("%lld", &tmp);

        R[4] = tmp / (1ll << 50); tmp = tmp % (1ll << 50);
        R[5] = tmp / (1ll << 40); tmp = tmp % (1ll << 40);
        R[6] = tmp / (1ll << 33);

        printf("56\n"); fflush(stdout);

        scanf("%lld", &tmp);

        tmp -= R[4] * (1ll << 14) + R[5] * (1ll << 11) + R[6] * (1ll << 9);

        R[1] = tmp / (1ll << 56); tmp = tmp % (1ll << 56);
        R[2] = tmp / (1ll << 28); tmp = tmp % (1ll << 28);
        R[3] = tmp / (1ll << 18);

        for(int i = 1; i <= 6; ++i) {
            if(i != 1) printf(" ");
            printf("%lld", R[i]);
        } printf("\n");
        fflush(stdout);

        int x; scanf("%d", &x);
        assert(x == 1);
    }
    return 0;
}