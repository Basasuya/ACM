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

char seq[55][55];

int ok(int x, int y) {
    if(seq[x][y] == '.' && seq[x - 1][y] == '.' && seq[x][y - 1] == '.' && seq[x + 1][y] == '.' && seq[x][y + 1] == '.') return 1;
    else return 0;
}
void solve(int x, int y) {
    seq[x][y] = '#';
    seq[x - 1][y] = '#';
    seq[x + 1][y] = '#';
    seq[x][y - 1] = '#';
    seq[x][y + 1] = '#';
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%s", seq[i] + 1);
        }

        for(int i = 2; i <= n - 1; ++i) {
            for(int j = 2; j <= n - 1; ++j) {
                if(ok(i, j)) {
                    solve(i, j);
                }
            }
        }
        bool success = true;
        for(int i = 1; i <= n && success; ++i) {
            for(int j = 1; j <= n && success; ++j) {
                if(seq[i][j] != '#') success = false;
            }
        }

        printf("%s\n", success ? "YES" : "NO");
    }
    return 0;
}