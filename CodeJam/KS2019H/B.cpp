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
#define mp make_pair
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


const int INF = 0x3f3f3f3f;
char seq[105][105];
int tmp[105][105];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", seq[i]);
        }

        int ans = INF; int _ans = INF;
        // solve1 
        {
            
            int cnt = 0; bool suc = true;
            map<int, int> mp;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    tmp[i][j] = seq[i][j] == '#';
                }
            }
            vector<int> diagnol;
            for(int i = 0; i < n; ++i) {
                if(tmp[i][i] == 0) {
                    diagnol.push_back(i);
                }
            }
            for(int i = 0, len = diagnol.size(); i < len; ++i) {
                int x = diagnol[i] * 2; int y = 0; int doLen = diagnol[i] * 2 + 1;
                if(x >= n) {
                    x = n-1; y = diagnol[i] * 2 - x; doLen = (n - diagnol[i] - 1) * 2 + 1;
                }
                for(int j = 0; j < doLen; ++j) {
                    tmp[x][y] = !tmp[x][y];
                    x ++; y --;
                }
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(tmp[i][j] == 0) {
                        mp[i - j] ++;
                    }
                }
            }

            
            for(auto it : mp) {
                cnt ++;
                int doLen = n - abs(it.first);
                if(doLen != it.second) {
                    suc = false; break;
                }
            }

            if(suc == true) ans = min(ans, cnt);
        }


        {    
            int cnt = 1; bool suc = true;
            map<int, int> mp;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    tmp[i][j] = seq[i][j] == '#';
                }
            }
            vector<int> diagnol;
            for(int i = 0; i < n; ++i) {
                if(tmp[i][i] == 1) {
                    diagnol.push_back(i);
                }
                tmp[i][i] = !tmp[i][i];
            }
            for(int i = 0, len = diagnol.size(); i < len; ++i) {
                int x = diagnol[i] * 2; int y = 0; int doLen = diagnol[i] * 2 + 1;
                if(x >= n) {
                    x = n-1; y = diagnol[i] * 2 - x; doLen = (n - diagnol[i] - 1) * 2 + 1;
                }
                for(int j = 0; j < doLen; ++j) {
                    tmp[x][y] = !tmp[x][y];
                    x ++; y --;
                }
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(tmp[i][j] == 0) {
                        mp[i - j] ++;
                    }
                }
            }

            
            for(auto it : mp) {
                cnt ++;
                int doLen = n - abs(it.first);
                if(doLen != it.second) {
                    suc = false; break;
                }
            }

            if(suc == true) ans = min(ans, cnt);
        }


        { 
            int cnt = 0; bool suc = true;
            map<int, int> mp;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    tmp[i][j] = seq[i][j] == '#';
                }
            }
            vector<int> diagnol;
            for(int i = 0; i < n; ++i) {
                if(tmp[i][i] == 0) {
                    diagnol.push_back(i);
                }
            }
            for(int i = 0, len = diagnol.size(); i < len; ++i) {
                int x = diagnol[i] * 2; int y = 0; int doLen = diagnol[i] * 2 + 1;
                if(x >= n) {
                    x = n-1; y = diagnol[i] * 2 - x; doLen = (n - diagnol[i] - 1) * 2 + 1;
                }
                for(int j = 0; j < doLen; ++j) {
                    tmp[x][y] = !tmp[x][y];
                    x ++; y --;
                }
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(tmp[i][j] == 0) {
                        mp[i - j] ++;
                    }
                }
            }

            
            for(auto it : mp) {
                cnt ++;
                int doLen = n - abs(it.first);
                if(doLen != it.second) {
                    suc = false; break;
                }
            }

            if(suc == true) ans = min(ans, cnt);
        }





        printf("Case #%d:", cas);
        printf("%d\n", ans);
    }
    return 0;
}

/*


3
3
..#
#.#
#..
5
.####
#.###
##.##
###.#
#####
2
##
##
*/