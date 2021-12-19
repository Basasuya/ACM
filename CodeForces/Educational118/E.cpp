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


const int MAXN = 1e6 + 5;
char seq[MAXN];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<string> vc;
        for(int i = 0; i < n; ++i) {
            scanf("%s", seq);
            vc.push_back(seq);
        }
        

        int L_i, L_j;     
        bool find_L = false;
        for(int i = 0; i < n && !find_L; i ++) {
            for(int j = 0; j < m && !find_L; ++j) {
                if (vc[i][j] == 'L') {
                    L_i = i; L_j = j;
                    find_L = true;
                }
            }
        } 


        queue<pair<int, int> > Q;
        Q.push({L_i, L_j});
        while(!Q.empty()) {
            auto tmp = Q.front(); Q.pop();

            debug(tmp);

            for(int i = 0; i < 4; ++i) {
                int tx = direction[i][0] + tmp.first; 
                int ty = direction[i][1] + tmp.second;
                

                if (tx < 0 || tx >= n || ty < 0 || ty >= m || vc[tx][ty] != '.' ) {
                    continue;
                }

                int success_cnt = 0; int fail_cnt = 0;
                for(int j = 0 ; j < 4; ++j) {
                    int ttx = tx + direction[j][0]; 
                    int tty = ty + direction[j][1];

                    if (ttx < 0 || ttx >= n || tty < 0 || tty >= m || vc[ttx][tty] == '#') {
                        continue;
                    } 

                    if(vc[ttx][tty] == 'L' || vc[ttx][tty] == '+') {
                        success_cnt ++;
                    } else {
                        fail_cnt ++;
                    }
                }

                debug(tx, ty, success_cnt, fail_cnt);

                if (success_cnt && fail_cnt <= 1) {
                    vc[tx][ty] = '+';
                    Q.push({tx, ty});
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            printf("%s\n", vc[i].c_str());
        }
        
    }
    return 0;
}