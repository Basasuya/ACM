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

int main() {
    int T;
    cin >> T;
    while(T --) {
        string s;
        cin >> s;
        int slen = s.length();
        int ans = 0;

        vector<int> has;
        has.resize(slen);
        for(int i = 0; i < slen; ++i) {
            if(s[i] == '1') has[i] ++;
        }
        for(int i = 1; i < slen; ++i) {
            has[i] += has[i-1];
        }

        auto sum = [&](int fr, int to) {
            
            if(fr < 0) return -1;
            else if(fr == to + 1) return 0;
            else if(fr == 0) return has[to];
            else return has[to] - has[fr - 1]; 
        };

        for(int i = 1; i <= 18; ++i) {
            // debug(i);
            int minNum = 1<<(i-1);
            if((1<<(i-1)) > slen) break;
            int tmp = 0;
            for(int j = 0; j < i; ++j) {
                tmp = tmp * 2 + (s[j] == '1');
            }
            if(tmp >= minNum && sum(i - tmp, -1) == 0) ans ++;
            for(int j = i; j < slen; ++j) {
                tmp *= 2;
                tmp &= (1 << i) - 1;
                tmp += (s[j] == '1');
                // debug(i - tmp, j - i, sum(j - tmp + 1, j - i), tmp);
                if(tmp >= minNum && sum(j - tmp + 1, j - i) == 0) ans ++;
                // debug(ans);
            }
            // debug(ans);
        }

        printf("%d\n", ans);
    }
    return 0;
}

/*


4
0110
0101
00001000
0001000 

*/