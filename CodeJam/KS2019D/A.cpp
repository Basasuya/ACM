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

int a[MAXN];

int bitCount(int x) {
    int tmp = x;
    int cnt = 0;
    while(tmp) {
        if(tmp % 2) cnt ++;
        tmp /= 2;
    }
    return cnt % 2;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas=1; cas <= T; ++cas) {
        int n, q;
        scanf("%d %d", &n, &q);
        int all = 0;
        set<int> pos;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            all ^= a[i];
            if(bitCount(a[i]) == 1) {
                pos.insert(i);
            }
        }

        bool flag = bitCount(all) == 0;



        printf("Case #%d:", cas);
        for(int i = 0; i < q; ++i) {
            int p, v; scanf("%d %d", &p, &v);
            
            if(bitCount(v) == 1) {
                pos.insert(p);
            } else pos.erase(p);

            all ^= a[p] ^ v;
            if(bitCount(all) == 0) {
                printf(" %d", n);
            } else {
                int t1 = n - *pos.begin() - 1;
                int t2 = *pos.rbegin();
                printf(" %d", max(t1, t2));
                
            }

            a[p] = v;
        }
        printf("\n");
    }
    return 0;
}