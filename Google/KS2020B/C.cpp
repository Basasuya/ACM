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

const int MAXN = 2e3 + 5;
char seq[MAXN];
const int MOD = 1e9;

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%s", seq);
        int len = strlen(seq);

        ll X = 0; ll Y = 0;

        vector<pair<ll, ll> > st;
        for(int i = 0; i < len; ++i) {
            if(seq[i] == ')') {
                ll x_tmp = 0; ll y_tmp = 0;
                while(!st.empty()) {
                    auto tmp = st.back(); st.pop_back();
                    if(tmp.first == INF) {
                        x_tmp = x_tmp * tmp.second % MOD;
                        y_tmp = y_tmp * tmp.second % MOD;
                        break;
                    }

                    x_tmp = (x_tmp + tmp.first + MOD) % MOD;
                    y_tmp = (y_tmp + tmp.second + MOD) % MOD;
                }

                st.push_back({x_tmp, y_tmp});
            } else {
                if(seq[i] == 'N') {
                    st.push_back({0, 999999999});
                } else if(seq[i] == 'S') {
                    st.push_back({0, 1});
                } else if(seq[i] == 'W') {
                    st.push_back({999999999, 0});
                } else if(seq[i] == 'E') {
                    st.push_back({1, 0});
                } else if(seq[i] >= '2' && seq[i] <= '9'){
                    st.push_back({INF, seq[i] - '0'});
                }
            }
        }

        {
            ll x_tmp = 0; ll y_tmp = 0;
            while(!st.empty()) {
                auto tmp = st.back(); st.pop_back();
                assert(tmp.first != INF);
                x_tmp = (x_tmp + tmp.first + MOD) % MOD;
                y_tmp = (y_tmp + tmp.second + MOD) % MOD;
            }
            st.push_back({x_tmp, y_tmp});
        }

        printf("Case #%d: %lld %lld\n", cas, st.back().first + 1, st.back().second + 1);
    }
    return 0;
}