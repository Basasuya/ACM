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

const int MAXN = 5e4 + 5;
char seq[MAXN];
const int INF = 0x3f3f3f3f;
set<pair<int, int>> col[MAXN];
set<pair<int, int>> row[MAXN];


void insert(set<pair<int, int>> &st, int t1, int t2) {
    if(t1 <= t2) st.insert(make_pair(t1, t2));
}

void solve(int& x, int& y, char dir) {
    if(dir == 'S') {
        auto tt = (col[y].lower_bound(make_pair(x, INF)));
        x = (*tt).first;
    } else if(dir == 'N') {
        auto tt = (col[y].lower_bound(make_pair(x, INF)));
        -- tt;
        x = (*tt).second;        
    } else if(dir == 'E') {
        auto tt = (row[x].lower_bound(make_pair(y, INF)));
        y = (*tt).first;
    } else {
        auto tt = (row[x].lower_bound(make_pair(y, INF)));
        -- tt;
        y = (*tt).second;   
    }

    // printf("%d %d\n", x, y);


    {
        auto tt = (row[x].upper_bound(make_pair(y, INF))); --tt;
        // for(auto tmp : row[x]) {
        //     printf("yyy: %d %d\n", tmp.first,  tmp.second);
        // }
        // printf("row: %d %d %d\n", x, (*tt).first, (*tt).second);
        row[x].erase(tt);
        int t1 = (*tt).first; int t2 = (*tt).second;
        insert(row[x], t1, y - 1);
        insert(row[x], y + 1, t2);
    }

    {
        auto tt = (col[y].upper_bound(make_pair(x, INF))); --tt;
        // printf("col:%d %d %d\n", y, (*tt).first, (*tt).second);
        col[y].erase(tt);
        int t1 = (*tt).first; int t2 = (*tt).second;
        insert(col[y], t1, x - 1);
        insert(col[y], x + 1, t2);
    }

}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n, r, c, sr, sc;
        scanf("%d %d %d %d %d", &n, &r, &c, &sr, &sc);
        scanf("%s", seq);
        for(int i = 1; i <= r; ++i) {
            row[i].clear();
            if(i == sr) {
                insert(row[i], 1, sc - 1);
                insert(row[i], sc + 1, c);
            }
            else row[i].insert(make_pair(1, c));
        }
        for(int i = 1; i <= c; ++i) {
            col[i].clear();
            if(i == sc) {
                insert(col[i], 1, sr - 1);
                insert(col[i], sr + 1, r);
            }
            else col[i].insert(make_pair(1, r));
        }

        int len = strlen(seq);
        int tx = sr; int ty = sc;
        for(int i = 0; i < len; ++i) {
            solve(tx, ty, seq[i]);
            // printf("hhh %d %d\n", tx, ty);
        }    
        printf("Case #%d: ", cas);    
        printf("%d %d\n", tx, ty);
    }
    return 0;
}
/*
3
5 3 6 2 3
EEWNS
4 3 3 1 1
SESE
11 5 8 3 4
NEESSWWNESE
*/