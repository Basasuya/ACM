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

char seq[205];
set<pair<int, int> > st;
vector<int> cnt;
vector<int> has;
vector<vector<int> > E;

string dfs(int x, int pre) {
    // debug(x, x + 'a');
    char c = x + 'a';
    string ans; ans += c;
    for(int i = 0, len = E[x].size(); i < len; ++i) {
        int to = E[x][i]; if(to == pre) continue;
        has[to] = 1;
        ans += dfs(to, x);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%s", seq);
        int len = strlen(seq);

        st.clear(); cnt.clear(); has.clear(); E.clear();
        for(int i = 0; i < 26; ++i) {
            cnt.push_back(0);
            has.push_back(0);
            E.push_back(vector<int>());
        }

        for(int i = 1; i < len; ++i) {
            int t1 = seq[i] - 'a'; int t2 = seq[i-1] - 'a';
            if(t1 > t2) swap(t1, t2);
            if(!st.count({t1, t2})) {
                cnt[t1] ++; cnt[t2] ++;
                E[t1].push_back(t2); E[t2].push_back(t1);
                st.insert({t1, t2});
            }
        }  

        bool suc = true;
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 2) {
                suc = false;
                break;
            }
        } 

        if(suc == false) {
            printf("NO\n"); continue;
        }

        

        string result; result.clear();

        for(int i = 0; i < 26; ++i) {
            if(has[i] == 0 && cnt[i] == 1) {
                has[i] = 1;
                result += dfs(i, i);
            }
        }

        for(int i = 0; i < 26; ++i) {
            if(has[i] == 0 && cnt[i] > 0) {
                suc = false; break;
            }
            if(has[i] == 0 && cnt[i] == 0) {
                result += i + 'a';
            }
        }

        if(suc == false) printf("NO\n");
        else printf("YES\n%s\n", result.c_str());
    }
    return 0;
}