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


int main() {
    int T;
    scanf("%d", &T);
    vector<string> answer;

    vector<string> vc[2];
    vc[0].push_back("169");
    vc[0].push_back("196");
    vc[0].push_back("961");
    int offset = 1;
    for(int i = 5; i <= 99; i += 2) {
        string ans = "";

        for(int i = 0, len = vc[offset ^ 1].size(); i < len; ++i) {
            ans += vc[offset ^ 1][i] + "00\n";
            vc[offset].push_back(vc[offset ^ 1][i] + "00");
        }


        int gap = (i - 3) / 2 + 1;
        string tmp = "9";
        for(int j = 1; j < i - 1; ++j) {
            tmp += j % gap == 0 ? "6" : "0";
        }
        tmp += "1";
        ans += tmp + "\n";
        vc[offset].push_back(tmp);

        tmp = "1";
        for(int j = 1; j < i - 1; ++j) {
            tmp += j % gap == 0 ? "6" : "0";
        }
        tmp += "9";
        ans += tmp + "\n";
        vc[offset].push_back(tmp);
        // debug(vc[offset]);
        answer.push_back(ans);
        vc[offset ^ 1].clear();
        offset ^= 1;

        // if (i >= 10) {
        //     return 0;
        // }
    }

    while(T --) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            printf("1\n"); continue;
        } else if (n == 3) {
            printf("169\n196\n961\n"); continue;
        }

        printf("%s", answer[n / 2 - 2].c_str());
    }
    return 0;
}