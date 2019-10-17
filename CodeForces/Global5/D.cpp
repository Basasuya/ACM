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
int n;
struct Node{
    int fr, to;
    int maxx;
};

int ans[MAXN];
void solve() {
    deque<Node> st;
    memset(ans, -1, sizeof(ans));
    int cnt = 0;
    int logCnt = 0;
    bool hasLoop = false;
    for(int i = 0, tim = 0; ; i = (i + 1) % n, tim ++) {
        
        if(tim > n * 3) break;
        while(!st.empty()) {
            Node tt = st.front();
            if( (tt.maxx - 1) / 2 >= A[i] ) {
                for(int j = tt.fr; j <= tt.to; ++j) {
                    if(ans[j] != -1) {
                        continue;
                    }
                    ans[j] = tim - j;
                    cnt ++;
                    if(cnt == n) return;
                }
                st.pop_front(); 
            } else break;
        }
        
        if(!hasLoop) {
            Node tmp;
            tmp.fr = i; tmp.to = i;
            tmp.maxx = A[i];
            while(!st.empty()) {
                Node tt = st.back();
                if(tt.maxx < tmp.maxx){
                    tmp.fr = tt.fr;
                    st.pop_back(); 
                } else break;
            }
            st.push_back(tmp);
        } else {
            Node tmp;
            tmp.fr = tmp.to = -1;
            tmp.maxx = A[i];
            while(!st.empty()) {
                Node tt = st.back();
                if(tt.maxx < A[i]){
                    if(tmp.fr == -1) {
                        tmp.fr = tt.fr; tmp.to = tt.to; 
                    } else {
                        tmp.fr = tt.fr;
                    }
                    st.pop_back(); 
                } else break;
            }
            if(tmp.fr != -1) st.push_back(tmp);
        }
        if(i == n - 1) hasLoop = true;
        
    }
}

int main() {
    
    while(~scanf("%d", &n)) {
        
        memset(ans, -1, sizeof(ans));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        solve();

        for(int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        
    }
    return 0;
}