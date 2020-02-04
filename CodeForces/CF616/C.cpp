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

const int MAXN = 3e5 + 5;
int A[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        if(k >= m) k = m - 1; 
        vector<int> vc;
        int len = n - m + 1;
        
        for(int i = 0; i < n; ++i) {
            int t1 = i; int t2 = i + len - 1;
            if(t2 < n) {
                vc.push_back(max(A[t1], A[t2]));
            }
        }

        int offset = vc.size() - k;

        int ans = -1;
        multiset<int> st;
        for(int i = 0; i < offset; ++i) {
            st.insert(vc[i]);
        }
        ans = max(*(st.begin()), ans);
        for(int i = offset; i < vc.size(); ++i) {
            st.erase(st.find(vc[i - offset]));
            st.insert(vc[i]);
            ans = max(*(st.begin()), ans);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}