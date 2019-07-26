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
int main() {
    int n;
    while(~scanf("%d", &n)) {
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            mp[a[i]] ++;
        }

        if(mp.size() == 2) {
            int tmp[10]; int cnt = 0;
            bool flag = true;
            flag &= (n % 3 == 0);
            for (auto it : mp) {
                tmp[cnt ++] = it.first;
                if(cnt == 1) {
                    flag &= it.first == 0;
                    flag &= it.second == n / 3;
                } else {
                    flag &= it.second == n / 3 * 2;
                }
                if(!flag) break;
            }
            if(flag) printf("Yes\n");
            else printf("No\n");

        } else if(mp.size() == 3) {
            int tmp[10]; int cnt = 0;
            bool flag = true;
            flag &= (n % 3 == 0);
            for (auto it : mp) {
                tmp[cnt ++] = it.first;
                flag &= it.second == n / 3;
                if(!flag) break;
            }
            flag &= (tmp[0] ^ tmp[1]) == tmp[2];
            if(flag) printf("Yes\n");
            else printf("No\n");
        } else if(mp.size() == 1) {
            if(mp.find(0) == mp.end()) printf("No\n");
            else printf("Yes\n");
        } else {
            printf("No\n");
        }

        
    }
    return 0;
}