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

const int MAXN = 105;
int A[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int _ = 1; _ <= T; ++_) {
        int N, C;
        scanf("%d %d", &N, &C);
        for(int i = 1; i <= N; ++i) A[i] = -1;

        if(C < N - 1 || C > (N * (N + 1) / 2 - 1) ) {
            printf("Case #%d: IMPOSSIBLE\n", _);
            continue;
        }  

        C -= N - 1;
        vector<int> pipe;

        for(int i = 1; i < N; ++i) {
            int largest = N - i;
            if(C == 0) pipe.push_back(i);
            else if(C >= largest) {
                C -= largest;
                pipe.push_back(N);
            } else {
                pipe.push_back(i + C);
                C = 0;
            }
        }

        pipe.push_back(N);

        debug(pipe);
        
        for(int i = N - 1; i >= 0; --i) {
            A[i + 1] = i + 1; 
            for(int j = i + 1; j <= pipe[i]; ++j) {
                int fr = j; int to = pipe[i] + i + 1 - j;
                if(fr >= to) break;
                swap(A[fr], A[to]);
            }

            // for(int i = 1; i <= N; ++i) printf("%d ", A[i]); printf("\n");
        }

        printf("Case #%d: ", _);
        for(int i = 1; i <= N; ++i) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}