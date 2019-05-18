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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
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

const int N = 2e5 + 5;
char seq[N];
char choose[N];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", seq);
    string t1, t2;
    t1.clear(); t2.clear();
    int cnt1 = 0, cnt2 = 0;
    int max1 = -1; int max2 = -1;
    for(int i = 0; i < n; ++i) {
        if(seq[i] == '(') {
            if(cnt1 <= cnt2) {
                choose[i] = '0';
                t1 += seq[i];
                cnt1 ++;
            } else {
                choose[i] = '1';
                t2 += seq[i];
                cnt2 ++;
            }
        } else {
            if(cnt1 > cnt2) {
                choose[i] = '0';
                t1 += seq[i];
                cnt1 --;
            } else {
                choose[i] = '1';
                t2 += seq[i];
                cnt2 --;
            }
        }
        max1 = max(cnt1, max1);
        max2 = max(cnt2, max2);
    }
    choose[n] = 0;
    debug(max(max1, max2));
    printf("%s\n", choose);
}