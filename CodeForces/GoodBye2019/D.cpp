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

const int MAXN = 505;
int color[MAXN];

pair<int, int> ask(set<int> &st) {
    printf("?");
    for(auto it : st) {
        printf(" %d", it);
    }
    printf("\n"); fflush(stdout);
    int target, val;
    scanf("%d %d", &target, &val);
    return MP(target, val);
} 

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        
        if(k == 1) {
            printf("! 1\n"); fflush(stdout);
            continue;
        }

        for(int i = 1; i <= n; ++i) {
            color[i] = -1;
        }

        set<int> st;
        for(int i = 1; i <= k; ++i) {
            st.insert(i);
        }

        pair<int, int> target = ask(st);
        int swapPos = 1;
        if(target.first == 1) swapPos ++;
        
        color[swapPos] = 1;

        for(int i = k + 1; i <= n; ++i) {
            st.erase(swapPos);
            st.insert(i);
            pair<int, int> result = ask(st);
            if(result == target) color[i] = color[swapPos];
            else color[i] = color[swapPos] ^ 1;
            st.erase(i);
            st.insert(swapPos);
        }

        int testPos = k + 1;

        for(int i = 1; i <= k; ++i) {
            if(swapPos == i || target.first == i) continue;

            st.insert(testPos);
            st.erase(i);
            pair<int, int> result = ask(st);
            if(result == target) color[i] = color[testPos];
            else color[i] = color[testPos] ^ 1;
            st.insert(i);
            st.erase(testPos);
        }

        st.erase(target.first);
        st.insert(testPos);
        pair<int, int> judge = ask(st);

        int judgeCnt = 0; 
        for(int i = 1; i <= k; ++i) {
            if(i == target.first) continue;
            if(color[i] == color[judge.first]) judgeCnt ++;
        }

        if(judge.second > target.second) printf("! %d\n", k - judgeCnt);
        else printf("! %d\n", judgeCnt + 1);
        fflush(stdout);
    }

    return 0;
}

/*

𝑛=4 , 𝑘=3, 𝑚=3, 𝑎=[2,0,1,9].

"E23"
"2X2"
"12S"



*/