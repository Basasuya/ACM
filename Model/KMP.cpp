#include <iostream>
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
#define mp make_pair
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


void kmp(string s, vector<int>& nex) {
    int m = s.length();
    int i, j;
    j = nex[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && s[i] != s[j]) j = nex[j];
        nex[++i] = ++j;
    }
}

int kmp_count(string s, vector<int> nex, string t) {
    int i = 0, j = 0;
    int ans = 0;
    int m = s.length();
    int n = t.length();

    while(i < n) {
        while(j != -1 && t[i] != s[j]) j = nex[j];
        i ++; j ++;
        if(j >= m) {
            ans ++;
            // j = nex[j]; can overlop
            j = 0;
        }
    }
    return ans;
}

int main() {
    string a, b;
    while(1) {
        cin >> a >> b;
        
        vector<int> nex(a.size() + 5, 0);

        kmp(a, nex);
        cout << kmp_count(a, nex, b) << endl;
    }
}