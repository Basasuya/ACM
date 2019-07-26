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

const int MAXN = 2e5 + 5;
int A[MAXN];
int preMax[MAXN];
int sufMax[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }

        preMax[0] = -1;
        for(int i = 1; i <= n; ++i) {
            preMax[i] = max(preMax[i-1], A[i]);
        }
        sufMax[n + 1] = -1;
        for(int i = n; i >= 1; --i) {
            sufMax[i] = max(sufMax[i+1], A[i]);
        }
        
        for(int i = 1; i <= n; ++i) {
            int tt = max(preMax[i-1], sufMax[i + 1]);
            printf("%d\n", tt);
        }
    }
    return 0;
}