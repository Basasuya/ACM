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

int change[10] = {0, 3, 1, 2};
int main() {
    int x;
    while(~scanf("%d", &x)) {
        int maxx = -1; int add;
        for(int i = 0; i < 3; ++i) {
            int tmp = x + i;
            int re = change[tmp % 4];
            if(maxx < re) {
                maxx = re; add = i;
            }
        }

        printf("%d %c\n", add, 'A' + 3 - maxx);
    }
    return 0;
}