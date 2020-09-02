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

const int MAXN = 1e6 + 5;
int L[MAXN], H[MAXN];
int P[MAXN];
const int MOD = 1e9 + 7;

int main() {
    freopen("perimetric_chapter_1_input.txt", "r", stdin);
    freopen("perimetric_chapter_1_output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas){
        int N, K, W;
        int AL, BL, CL, DL;
        int AH, BH, CH, DH;
        scanf("%d %d %d", &N, &K, &W);

        for(int i = 0; i < K; ++i) {
            scanf("%d", &L[i]);
        }
        
        scanf("%d %d %d %d", &AL, &BL, &CL, &DL);

        for(int i = 0; i < K; ++i) {
            scanf("%d", &H[i]);
        }
        
        scanf("%d %d %d %d", &AH, &BH, &CH, &DH);

        for(int i = K; i < N; ++i) {
            L[i] = ( ( 1ll *AL * L[i - 2] + 1ll * BL * L[i - 1] + CL) % DL) + 1;
            H[i] = ( ( 1ll *AH * H[i - 2] + 1ll * BH * H[i - 1] + CH) % DH) + 1;
        }
        
        ll ans = 1;
        ll tmp_ans = 0;
        std::deque<pair<int, int> > Q;
        // map<int, int> mp; 
        for(int i = 0; i < N; ++i) {
            if(i == 0) {
                tmp_ans += 2 * W + 2 * H[i];
                Q.push_back({H[i], L[i]});
                // for(int j = L[i]; j <= L[i] + W; ++j) {
                //     mp[j] = H[i];
                // }
            } else {
                while(!Q.empty()) {
                    if(Q.front().second + W < L[i]) Q.pop_front();  
                    else break;  
                }
                if(L[i] <= L[i - 1] + W) {
                    assert(!Q.empty());
                    int maxx = -1;
                    // for(int j = L[i]; j <= L[i] + W; ++j) {
                    //     maxx = max(maxx, mp[j]);
                    // }
                    if(!Q.empty()) {
                        maxx = Q.front().first;
                    }

                    if(maxx < H[i]) {
                        tmp_ans += 2 * (H[i] - maxx);
                    }
                    tmp_ans += 2 * (L[i] - L[i - 1]);
                } else {
                    assert(Q.empty());
                    tmp_ans += 2 * W + 2 * H[i];
                }

                

                if(Q.empty()) {
                    Q.push_back({H[i], L[i]});
                } else {
                    while(!Q.empty() && Q.back().first < H[i]) Q.pop_back();
                    Q.push_back({H[i], L[i]});
                }                
            }
            tmp_ans %= MOD;

            ans = tmp_ans * ans % MOD;

            // debug(tmp_ans);
        }

        printf("Case #%d: %lld\n", cas, ans);
    }
}

/*

5
2 2 2
1 2
0 0 0 100
3 3
0 0 0 100
2 2 2
10 20
0 0 0 100
3 3
0 0 0 100
5 5 3
2 4 5 9 12
0 0 0 100
4 3 6 3 2
0 0 0 100
10 3 8
9 14 15
0 1 3 53
12 7 16
5 2 1 38
50 10 17
4 9 10 26 28 59 97 100 105 106
1 0 7 832
130 12 82 487 12 30 214 104 104 527
21 81 410 605

*/