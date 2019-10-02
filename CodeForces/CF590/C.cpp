#include <iostream>
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
char seq[2][MAXN];

int main() {
    int q;
    scanf("%d", &q);
    while(q --) {
        int n;
        scanf("%d", &n);
        scanf("%s %s", seq[0], seq[1]);
        int dir1 = 1; int dir2 = 0;
        bool suc = true;
        for(int i = 0; i < n; ++i) {
            // debug(dir1, dir2);
            if(dir1 == 0 && dir2 == 0) {
                suc = false;
                break;
            }
            int tmpDir1 = 0; int tmpDir2 = 0;
            int tag1 = seq[0][i] < '3'; int tag2 = seq[1][i] < '3'; 
            if(dir1) {
                if(tag1 == 1) tmpDir1 = 1;
                if(tag1 == 0 && tag2 == 0) tmpDir2 = 1;
            }

            if(dir2) {
                if(tag2 == 1) tmpDir2 = 1;
                if(tag1 == 0 && tag2 == 0) tmpDir1 = 1;
            }


            dir1 = tmpDir1; dir2 = tmpDir2;
        }

        if(dir2 == false) suc = false;

        printf("%s\n", suc ? "YES" : "NO");
    }
    return 0;
}