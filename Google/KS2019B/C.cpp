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

const int N = 1e5 + 5;

int A[N];
int n, s;
int ans = -1;
int solve(int l, int r) {
    if(r - l + 1 <= ans) return 0;
    unordered_map<int, int> mp;
    unordered_map<int, int>::iterator it;
    int result = 0;
    for(int i = l; i <= r; ++i) {
        mp[A[i]] ++;
        // if(mp[A[]])
    }
    
    for(it = mp.begin(); it != mp.end(); ++it) {
        int val = it->first;
        int cnt = it->second;
        if(cnt <= s) result += cnt;
    }
    return result;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        
        scanf("%d %d", &n, &s);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }

        ans = -1;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                ans = max(ans, solve(i, j));
            }
        }

        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

/*

4
6 2
1 1 4 1 4 4
8 1
1 2 500 3 4 500 6 7
10 1
100 200 8 8 8 8 8 300 400 100
12 2
40 50 1 1 1 60 70 2 2 2 80 90

*/