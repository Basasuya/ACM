#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MP make_pair
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.last()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define bitCount(a)  __builtin_popcount(a)
template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;
const int INF = 0x3f3f3f3f;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// int mp[105][105];
vector<vector<int> > mp;

int R, C;

int update() {
    vector<vector<int> > row(R + 5, vector<int> ());
    vector<vector<int> > col(C + 5, vector<int> ());

    for(int i = 0; i < R; ++i) {
        row[i].push_back(-1);
        for(int j = 0; j < C; ++j) {
            if(mp[i][j] != -1) row[i].push_back(j);
        }
        row[i].push_back(C);
    }

    for(int i = 0; i < C; ++i) {
        col[i].push_back(0);
        for(int j = 0; j < R; ++j) {
            if(mp[j][i] != -1) col[i].push_back(j);
        }
        col[i].push_back(R);
    }
    
    int result = 0;
    vector<pair<int, int> > deleteEle;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(mp[i][j] != -1) {
                result += mp[i][j];
                int neiNum = 0; int neiVal = 0; int iter;
                iter = lower_bound(row[i].begin(), row[i].end(), j) - row[i].begin(); iter --; if(iter > 0) { neiNum ++; neiVal += mp[i][row[i][iter]]; }
                iter = upper_bound(row[i].begin(), row[i].end(), j) - row[i].begin(); if(iter < row[i].size() - 1) { neiNum ++; neiVal += mp[i][row[i][iter]]; }
                iter = lower_bound(col[j].begin(), col[j].end(), i) - col[j].begin(); iter --; if(iter > 0) { neiNum ++; neiVal += mp[col[j][iter]][j]; }
                iter = upper_bound(col[j].begin(), col[j].end(), i) - col[j].begin(); if(iter < col[j].size() - 1) { neiNum ++; neiVal += mp[col[j][iter]][j]; }
                
                if(neiVal > mp[i][j] * neiNum) deleteEle.push_back(MP(i, j));
            }
        }
    }

    // debug(deleteEle);
    
    for(auto it : deleteEle) {
        mp[it.first][it.second] = -1;
    }

    if(deleteEle.size() == 0) return -result;

    return result;
}


int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        mp.clear();
        scanf("%d %d", &R, &C);
        mp.resize(R, vector<int> (C, 0));
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }

        ll ans = 0;
        while(1) {
            int tmp = update();
            if(tmp < 0) { ans += -tmp; break; }
            ans += tmp;
        }

        printf("Case #%d: %lld\n", cas, ans);

    }
    return 0;
}

/*


4
1 1
15
3 3
1 1 1
1 2 1
1 1 1
1 3
3 1 2
1 3
1 2 3


*/