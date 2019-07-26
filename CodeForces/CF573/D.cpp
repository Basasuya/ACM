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
 
// int has[10][10];
// int dfs(int a, int b) {
//     if(a == b) return 0;
//     if(has[a][b] != -1) return has[a][b];
//     int mex[20];
//     memset(mex, 0, sizeof(mex));
//     if(b) mex[dfs(a, b - 1)] ++;
//     if(a) mex[dfs(a - 1, b)] ++;
//     int val;
//     for(int i = 0; i < 20; ++i) {
//         if(mex[i] == 0) {
//             val = i; break;
//         }
//     }
//     has[a][b] = val;
//     return val;
// }
 
const int MAXN = 1e5 + 5;
int d[MAXN];
int main () {
    int n;
    while(~scanf("%d", &n)) {
        // memset(has, -1, sizeof(has));
 
        
 
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
            // sum += d[i] % 2;
        }
        // sort(d, d + n);

        map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            sum += (d[i] + i) % 2;
            mp[d[i]] ++;
        }   

 
        if(n == 1) {
            printf("%s\n", (sum % 2 == 1) ? "sjfnb" : "cslnb");
            continue;
        }

        bool flag = false;
        int count = 0;
        for (auto it : mp) {
            if(it.second > 2) flag = true;
            if(it.second > 1) count ++;
            if(it.second > 1 && (mp.find(it.first - 1) != mp.end() && mp[it.first - 1] > 0) ) flag = true;

            if(flag == true) break;
        }
        if(count >= 2 || mp[0] > 1) flag = true;
 
 
        if(flag) {
            printf("cslnb\n");
            continue;
        }

        printf("%s\n", (sum % 2 == 1) ? "sjfnb" : "cslnb");
 
        // printf("%d\n", dfs(d[0], d[1]) );
    }
    return 0;
}