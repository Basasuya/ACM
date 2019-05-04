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

const int N = 1e5 + 5;

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        int oddN = 0; int evenN = 0;
        for(int i = 0; i < n; ++i) {    
            int x; scanf("%d", &x);
            if(x % 2 == 0) evenN ++;
            else oddN ++;
        }
        int oddM = 0; int evenM = 0;
        for(int i = 0; i < m; ++i) {
            int x; scanf("%d", &x);
            if(x % 2 == 0) evenM ++;
            else oddM ++;
        }

        printf("%d\n", min(oddM, evenN) + min(oddN, evenM));
    }
    return 0;
}

/*

5 4
9 14 6 2 11
8 4 7 20
5 1
2 4 6 8 10
5
1 4
10
20 30 40 50

*/