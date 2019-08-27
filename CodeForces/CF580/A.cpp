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

const int MAXN = 105;
int a[MAXN];
int b[MAXN];
int main() {
    int n, m;
    while(~scanf("%d", &n)) {

        set<int> st;
        for(int i = 0; i < n; ++i) { scanf("%d", &a[i]); st.insert(a[i]); }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) { scanf("%d", &b[i]); st.insert(b[i]); }
        int flag = true;
        for(int i = 0; i < n && flag; ++i) {
            for(int j = 0; j < m && flag; ++j) {
                int tmp = a[i] + b[j];
                if(st.find(tmp) == st.end()) {
                    printf("%d %d\n", a[i], b[j]);
                    flag = false;
                }
            }
        }
    }
}