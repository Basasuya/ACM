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
using namespace std;
// #define MP make_pair
// #define ll long long
// #define ld long double
// #define null NULL
// #define all(a) a.begin(), a.end()
// #define forn(i, n) for (int i = 0; i < n; ++i)
// #define sz(a) (int)a.size()
// #define lson l , m , rt << 1
// #define rson m + 1 , r , rt << 1 | 1
// #define bitCount(a)  __builtin_popcount(a)
// template<class T> int gmax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
// template<class T> int gmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }

// const int INF = 0x3f3f3f3f;
// string to_string(string s) { return '"' + s + '"'; }
// string to_string(const char* s) { return to_string((string) s); }
// string to_string(bool b) { return (b ? "true" : "false"); }
// template <typename A, typename B>
// string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
// template <typename A>
// string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
// void debug_out() { cerr << endl; }
// template <typename Head, typename... Tail>
// void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
// #ifdef LOCAL
// #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define debug(...) 42
// #endif

const int MAXN = 2e6 + 5;

struct Node{
    int nex[26];
    int cnt;
    int pre;
    Node() {
        // for(int i = 0; i < 26; ++i) nex[i] = -1;
        // cnt = 0;
        // pre = 0;
    }
}trie[MAXN];
char seq[MAXN];
// vector<Node> trie;
int root;
int tot;
int ans;
int newNode() {
    memset(trie[tot].nex, -1, sizeof(trie[tot].nex));
    trie[tot].pre = 0;
    trie[tot].cnt = 0;
    return tot ++;
}

void insert(string seq) {
    int rt = root;
    for(auto it : seq) {
        int x = it - 'A';
        if(trie[rt].nex[x] == -1) {
            trie[rt].nex[x] = newNode();
        }
        trie[trie[rt].nex[x]].pre = rt;
        rt = trie[rt].nex[x];
        trie[rt].cnt ++;
    }
    // for(int i = 0; i < 26; ++i) debug(trie[root].nex[i]);
}

void get(int K, int floor2, int rt) {
    // printf("%d %d %d\n", K, floor2, rt);

    for(int i = 0; i < 26; ++i) {
        if(trie[rt].nex[i] != -1) {
            get(K, floor2 + 1, trie[rt].nex[i]);
        }
    }

    if(trie[rt].cnt >= K) {
        int groups = trie[rt].cnt / K;
        int sub = groups * K;
        
        while(rt > 0) {
            trie[rt].cnt -= sub;
            rt = trie[rt].pre;
            // printf("%d\n", rt);
        }

        ans += groups * floor2;
    }
} 


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        ans= 0;
        tot = 0;
        int n, K;
        scanf("%d %d", &n, &K);
        // vector<string> vc;
        // trie.clear();
        root = newNode();
        for(int i = 0; i < n; ++i) {
            // string tmp;
            scanf("%s", seq);
            insert(string(seq));
        }

        get(K, 0, root);
        
        // cout << "Case #" << cas << ": " << ans << endl;
        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
    return 0;
}