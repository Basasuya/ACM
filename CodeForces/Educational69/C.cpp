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

const int MAXN = 3e5 + 5;
int a[MAXN];
int b[MAXN];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if(i) {
                b[i-1] = a[i] - a[i-1];
            }
        }
        sort(b, b + n - 1, cmp);
        int tmp = 0;
        for(int i = 0; i < k - 1; ++i) {
            tmp += b[i];
        }
        printf("%d\n", a[n - 1] - a[0] - tmp);
    }
    return 0;
}