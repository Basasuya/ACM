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
#include <string>
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

int m[] = {5, 7, 9, 11, 13, 16, 17};
int M[10];
ll S[10];
int tmp[20];
ll MulSum = 1;
long long exgcd(long long a,long long b,long long& x,long long& y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    long long r=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return r;
}

ll get(int x, int p) {
    ll t1, t2;
    exgcd(x, p, t1, t2);
    return t1;
}

int main() {
    
    {
        MulSum = 1;
        for(int i = 0; i < 7; ++i) MulSum *= m[i];
        for(int i = 0; i < 7; ++i) M[i] = MulSum / m[i];
        for(int i = 0; i < 7; ++i) S[i] = 1ll * get(M[i], m[i]) * M[i];
        // for(int i = 0; i < 7; ++i) printf("%lld ", S[i]); printf("\n");
    }

    int T, N, M;
    scanf("%d %d %d", &T, &N, &M);
    for(int cas = 1; cas <= T; ++cas) {
        ll ans = 0;
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 18; ++j) {
                if(j) printf(" ");
                printf("%d", m[i]);
            }
            printf("\n");
            fflush(stdout);

            int sum = 0;
            for(int j = 0; j < 18; ++j) {
                scanf("%d", &tmp[i]);
                sum += tmp[i];
            }
            sum %= m[i];

            ans += 1ll * sum * S[i];

        }
        ans = (ans % MulSum + MulSum) % MulSum;  
        printf("%lld\n", ans);  fflush(stdout); int x; scanf("%d", &x);
    }
    return 0;
}


/*


1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

