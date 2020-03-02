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

const int MAXN = 2e5 + 5;
int A[MAXN];
int T[MAXN];


int main() {
    int n;
    while(~scanf("%d", &n)) {
        vector<int> id;
        for(int i = 0; i < n; ++i) id.push_back(i);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &T[i]);
        }

        auto cmp = [&](int x, int y) {
            if(A[x] != A[y]) return A[x] < A[y];
            else return T[x] < T[y];
        };

        priority_queue<int, vector<int>, less<int> > Q;

        sort(id.begin(), id.end(), cmp);

        int pre = -1;
        ll ans = 0; ll tmp = 0;
        for(int i = 0; i < n; ++i) {
            debug(A[id[i]], T[id[i]], id[i]);


            if(i == 0) {
                pre = A[id[i]];
                Q.push(T[id[i]]);
                tmp += T[id[i]];
                continue;
            }

            if(pre == A[id[i]]) {
                Q.push(T[id[i]]);
                tmp += T[id[i]];
            } else{
                while(!Q.empty() && pre < A[id[i]]) {
                    int x = Q.top(); Q.pop();
                    pre ++;
                    tmp -= x;
                    debug("add", tmp);
                    ans += tmp;
                }

                Q.push(T[id[i]]);
                tmp += T[id[i]];
                pre = A[id[i]];
            }

            if(i == n-1) {
                while(!Q.empty()) {
                    int x = Q.top(); Q.pop();
                    pre ++;
                    tmp -= x;
                    ans += tmp;
                }
            }
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}