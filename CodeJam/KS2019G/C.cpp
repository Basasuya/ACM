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
int tree[MAXN];
int treesize;
int sum(int x) {
    if(x > treesize) x = treesize;
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= x & -x;
    }
    return ans;
}
void add(int x, int d) {
    // debug(x);
    while(x <= treesize) {
        tree[x] += d;
        x += x & -x;
    }
}

int A[30], B[30];
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        memset(tree, 0, sizeof(tree));

        int n, h;
        scanf("%d %d", &n, &h);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &B[i]);
        }

        if(n <= 10) {
            int mul = 1;
            for(int i = 0; i < n; ++i) {
                mul *= 3;
            }
            ll ans = 0;
            for(int i = 0; i < mul; ++i) {
                int tmp = i; ll cntA = 0; ll cntB = 0;
                for(int j = 0; j < n; ++j) {
                    int ch = tmp % 3;
                    tmp /= 3;
                    if(ch == 0) cntA += A[j];
                    else if(ch == 1) cntB += B[j];
                    else cntA += A[j], cntB += B[j];
                }
                if(cntA >= h && cntB >= h) ans ++;
            }
            printf("Case #%d: ", cas);
            printf("%lld\n", ans);
            continue;
        }

        int halfN = n / 2;
        int mul = 1;
        for(int i = 0; i < halfN; ++i) {
            mul *= 3;
        }
        vector<pair<ll, ll> > fr;
        for(int i = 0; i < mul; ++i) {
            int tmp = i; ll cntA = 0; ll cntB = 0;
            for(int j = 0; j < halfN; ++j) {
                int ch = tmp % 3;
                tmp /= 3;
                if(ch == 0) cntA += A[j];
                else if(ch == 1) cntB += B[j];
                else cntA += A[j], cntB += B[j];
            }
            fr.push_back(make_pair(cntA, cntB));
        }
        // debug("hhhh");

        vector<ll> uni;
        vector<pair<ll, ll> > ed;
        if(n % 2) mul *= 3;
        for(int i = 0; i < mul; ++i) {
            int tmp = i; ll cntA = 0; ll cntB = 0;
            for(int j = halfN; j < n; ++j) {
                int ch = tmp % 3;
                tmp /= 3;
                if(ch == 0) cntA += A[j];
                else if(ch == 1) cntB += B[j];
                else cntA += A[j], cntB += B[j];
            }
            ed.push_back(make_pair(cntA, cntB));
            uni.push_back(cntB);
        }

        // debug("hhhh");

        sort(fr.begin(), fr.end());
        sort(ed.begin(), ed.end());
        
        sort(uni.begin(), uni.end());
        uni.erase(unique(uni.begin(), uni.end()), uni.end());
        treesize = uni.size();

        int j = ed.size() - 1;
        ll ans = 0;
        // debug(fr);
        // debug(ed);
        for(int i = 0, len = fr.size(); i < len; ++i) {
            ll edge = h - fr[i].first;
            // debug(i);
            while(j >= 0) {
                // debug(j);
                if(ed[j].first >= edge) {
                    int tt = lower_bound(uni.begin(), uni.end(), ed[j].second) - uni.begin();
                    add(tt + 1, 1);
                    debug("add", tt + 1);
                    j --;
                } else break;
            }
            // debug("yyy");
            ll ed2 = h - fr[i].second;
            int tt = lower_bound(uni.begin(), uni.end(), ed2) - uni.begin(); tt ++;
            // debug(tt);
            ans += sum(treesize) - sum(tt - 1);
        }

        printf("Case #%d: ", cas);
        printf("%lld\n", ans);
    }
    return 0;
}


/*

2
2 3
1 2
3 3
2 5
2 2
10 30

3 6
1 2 3
1 2 3
3 4
1 2 3
1 2 3
3 5
1 2 3
1 2 3
*/