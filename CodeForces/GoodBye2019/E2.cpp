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

const int MAXN = 1e3 + 5;

int X[MAXN], Y[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &X[i], &Y[i]);
            X[i] += 1e6;
            Y[i] += 1e6;
        }

        vector<int> ans;
        while(1) {
            int cnt[5]; memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < n; ++i) {
                cnt[2 * (X[i] % 2) + Y[i] % 2] ++;
            }

            if(cnt[0] + cnt[3] > 0 && cnt[1] + cnt[2] > 0) {
                for(int i = 0; i < n; ++i) {
                    int tmp = 2 * (X[i] % 2) + Y[i] % 2;
                    if(tmp == 0 || tmp == 3) ans.push_back(i);
                }
                break;
            } else if(cnt[1] && cnt[2]) {
                for(int i = 0; i < n; ++i) {
                    int tmp = 2 * (X[i] % 2) + Y[i] % 2;
                    if(tmp == 1) ans.push_back(i);
                }
                break;

            } else if(cnt[0] && cnt[3]) {
                for(int i = 0; i < n; ++i) {
                    int tmp = 2 * (X[i] % 2) + Y[i] % 2;
                    if(tmp == 0) ans.push_back(i);
                }
                break;
            }

            int target = -1;
            for(int i = 0; i < 4; ++i) {
                if(cnt[i] > 0) {
                    target = i; break;
                }
            }

            for(int i = 0; i < n; ++i) {
                X[i] = (X[i] - (target >> 1)) / 2;
                Y[i] = (Y[i] - (target & 1)) / 2; 
            }
        }

        printf("%d\n", (int) ans.size());
        for(int i = 0, len = ans.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i] + 1);
        }
        printf("\n");
    }
    return 0;
}