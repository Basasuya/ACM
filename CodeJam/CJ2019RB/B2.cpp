
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

const unsigned long long MOD = 1ull << 63;
unsigned long long two[500];

int a[7];
int main() {
    
    two[0] = 1;
    for(int i = 1; i < 500; ++i) {
        two[i] = two[i - 1] * 2 % MOD;
    }

    for(int i = 1; i <= 6; ++i) scanf("%d", &a[i]);
    int x;
    while(~scanf("%d", &x)) {
        unsigned long long tmp = 0;
        for(int i = 1; i <= 6; ++i) {
            tmp = (tmp + two[x / i] * a[i]) % MOD;
        }
        cout << tmp << endl;
    }
    return 0;
}