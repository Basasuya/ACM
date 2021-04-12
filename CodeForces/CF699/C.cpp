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

const int MAXN = 1e5 + 5;
int A[MAXN], B[MAXN], C[MAXN];

// int has[MAXN];
// int last[MAXN];
// int B_set[MAXN];
int ans[MAXN];
int B_pos[MAXN];

int main() {
    int T;
    int test_case = 0;
    int all_case;
    scanf("%d", &T);
    all_case = T;
    while (T --) {
        test_case ++;

        int n, m;
        scanf("%d %d", &n, &m);
        
        vector<vector<int> > vc;

        for(int i = 0, max_len = max(n, m); i <= max_len; ++i) {
            // has[i] = 0;
            // last[i] = -1;
            // B_set[i] = 0;
            B_pos[i] = -1;
            ans[i] = -1;
            vc.push_back(vector<int> ());
        }

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
        }

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &B[i]);
            // B_set[B[i]] ++;
            B_pos[B[i]] = i;
        }

        for(int i = 1; i <= m; ++i) {
            scanf("%d", &C[i]);
            vc[C[i]].push_back(i);
            // has[C[i]] ++;
            // last[C[i]] = max(last[C[i]], i);
        }

        // if(test_case == 19 && all_case == 3333) {
        //     printf("%d %d\n", n, m);
        //     for(int i = 1; i <= n; ++i) printf("%d ", A[i]); printf("\n");
        //     for(int i = 1; i <= n; ++i) printf("%d ", B[i]); printf("\n");
        //     for(int i = 1; i <= m; ++i) printf("%d ", C[i]); printf("\n");
        //     // printf("hhh\n");
        // }
 
        bool suc = true;
        
        // int first_pos = -1;
        
        // if(B_pos[C[m]] == -1) {
        //     suc = false;
        // } else {
        //     last_modify = B_pos[C[m]];
        // }

        // ans[m] = last_modify;
        // vc[C[m]].pop_back();
        // A[last_modify] = C[m];

        // debug(last_modify, C[m], suc);


        for(int i = 1; i <= n && suc; ++i) {
            if(A[i] != B[i]) {
                if(vc[B[i]].empty()) {
                    suc = false;
                    break;
                }
                ans[vc[B[i]].back()] = i;
                vc[B[i]].pop_back();
                // debug(vc[B[i]].back(), i);
            }
        }

        int last_modify = 0;
        if(ans[m] == -1) {
            if(B_pos[C[m]] == -1) {
                suc = false;
            } else {
                last_modify = B_pos[C[m]];
            }
        } else {
            last_modify = ans[m];
        }

        for(int i = 1; i <= m; ++i) {
            if(ans[i] == -1) {
                ans[i] = last_modify;
            }
        }

        // if(all_case != 3333) {
        if(suc == false) printf("NO\n");
        else {
            printf("YES\n");
            for(int i = 1; i <= m; ++i) {
                printf("%d ", ans[i]);
                A[ans[i]] = C[i];
            }
            // printf("\n"); for(int i = 1; i <= n; ++i) printf("%d ", A[i]); printf("\n");
            printf("\n");
        }
        // }


    }
    return 0;
}
