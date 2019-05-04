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

const int N = 2e5 + 5;
int x[N];
int main() {
    int n, z;
    while(~scanf("%d %d", &n, &z)) {
        // multiset<ll> st;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
            // st.insert(x);
        }

        sort(x, x + n);
        
        int l = 0; int r = n / 2;

        while(l <= r) {
            int m = (l + r) >> 1;

            bool isok = true;
            for(int i = 0, j = n - m; j < n; ++i, ++j) {
                isok &= (x[j] - x[i]) >= z;
            }
            if(isok) l = m + 1;
            else r = m - 1;
        }
        printf("%d\n", r);
    }
    return 0;
}