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

const int N = 105;
const int INF = 0x3f3f3f3f;
int a[N];

int solve(int x,int y) {
    if(x == 1 && y == 2) return 3;
    else if(x == 1 && y == 3) return 4;
    else if(x == 2 && y == 1) return 3;
    else if(x == 2 && y == 3) return INF;
    else if(x == 3 && y == 1) return 4;
    else return INF;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        // int result = 0;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        bool suc = true;
        int result = 0;
        for(int i = 1; i < n && suc; ++i) {
            int tmp = solve(a[i-1], a[i]);
            if(tmp == INF) suc = false;
            else result += tmp;
        }
        for(int i = 1; i < n - 1; ++i) {
            if(a[i-1] == 3 && a[i] == 1 && a[i + 1] == 2) result --;
        }

        if(suc) {
            printf("Finite\n%d\n", result);
        } else printf("Infinite\n");
    }
    return 0;
}