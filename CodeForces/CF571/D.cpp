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
double a[MAXN];
int b[MAXN];
int tag[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
        }

        ll sum = 0;
        int tmp = 0;
        for(int i = 0; i < n; ++i) {
            sum += floor(a[i]);
            b[i] = floor(a[i]); 
            if( abs(int(a[i]) - a[i]) > 1e-7) {
                // tmp ++;
                tag[i] = 1;
            } else tag[i] = 0;
        }


        for(int i = 0; i < n; ++i) {
            if(tag[i] && sum != 0) {
                sum ++;
                printf("%d\n", b[i] + 1);
            } else printf("%d\n", b[i]); 
        }

    }
    return 0;
}