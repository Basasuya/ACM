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

bool check_first_round(vector<int> &has, int n, int k) {
    for(int i = 1; i <= n - k + 1; ++i) {
        int tmp = has[i-1] - has[0] + has[n] - has[i + k - 1];
        if(tmp == 0 || tmp == n - k) return true;
    }
    return false;
}

bool check_second_round(vector<int> &has, int n, int k) {
    if(2 * k < n || k == 1) return false;
    for(int i = 2; i <= n - k; ++i) {
        int tmp1 = has[i-1] - has[0];
        int tmp2 = has[n] - has[i + k - 1];

        if( (tmp1 == 0 && tmp2 == n - i - k + 1) || (tmp1 == i - 1 && tmp2 == 0) ); 
        else return false;
    }
    debug("hhhh");
    // if(has[k] != 0 && has[k] != k) return false;
    // if(has[n] - has[n - k] != 0 && has[n] - has[n - k] != k) return false;
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, k;
    while(cin >> n >> k) {
        string s;
        cin >> s;
        vector<int> has(n + 5, 0);
        for(int i = 0, len = s.length(); i < len; ++i) {
            has[i + 1] += s[i] - '0';
        }
        for(int i = 1; i <= n; ++i) {
            has[i] += has[i-1];
        }

        if(check_first_round(has, n, k)) cout << "tokitsukaze" << endl;
        else {
            if(check_second_round(has, n, k)) cout << "quailty" << endl;
            else cout << "once again" << endl;
        }
    }
    return 0;
}