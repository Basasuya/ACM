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
 
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
ll a[MAXN];
vector<int> has[65];
set<int> mp[MAXN];
int vis[MAXN];
void scanDigit(ll x, int id) {
    int cnt = 0;
    while(x) {
        if(x % 2) has[cnt].push_back(id);
        x /= 2;
        cnt ++;
    }
    // debug(cnt);
}
 
bool over3Cnt() {
    for(int i = 0; i < 65; ++i) {
        if(has[i].size() >= 3) {
            return true;
        }
    } 
    return false;
}
 
int bfs(int fr, int to, int tag, int oldAns) {
    // if(fr == 2 && to == 9)  debug(fr, to, tag);
    queue<pair<int, int> > Q;
    vis[fr] = tag;
    Q.push(make_pair(fr, 1));
    int ans = -1;
    while(!Q.empty()) {
        int tmp = Q.front().first;
        int dis = Q.front().second;
        // if(fr == 2 && to == 9) debug(tmp, dis);
        if(dis >= oldAns - 1) return INF;
        Q.pop();
        bool flag = true;
        for(auto y : mp[tmp]) {
            // if(fr == 2 && to == 9) debug(y);
            // int to = mp[tmp][i];
            if(vis[y] == tag) continue;
            if(y == to) { ans = dis; flag = false; break; }
            vis[y] = tag;
            Q.push(make_pair(y, dis + 1));
        }
        if(flag == false) break;
    }
    // if(fr == 2 && to == 9)  debug(fr, to, ans + 1);
    if(ans == -1) return INF;
    else return ans + 1;
} 
int main() {
    int n;
    while(~scanf("%d", &n)) {
        // init
        for(int i = 0; i < 65; ++i) has[i].clear();   
        for(int i = 0; i < MAXN; ++i) mp[i].clear(), vis[i] = -1;
 
 
 
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        } 
        for(int i = 0; i < n; ++i) {
            scanDigit(a[i], i);
        }
 
        if(over3Cnt()) {
            printf("3\n"); continue;
        }
 
        // debug("hhhh");
 
        for(int i = 0; i < 65; ++i) {
            if(has[i].size() == 2) {
                // debug(has[i][0], has[i][1]);
                mp[has[i][0]].insert(has[i][1]);
                mp[has[i][1]].insert(has[i][0]);
            }
        } 

        // for(int i = 0; i < 65; ++i) {
        //     if(has[i].size() == 2) {
        //         for(int j = 0; j < n; ++j) {
        //             if( mp[has[i][0]].find(j) != mp[has[i][0]].end() && mp[has[i][1]].find(j) != mp[has[i][1]].end() ) {
        //                 debug(has[i][0], has[i][1], j);
        //             }
        //         }
        //     }
        // } 
 
        int ans = INF;
 
        for(int i = 0; i < 65; ++i) {
            if(has[i].size() == 2) {
                mp[has[i][0]].erase(has[i][1]);
                mp[has[i][1]].erase(has[i][0]);
                ans = min(ans, bfs(has[i][0], has[i][1], i, ans));
                mp[has[i][0]].insert(has[i][1]);
                mp[has[i][1]].insert(has[i][0]);
            }
        } 
 
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}

/*

10
193953851215184128 21533387621925025 0 0 90143735963329536 2272071319648 0 0 3378250047292544 0
27
4295000064 274877906976 48389226512 33554434 68720525312 4194320 67108865 96 2056 413264846980 541065216 17179901952 8589935104 129 2147487744 68719607808 139586437120 17315009610 1280 2097408 25165824 1107296256 268435968 278528 34376515584 16388 10240

*/