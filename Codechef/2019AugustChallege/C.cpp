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

char seq[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s", seq);
        int pre = 0;
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            int tmp = seq[i] - '0'; tmp ^= pre;
            if(tmp == 1) {
                pre = 1;
            } else pre = 0;
        }
        if(pre == 0) printf("LOSE\n");
        else printf("WIN\n");
    }
    return 0;
}