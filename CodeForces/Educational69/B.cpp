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
int a[MAXN];
int id[MAXN];
bool cmp(int x, int y) {
    return a[x] < a[y];
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            id[i] = i;
        }
        sort(id, id + n, cmp);
        int fr = id[n-1]; int to = id[n-1];
        bool flag = true;
        for(int i = n - 2; i >= 0 && flag; --i) {
            // printf("%d\n", id[i]);
            if(fr == id[i] + 1 || to == id[i] - 1) {
                fr = min(fr, id[i]);
                to = max(to, id[i]);
            } else {
                flag = false;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");



    }
    return 0;
}