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

const int MAXN = 1e5 + 5;
int A[MAXN];

int root = 0;
struct Trie{
    int nx[2];
    int cnt;
    int ty;
    int pre;
    Trie() {
        memset(nx, -1, sizeof(nx));
        cnt = 0;
        pre = -1;
        ty = -1;
    }
};

vector<Trie> tree;

void Insert(int x) {
    int rt = root;
    for(int i = 29; i >= 0; --i) {
        tree[rt].cnt ++;
        int digit = (x >> i) & 1;
        if( tree[rt].nx[digit] == -1 ) {
            tree.push_back(Trie());
            tree[rt].nx[digit] = tree.size() - 1;
            tree[tree.size() - 1].pre = rt;
            tree[tree.size() - 1].ty = digit;
        }

        rt = tree[rt].nx[digit];
    }

    tree[rt].cnt ++;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        
        root = 0;
        tree.push_back(Trie());

        for(int i = 0; i < n; ++i) {
            Insert(A[i]);
        }

        queue<int> Q;
        Q.push(root);

        vector<int> tag;
        int deep = 0;
        for(int turn = 0; turn <= 29; ++turn) {
            int siz = Q.size();
            vector<int> choose1; 
            vector<int> choose2;
            for(int l = 0; l < siz; ++l) {
                int x = Q.front(); Q.pop();
                int cnt = 0;
                for(int i = 0; i < 2; ++i) {
                    if(tree[x].nx[i] != -1) {
                        cnt ++;
                    }
                }
                if(cnt == 1) choose1.push_back(x);
                else if(cnt == 2) choose2.push_back(x);
            }

            // debug(choose1, choose2);

            if(choose1.size() > 0) {
                for(auto item : choose1) {
                    for(int i = 0; i < 2; ++i) {
                        if(tree[item].nx[i] != -1) {
                            Q.push(tree[item].nx[i]);
                        }
                    }
                }
                tag.push_back(0);
            } else {
                for(auto item : choose2) {
                    for(int i = 0; i < 2; ++i) {
                        if(tree[item].nx[i] != -1) {
                            Q.push(tree[item].nx[i]);
                        }
                    }
                }
                tag.push_back(1);
            }
        }

        int x = Q.front(); Q.pop();
        int ans = 0;
        int cnt = 0;
        while(tree[x].pre != -1) {
            // debug(tree[x].ty, tag[tag.size() - 1 - cnt]);
            int tmp = tag[tag.size() - 1 - cnt] ^ 1;
            ans += (tree[x].ty == tmp) ? (1<<cnt) : 0;
            x = tree[x].pre;
            cnt ++;
        }
        
        int result = -1;
        for(int i = 0; i < n; ++i) {
            result = max(result, A[i] ^ ans);
        }

        printf("%d\n", result);
    }


    return 0;
}