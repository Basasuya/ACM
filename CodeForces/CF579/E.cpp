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
// #define ll long long
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

const int MAXN = 150005;
int A[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        map<int, int> mp;
        set<int> st;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            mp[A[i]] ++;
            // st.insert(A[i]);
        }
        vector<pair<int,int>> tmp2, tmp1;
        for(auto it : mp) {
            if(it.second >= 3) {
                st.insert(max(1, it.first - 1));
                st.insert(it.first + 1);
                st.insert(it.first);
            } else if(it.second == 2) tmp2.push_back(it);
            else tmp1.push_back(it);
        }

        for(auto it : tmp2) {
            if(it.second == 2) {
                st.insert(it.first);
                if(st.find(max(1, it.first - 1)) == st.end()) st.insert(max(1, it.first - 1));
                else st.insert(it.first + 1);
            }
        }

        for(auto it : tmp1) {
            if(it.second == 1) {
                debug(it);
                if(st.find(it.first) != st.end()) {
                    if(st.find(max(1, it.first - 1)) == st.end()) st.insert(max(1, it.first - 1));
                    else st.insert(it.first + 1);
                } else st.insert(it.first);
            }
        }

        printf("%d\n", (int)st.size());

    }
    return 0;
}