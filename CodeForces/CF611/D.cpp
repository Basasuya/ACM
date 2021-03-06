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

const int MAXN = 2e5 + 5;
int X[MAXN];

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &X[i]);
        }

        map<int, int> has;
        queue<int> Q;

        for(int i = 0; i < n; ++i) {
            has[X[i]] ++;
            Q.push(X[i]);
        }

        ll result = 0;
        int cnt = m;
        vector<int> ans;
        int dis = 0;
        while(!Q.empty()) {
            if(cnt == 0) break;
            dis ++;
            int siz = Q.size();
            for(int i = 0; i < siz && cnt; ++i) {
                int x = Q.front(); Q.pop();
                if(!has.count(x - 1) && cnt) {
                    has[x - 1] ++;
                    ans.push_back(x - 1);
                    cnt --;
                    result += dis;
                    Q.push(x - 1);
                }
                if(!has.count(x + 1) && cnt) {
                    has[x + 1] ++;
                    cnt --;
                    ans.push_back(x + 1);
                    result += dis;
                    Q.push(x + 1); 
                }

            }
        }

        printf("%lld\n", result);
        for(int i = 0; i < m; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        } 
        printf("\n");
    }
    return 0;
}