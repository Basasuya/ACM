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
#define all(a) a.begin(), a.end()
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

const int MAXN = 1e3 + 5;
// pair<int, int> vc[MAXN][MAXN];
int ans[MAXN][MAXN]; // {0, X}, {1, L}, {2, R}, {3, U}, {4, D}
bool suc;
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n;

void solve_Normal(pair<int, int> tag, vector<pair<int, int>>& nodes) {
    // debug(tag, nodes);

    if(suc == false) return;

    unordered_map<int, int> has;

    for(auto ele : nodes) {
        has[ele.first * n + ele.second] = 0;
    }
    
    if(has.find(tag.first * n + tag.second) == has.end()) {
        suc = false; return;
    }

    queue<pair<int, int> > Q;
    has[tag.first * n + tag.second] = 1;
    Q.push(tag);
    ans[tag.first][tag.second] = 0;
    
    int cnt = 0;
    while(!Q.empty()) {
        auto ele = Q.front(); Q.pop();
        cnt ++;
        for(int i = 0; i < 4; ++i) {
            int xx = ele.first + dirs[i][0];
            int yy = ele.second + dirs[i][1];
            int id = xx * n + yy;
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && has.find(id) != has.end() && has[id] == 0) {
                has[id] ++;
                ans[xx][yy] = i + 1;
                Q.push({xx, yy});
            }
        }
    } 

    if(cnt != nodes.size()) {
        suc = false; return;
    }
}


void solve_Circle(pair<int, int> tag, vector<pair<int, int>>& nodes) {
    // if(nodes.size() == 1000 * 1000) {
    //     suc = false; return;
    // }
    // debug("circle", tag, nodes);
    if(suc == false) return;

    if(nodes.size() == 1) {
        suc = false; return;
    }
    unordered_set<int> chooseList;
    unordered_map<int, int> has;

    for(auto ele : nodes) {
        has[ele.first * n + ele.second] = 0;
        chooseList.insert(ele.first * n + ele.second);
    }
    
    int allCnt = 0;
    
    queue<pair<int, int> > Q;
    while(!chooseList.empty()) {
        int firstNode = *chooseList.begin();

        
        has[firstNode] = 1;
        Q.push({firstNode / n, firstNode % n});
        
        int cnt = 1;
        while(!Q.empty()) {
            auto ele = Q.front(); Q.pop();
            chooseList.erase(ele.first * n + ele.second);

            for(int i = 0; i < 4; ++i) {
                int xx = ele.first + dirs[i][0];
                int yy = ele.second + dirs[i][1];
                int id = xx * n + yy;
                if(xx >= 0 && xx < n && yy >= 0 && yy < n && has.find(id) != has.end() && has[id] == 0) {
                    has[id] ++;
                    ans[xx][yy] = i + 1;
                    Q.push({xx, yy});
                    cnt ++;
                    if(cnt == 2) {
                        ans[ele.first][ele.second] = (i ^ 1) + 1;
                        // debug(ele, ans[ele.first][ele.second]);
                    }
                    
                }
            }
        } 
        if(cnt < 2) { suc = false; return; }
        allCnt += cnt;
    }

    if(allCnt != nodes.size()) {
        suc = false; return;
    }
}



int main() {
    
    while(~scanf("%d", &n)) {
        map<pair<int, int>, vector<pair<int, int> > > mp; 
        suc = true;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans[i][j] = -1;
                int t1, t2;
                scanf("%d %d", &t1, &t2);
                t1 --; t2 --;
                // vc[i][j] = make_pair(t1, t2);
                mp[{t1, t2}].push_back({i, j});
            }
        }

        for(auto it : mp) { 
            pair<int, int> tag = it.first;
            vector<pair<int, int>>& nodes = it.second;
            
            if(tag.first != -2) solve_Normal(tag, nodes);
            else solve_Circle(tag, nodes);
        }

        if(suc == true) {
            printf("VALID\n");
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(ans[i][j] == 0) printf("X");
                    else if(ans[i][j] == 1) printf("L");
                    else if(ans[i][j] == 2) printf("R");
                    else if(ans[i][j] == 3) printf("U");
                    else if(ans[i][j] == 4) printf("D");
                    else printf("S");
                }
                printf("\n");
            }
        } else {
            printf("INVALID\n");
        }
    }
    return 0;
}

/*


2
-1 -1 1 2
2 1 2 1



*/