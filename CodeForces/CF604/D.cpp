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

vector<int> ans;
bool solve(int all, int start, int a, int b, int c, int d) {
    ans.clear();
    for(int i = 0; i < all; ++i) ans.push_back(-1);

    for(int i = start, cnt = 1; i < all; i += 2, ++cnt) {
        if(cnt <= b) ans[i] = 1;
        else ans[i] = 3;
    }

    bool suc = true;

    for(int i = start ^ 1; i < all; i += 2) {
        int pre = (i == 0) ? -1 : ans[i - 1];
        int nex = (i == all-1) ? -1 : ans[i + 1]; 
        // if(pre == 1 && nex == 1) {
        if( (pre == 1 && nex == 1) || (pre == 1 && nex == -1) || (pre == -1 && nex == 1) ) {
            if(a) {
                a --; ans[i] = 0;
            } else if(c) {
                c --; ans[i] = 2;
            }
        } else {
            if(a) {
                suc = false; return false; break;
            } else if(c) {
                c --; ans[i] = 2;
            }
        }
    }

    assert(c == 0 && a == 0);


    return suc;
}
int main() {
    int a, b, c, d;
    while(~scanf("%d %d %d %d", &a, &b, &c, &d)) {
        int all = a + b + c + d;
        if( abs((a + c) - (b + d)) > 1) { printf("NO\n"); continue; }

        if(all == 1) {
            printf("YES\n");
            if(a) printf("0\n");
            if(b) printf("1\n");
            if(c) printf("2\n");
            if(d) printf("3\n");
            continue;
        }
        
        bool suc;
        if(all % 2 == 1) {       
            if(b + d == all / 2) suc = solve(all, 1 , a, b, c, d);
            else suc = solve(all, 0 , a, b, c, d);
        } else {
            suc = solve(all, 0 , a, b, c, d);
            if(suc == false) suc = solve(all, 1 , a, b, c, d);
        }


        if(suc == false) { printf("NO\n"); continue; }

        printf("YES\n");
        for(int i = 0; i < all; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        } printf("\n");
    }
    return 0;
}

/*


2 2 2 1

*/