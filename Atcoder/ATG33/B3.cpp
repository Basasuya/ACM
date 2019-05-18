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


const int N = 2e5 + 5;

char S[N], T[N];


bool solve(char* S, char* T, int fr, int to, int pos, int edge, char add, char sub) {
    int l = 1; int r = edge;

    for(int i = to; i >= fr; --i) {
        // printf("%d %c %c %c: ", i, T[i], S[i], add);
        if(T[i] == add) { 
            l --;
        } else if(T[i] == sub) {
            r ++;
        }

        l = max(l, 1);
        r = min(r, edge);

        if(S[i] == add) {
            r --;
        } else if(S[i] == sub) {
            l ++;
        }
        
        if(l > r) return false;
    }
    if(l <= pos && pos <= r) return true;
    else return false;
}
int main() {
    int H, W, N;
    int sr, sc;
    while(~scanf("%d %d %d", &H, &W, &N)) {
        scanf("%d %d", &sr, &sc);
        scanf("%s %s", S, T);

        bool flag = solve(S, T, 0, N - 1, sc, W, 'R', 'L');
        
        if(flag) flag = solve(S, T, 0, N - 1, sr, H, 'D', 'U'); 
        
        // cout << flag << endl;
        printf("%s\n", flag ? "YES" : "NO");

    }
    return 0;
}

/*
2 3 3
2 2
RRL
LUD
4 3 5
2 2
UDRRR
LLDUD
5 6 11
2 1
RLDRRUDDLRL
URRDRLLDLRD



*/