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

const int MAXN = 1e6 + 10;
char seq[MAXN];
int line[MAXN];

int maxx[MAXN << 2];
int minn[MAXN << 2];
int col[MAXN << 2];


void PushUp(int rt) {
    maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
    minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
}

void PushDown(int rt) {
    if (col[rt]) {
        col[rt<<1] += col[rt];
        col[rt<<1|1] += col[rt];

        maxx[rt << 1] = maxx[rt << 1] + col[rt];
        maxx[rt << 1 | 1] = maxx[rt << 1 | 1] + col[rt];
        minn[rt << 1] = minn[rt << 1] + col[rt];
        minn[rt << 1 | 1] = minn[rt << 1 | 1] + col[rt];

        col[rt] = 0;
    }
}

void Build(int l,int r,int rt) {
    maxx[rt] = 0;
    minn[rt] = 0;
    col[rt] = 0;
    if (l == r) return;

    int m = (l + r) >> 1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}


void Update(int L,int R,int c,int l,int r,int rt) {
    if (L <= l && r <= R) {
        col[rt] += c;
        maxx[rt] = maxx[rt] + c;
        minn[rt] = minn[rt] + c;
        return ;
    }

    PushDown(rt);

    int m = (l + r) >> 1;
    if (L <= m) Update(L , R , c , lson);
    if (R > m) Update(L , R , c , rson);
    PushUp(rt);
}


void Debug(int l,int r,int rt) {
    if (l == r) {
        debug(l, maxx[rt], minn[rt]);
        return;
    }

    PushDown(rt);
    int m = (l + r) >> 1;
    Debug(lson);
    Debug(rson);
    PushUp(rt);
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        scanf("%s", seq);
        int cursor = 1;
        for(int i = 0; i < n + 5; ++i) line[i] = 0;

        Build(1, n, 1);

        vector<int> result;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(seq[i] == 'L') cursor = max(1, cursor - 1);
            else if(seq[i] == 'R') cursor ++;
            else {
                int tmp = 0;
                if(seq[i] == '(') { tmp = 1; cnt ++; } if(seq[i] == ')') { tmp = -1; cnt --; }
                
                if(line[cursor] != 0) cnt -= line[cursor];

                int sub = tmp - line[cursor];

                // debug(sub, cursor);

                Update(cursor, n, sub, 1, n, 1);


                line[cursor] = tmp;
            }

            // Debug(1, n, 1);

            // debug(cnt);
            if(minn[1] < 0 || cnt != 0) result.push_back(-1);
            else result.push_back(maxx[1]);
        }

        for(int i = 0, len = result.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}