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

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;


int tree2[MAXN], tree3[MAXN];
int treesize;
int Sum(int x, int ty) {
    if(x > treesize) x = treesize;
    int ans = 0;
    while(x > 0) {
        ans += ty ? tree3[x] : tree2[x];
        x -= x & -x;
    }
    return ans;
}
void Add(int x, int d, int ty) {
    while(x <= treesize) {
        if(ty) tree3[x] += d;
        else tree2[x] += d;
        x += x & -x;
    }
}

int main() {
    int k1, k2, k3;
    while(~scanf("%d %d %d", &k1, &k2, &k3)) {
        int n = k1 + k2 + k3;

        treesize = n;
        for(int i = 0; i <= n; ++i) tree2[i] = 0, tree3[i] = 0;

        set<int> s1, s2, s3;

        for(int i = 0; i < k1; ++i) {
            int x; scanf("%d", &x);
            s1.insert(x);
        }

        for(int i = 0; i < k2; ++i) {
            int x; scanf("%d", &x);
            s2.insert(x); Add(x,1,0);
        }

        for(int i = 0; i < k3; ++i) {
            int x; scanf("%d", &x);
            s3.insert(x); Add(x,1,1);
        }

        int ans = INF; int cnt = 0;
        for(int i = 0; i <= n; ++i) {
            if(i && !s1.count(i)) {
                if(s2.count(i)) s2.erase(i), Add(i, -1, 0);
                else if(s3.count(i)) s3.erase(i), Add(i, -1, 1);
                cnt ++;
                s1.insert(i);
            }

            // debug(cnt);

            int tmp = cnt + s1.size() - i;

            if(s2.size() > 0 && s3.size() > 0) {
                int t1 = *s3.begin();
                int sum1 = s2.size() - Sum(t1, 0);

                int t2 = *(--s2.end());
                int sum2 = Sum(t2, 1);

                tmp += min(sum1, sum2);
            }


            ans = min(ans, tmp);
        }


        printf("%d\n", ans);
    }
    return 0;
}