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
int A[MAXN];
pair<int, vector<int > > best_answer;
int m, n;

void solve() {
    vector<int> order;
    
    for(int i = 0; i < n; ++i) {
        order.push_back(i);
    }   

    random_shuffle(order.begin(), order.end());
    vector<int> solution;
    

    int count_m = 0;
    for(auto i : order) {
        if(A[i] + count_m <= m) {
            count_m += A[i];
            solution.push_back(i);
        }
    }
    
    auto now_answer = make_pair(count_m, solution);

    if(best_answer < now_answer) {
        best_answer = now_answer;
    }
}
int main() {
    // freopen("a_example.in", "r", stdin);
    // freopen("a_example.out", "w", stdout);

    // freopen("b_small.in", "r", stdin);
    // freopen("b_small.out", "w", stdout);

    // freopen("c_medium.in", "r", stdin);
    // freopen("c_medium.out", "w", stdout);

    // freopen("d_quite_big.in", "r", stdin);
    // freopen("d_quite_big.out", "w", stdout);

    // freopen("d_quite_big.in", "r", stdin);
    // freopen("d_quite_big.out", "w", stdout);
    // cerr << (unsigned)time(NULL) << endl;
    // srand((unsigned)time(NULL));
    while(~scanf("%d %d", &m, &n)) {
        best_answer = make_pair(0, vector<int>());

        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);

        for(int i = 0; i < 50000; ++i) {
            solve();
        }

        cerr << best_answer.first << " / " << m << endl;
        
        vector<int> &vc = best_answer.second;
        printf("%d\n", (int)vc.size());
        sort(vc.begin(), vc.end());
        for(auto it : vc) {
            printf("%d ", it);
        }
        // sort(A, A + n);
        
        // set<int> st;
        // map<int, int> mp;

        // for(int i = 0; i < n; ++i) {
        //     vector<int> tmp;

        //     for(auto item : st) {
        //         if(!st.count(item + A[i]) && item + A[i] <= m) {
        //             tmp.push_back(item + A[i]);
        //         } 
        //     }    

        //     if(!st.count(A[i])) {
        //         st.insert(A[i]);
        //         mp[A[i]] = i;
        //     }

        //     for(auto item : tmp) {
        //         st.insert(item);
        //         mp[item] = i;
        //     }
        // }

        // int target = *(--st.end());
        // vector<int> ans;
        // while(1) {
        //     int tt = mp[target];
        //     ans.push_back(tt);
        //     target -= A[tt];
        //     if(target == 0) break;
        // }

        // printf("%d\n", (int)ans.size());
        // sort(ans.begin(), ans.end());
        // for(int i = 0, len = ans.size(); i < len; ++i) {
        //     printf("%d ", ans[i]);
        // } 
        // printf("\n");  

    }   
    return 0;
}
