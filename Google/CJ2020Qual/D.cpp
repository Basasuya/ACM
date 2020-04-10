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

int read() {
    char tmp[10]; scanf("%s", tmp);
    if(tmp[0] >= '0' && tmp[0] <= '1')
        return tmp[0] - '0';
    else 
        return -1;
}

int ask(int x) {
    printf("%d\n", x);
    fflush(stdout);
    return read();
}

int ask(string x) {
    printf("%s\n", x.c_str());
    fflush(stdout);
    return read();
}

void solveB_20() {
    vector<int> same(11, 0);

    for(int i = 1; i <= 10; ++i) {
        int x = i; int y = 20 - i + 1;
        int colorX = ask(x); int colorY = ask(y);
        if(colorX == colorY) {
            same[i] = 1;
        } else {
            same[i] = 0;
        }
    }

    for(int i = 0; i < 120; ++i) { ask(1); }
    string ans;
    for(int i = 1; i <= 10; ++i) {
        ans += ask(i) + '0';
    }
    
    for(int i = 11; i <= 20; ++i) {
        ans += (same[20 - i + 1] == 1) ? ans[20 - i] : ( (ans[20 - i] - '0') ^ 1 + '0' );
    }
    ask(ans);
}

void solveB_100() {}

int main() {
    int T, B;
    scanf("%d %d", &T, &B);
    while(T --) {
        if(B == 10) {
            for(int i = 0; i < 140; ++i) {
                ask(1);
            }
            string ans;
            for(int i = 1; i <= 10; ++i) {
                ans += ask(i) + '0';
            }
            ask(ans);
        } else if(B == 20) solveB_20();
        else solveB_100();
    }
}