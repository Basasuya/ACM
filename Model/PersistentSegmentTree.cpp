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
// #define lson l , m , rt << 1
// #define rson m + 1 , r , rt << 1 | 1
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

// const int MAXN = 3e5 + 5;
// const int M = MAXN * 100;
int n, m;
vector<int> T, lson, rson, c;
int tot = 0;

int newNode() {
    lson.push_back(0); rson.push_back(0); c.push_back(0); 
    return tot ++;
}
int build(int l, int r) {
    int root = newNode();
    c[root] = 0;
    if(l != r) {
        int mid = (l + r) >> 1;
        lson[root] = build(l, mid);
        rson[root] = build(mid + 1, r);
    }
    return root;
}

int update(int root, int pos, int val) {
    int newroot = newNode(), tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(pos <= mid) {
            lson[newroot] = newNode(); rson[newroot] = rson[root];
            newroot = lson[newroot]; root = lson[root];
            r = mid;
        } else {
            rson[newroot] = newNode(); lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int query(int root, int pos) { // don't let pos < the left bound
    int ret = 0;
    int l = 1, r = n;
    while(pos < r) {
        int mid = (l + r) >> 1;
        if(pos <= mid) {
            r = mid;
            root = lson[root];
        } else {
            ret += c[lson[root]];
            root = rson[root];
            l = mid + 1;
        }
    }
    return ret + c[root];
}


class BIT {
private:
    vector<int> tree;
    int treesize;
public:
    BIT(int x) {
        tree.resize(x + 5, 0);
        treesize = x + 5;
    }

    int Sum(int x) {
        if(x <= 0) return 0;
        if(x > treesize) x = treesize;
        int ans = 0;
        while(x > 0) {
            ans += tree[x];
            x -= x & -x;
        }
        return ans;
    }
    void Add(int x, int d) {
        // debug(x);
        while(x <= treesize) {
            tree[x] += d;
            x += x & -x;
        }
    }
};


int main() {
    
    while(~scanf("%d %d", &n, &m)) {
        vector<int> vc;
        vector<int> mp(max(n,m) + 5, 0);
        vector<int> maxx(n + 5, 0);
        vector<int> minn(n + 5, 0);
        vector<vector<int> > E(n + 5, vector<int>());
        for(int i = 1; i <= n; ++i) {
            maxx[i] = minn[i] = i;
        }   

        for(int i = 0; i < m; ++i) {
            int t; scanf("%d", &t);
            vc.push_back(t);
            E[t].push_back(i + 1);
            minn[t] = 1;
        }

        BIT bit = BIT(n + 5);
        // set<int> st;
        for(int i = 0; i < m; ++i) {
            if(mp[vc[i]] == 0) {
                bit.Add(vc[i], 1);
                maxx[vc[i]] = max(maxx[vc[i]], vc[i] + bit.Sum(n) - bit.Sum(vc[i]));
                debug(i, vc[i], maxx[vc[i]]);
            }
            mp[vc[i]] = 1;
        }
        
        for(int i = 1; i <= n; ++i) {
            if(mp[i] == 0) {
                maxx[i] = max(maxx[i], i + bit.Sum(n) - bit.Sum(i));
                // debug(i, maxx[i]);
            }
        }


        tot = 0;
        T.clear();
        for(int i = 0; i < m + 5; ++i) T.push_back(i);
        T[m + 1] = build(1, m);
        for(int i = 1; i <= n; ++i) mp[i] = 0;
        for(int i = m; i >= 1; -- i) {
            int target = vc[i-1];
            if(mp[target] == 0) {
                T[i] = update(T[i + 1], i,  1);
            } else {
                int tmp = update(T[i + 1], mp[target], -1);
                T[i] = update(tmp, i, 1);
            }
            mp[target] = i;
        }

        debug(query(T[m + 1], m + 1), query(T[m + 1], m));

        for(int i = 1; i <= n; ++i) {
            int pre = m + 1;
            for(int j = E[i].size() - 1; j >= 0; --j) {
                int tmp = query(T[E[i][j]], pre - 1);
                maxx[i] = max(maxx[i], tmp);
                // debug(i, E[i][j] + 1, pre - 1, tmp);
                pre = E[i][j];
            }
        }

        

        for(int i = 1; i <= n; ++i) {
            printf("%d %d\n", minn[i], maxx[i]);
        }
    }
    return 0;
}