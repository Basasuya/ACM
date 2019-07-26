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

ll p[MAXN];
int main() {
    ll n, m, k;
    while(~scanf("%lld %lld %lld", &n, &m, &k)) {
        for(int i = 0; i < m; ++i) {
            scanf("%lld", &p[i]);
        }

        ll edge = k; int cnt = 0;
        ll answer = 0;
        for(int i = 0; i < m; ++i) {
            // printf("%d %lld %d\n", i, edge, cnt);
            if(p[i] <= edge) {
                cnt ++;
            } else {
                if(cnt) {
                    edge += cnt; --i; answer ++; cnt = 0;
                } else {
                    edge = edge + ceil( (p[i] - edge) * 1.0 / k ) * k; --i;
                }
            }           
        }

        if(cnt) answer ++;

        printf("%lld\n", answer);
    }
    return 0;
}