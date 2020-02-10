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

const double eps = 1e-5;

const int MAXN = 1e5 + 5;
int X[MAXN], Y[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) scanf("%d %d", &X[i], &Y[i]);

        double X_center = 0; double Y_center = 0; double A = 0;
        for(int i = 0; i < n; ++i) {
            int a = i; int b = (i + 1) % n;
            double tmp = (X[a] * 1.0 * Y[b] - X[b] * 1.0 * Y[a]);
            X_center += (X[a] + X[b]) * 1.0 * tmp;
            Y_center += (Y[a] + Y[b]) * 1.0 * tmp;
            A += tmp;
        }
        A /= 2;
        X_center /= 6 * A;
        Y_center /= 6 * A;

        vector<pair<double, double> > vc;


        for(int i = 0; i < n; ++i) {
            vc.push_back({X[i] - X_center, Y[i] - Y_center});
        }

        sort(vc.begin(), vc.end());
        
        bool suc = true;
        for(int i = 0; i < n; ++i) {
            double t1 = X[i] - X_center;
            double t2 = Y[i] - Y_center;
            t1 = -t1; t2 = -t2;

            int tt = lower_bound(vc.begin(), vc.end(), make_pair(t1, t2)) - vc.begin();
            
            // debug(tt, t1, t2);
            bool ok = false;
            for(int j = max(tt - 5, 0), len = min( (int)vc.size(), tt + 5); j < len; ++j) {
                // debug(vc[j]);
                if( abs(vc[j].first - t1) < eps && abs(vc[j].second - t2) < eps ) {
                    ok = true;
                    break;
                }
            }

            if(ok == false) {
                suc = false;
                break;
            }

        }

        printf("%s\n", suc == true ? "YES" : "NO");
    }
    return 0;
}