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
// #define mp make_pair
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

struct node {
    int next[26];
    int fail;
    int isend;
    node() : isend(0), fail(0) { memset(next, 0, sizeof next); }
};

vector<node> v;
int tot;
char ask[1000005];


void insert(char* s) {
    int p = 0;
    int slen = strlen(s);
    for (int i = 0; i < slen; ++i) {
        if (!v[p].next[s[i] - 'a']) {
            v[p].next[s[i] - 'a'] = ++tot; 
            v.push_back(node());
        }
        
        p = v[p].next[s[i] - 'a'];
    }
    v[p].isend ++;
}


void build() {
    queue<int> q;
    int p;
    for (int i = 0; i < 26; ++i) {
        if (v[0].next[i]) q.push(v[0].next[i]);
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (v[p].next[i]) {
                v[v[p].next[i]].fail = v[v[p].fail].next[i];
                q.push(v[p].next[i]);
            } else {
                v[p].next[i] = v[v[p].fail].next[i];
            }
        }
    }
}

int query(char* seq) {
    int len = strlen(seq);

    int rt = 0;
    int res = 0;

    for(int i = 0; i < len; ++i) {
        rt = v[rt].next[seq[i] - 'a'];
        int tmp = rt;
        while(tmp) {
            res +=  v[tmp].isend;
            v[tmp].isend = 0;
            tmp = v[tmp].fail;
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        
        v.clear();
        v.reserve(n * 5);
        v.push_back(node());
        tot = 0;

        char seq[100];
        for(int i = 0; i < n; ++i) {
            scanf("%s", seq);
            insert(seq);
        }

        build();

        scanf("%s", ask);
        
        printf("%d\n", query(ask));

    }   
    return 0;
}



/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

