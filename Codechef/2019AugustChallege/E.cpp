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

int has[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        map<int, vector<int> > mp;
        has[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &has[i]);
        }

        mp[0].push_back(0);
        for(int i = 1; i <= n; ++i) {
            // if(i) has[i] ^= has[i-1];
            has[i] ^= has[i-1];
            // printf("%d\n", has[i]);
            mp[has[i]].push_back(i);
        }

        // int cnt = 0;
        // for(int i = 1; i <= n; ++i) {
        //     for(int j = i; j <= n; ++j) {
        //         for(int k = j + 1; k <= n; ++k) {
        //             int t1 = has[j] ^ has[i-1];
        //             int t2 = has[k] ^ has[j];
        //             if(t1 == t2) {
        //                 // printf("%d %d %d\n", i, j, k);
        //                 cnt ++;
        //             }
        //         }
        //     }
        // }
        // printf("%d\n", cnt);
        // continue;

        ll ans = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            vector<int> &tmp = it->second;
            ll all = tmp[0];
            for(int j = 1, len = tmp.size(); j < len; ++j) {
                ans += 1ll * (tmp[j] - 1) * j - all;
                all += tmp[j];
            }
            // pair<int, int> tmp = it->second;
            // ans += max(0, tmp.second - tmp.first - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*

100
3
5 2 7
4
1 1 1 1


*/