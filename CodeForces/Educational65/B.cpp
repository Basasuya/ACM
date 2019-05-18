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
// #define ll long long
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

int a[10] = {4, 8, 15, 16, 23, 42};
int result[10];
int main() {
    map<int, pair<int, int> > mp;
    for(int i = 0; i < 6; ++i) {
        for(int j = i + 1; j < 6; ++j) {
            mp[a[i] * a[j]] = make_pair(i, j);
            // printf("%d %d %d\n", i, j, a[i] * a[j]);
        }
    }

    int tmp1, tmp2;
    int t[5];
    printf("? 1 2\n"); fflush(stdout); scanf("%d", &tmp1);
    printf("? 2 3\n"); fflush(stdout); scanf("%d", &tmp2);

    
    t[0] = mp[tmp1].first; t[1] = mp[tmp1].second;
    t[2] = mp[tmp2].first; t[3] = mp[tmp2].second;

    for(int i = 0; i < 2; ++i) {
        for(int j = 2; j < 4; ++j) {
            if(t[i] == t[j]) {
                result[1] = t[(i ^ 1)]; result[2] = t[i]; result[3] = t[j ^ 1]; 
            }
        }
    }

    printf("? 4 5\n"); fflush(stdout); scanf("%d", &tmp1);
    printf("? 5 6\n"); fflush(stdout); scanf("%d", &tmp2);

    
    t[0] = mp[tmp1].first; t[1] = mp[tmp1].second;
    t[2] = mp[tmp2].first; t[3] = mp[tmp2].second;

    for(int i = 0; i < 2; ++i) {
        for(int j = 2; j < 4; ++j) {
            if(t[i] == t[j]) {
                result[4] = t[(i ^ 1)]; result[5] = t[i]; result[6] = t[j ^ 1]; 
            }
        }
    }

    printf("!");
    for(int i = 1; i <= 6; ++i) {
        printf(" %d", a[result[i]]);
    } 
    printf("\n"); fflush(stdout);


}