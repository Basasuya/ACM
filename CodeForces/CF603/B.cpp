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

char seq[10][10];
int tag[10];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        set<string> st;
        scanf("%d", &n);
        int ans = 0;
        vector<string> result;

        for(int i = 0; i < n; ++i) {
            scanf("%s", seq[i]);
            string tmp = string(seq[i]);
            if(!st.count(tmp)) {
                st.insert(tmp);
                tag[i] = 0;
            } else tag[i] = 1;
        }
        
        for(int i = 0; i < n; ++i) {
            string tmp = string(seq[i]);

            if(tag[i] == 0) {
                st.insert(tmp);
                result.push_back(tmp);
                continue;
            }

            ans ++;
            bool suc = false;
            for(int j = 0; j < 4 && !suc; ++j) {
                for(int k = 0; k < 10 && !suc; ++k) {
                    string change = tmp;
                    change[j] = '0' + k;
                    if(!st.count(change)) {
                        st.insert(change);
                        result.push_back(change);
                        suc = true;
                        break;
                    }
                }
            }

        }

        printf("%d\n", ans);
        for(int i = 0, len = result.size(); i < len; ++i) {
            printf("%s\n", result[i].c_str());
        }
    }
    return 0;
}

/*

100
10
3139
3139
3139
3139
3139
3139
3139
3139
3139
3139
3
0123
0123
1123
*/