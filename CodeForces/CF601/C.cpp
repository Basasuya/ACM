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

const int MAXN = 1e5 + 5;
int A[MAXN][5];
vector<int> vc[MAXN];
int du[MAXN];
int cnt[MAXN];

void add(int x, int y) {
    vc[x].push_back(y); vc[y].push_back(x);
    du[x] ++; du[y] ++;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i <= n; ++i) {
            vc[i].clear();
            du[i] = 0;
            cnt[i] = 0;
        }
        map<pair<int, int>, int> mp;
        
        for(int i = 0; i < n - 2; ++i) {
            
            for(int j = 0; j < 3; ++j) { scanf("%d", &A[i][j]); cnt[A[i][j]] ++; }
            sort(A[i], A[i] + 3);
            if(mp.count(make_pair(A[i][0], A[i][1]))) { add(i, mp[make_pair(A[i][0], A[i][1])]); }
            if(mp.count(make_pair(A[i][1], A[i][2]))) { add(i, mp[make_pair(A[i][1], A[i][2])]); }
            if(mp.count(make_pair(A[i][0], A[i][2]))) { add(i, mp[make_pair(A[i][0], A[i][2])]); }

            mp[make_pair(A[i][0], A[i][1])] = mp[make_pair(A[i][1], A[i][2])] = mp[make_pair(A[i][0], A[i][2])] = i;
        }

        vector<int> solve;
        vector<int> ans; set<int> st;
        for(int i = 0; i < n - 2; ++i) {
            if(du[i] == 1) {
                int pre = -1; int x = i;
                for(int j = 0; j < n - 2; ++j) {
                    solve.push_back(x);
                    int to = -1;
                    for(int k = 0; k < vc[x].size(); ++k) {
                        if(vc[x][k] != pre) {
                            to = vc[x][k]; break;
                        }
                    }
                    pre = x;
                    x = to;
                }
                break;
            }
        }


        for(int i = 0, len = solve.size(); i < len; ++i) {
            if(i == 0) {
                set<int> has;
                for(int j = 0; j < 3; ++j) {
                    has.insert(A[solve[1]][j]);
                }
                
                for(int j = 0; j < 3; ++j) {
                    st.insert(A[solve[0]][j]);
                }

                for(int j = 0; j < 3; ++j) {
                    if(!has.count(A[solve[0]][j])) { ans.push_back(A[solve[0]][j]); break; }
                }

                has.clear();

                for(int j = 0; j < 3; ++j) {
                    has.insert(A[solve[2]][j]);
                }

                for(int j = 0; j < 3; ++j) {
                    if(!has.count(A[solve[0]][j]) && A[solve[0]][j] != ans[0]) { ans.push_back(A[solve[0]][j]); break; }
                }

                for(int j = 0; j < 3; ++j) {
                    if(has.count(A[solve[0]][j])) ans.push_back(A[solve[0]][j]);
                }
            } else {
                for(int j = 0; j < 3; ++j) {
                    if(!st.count(A[solve[i]][j])) { ans.push_back(A[solve[i]][j]); st.insert(A[solve[i]][j]); }
                }
            }
        }
        for(int i = 0, len = ans.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        } printf("\n");
        
    }
    return 0;
}