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

const int MAXN = 55;
char s[MAXN];
char t[MAXN];
int pos[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n;
        scanf("%d", &n);
        scanf("%s %s", s + 1, t + 1);

        int has[30]; 
        memset(has, 0, sizeof(has));
        

        for(int i = 1; i <= n; ++i) {
            has[s[i] - 'a'] ++; has[t[i] - 'a'] ++;
        } 

        bool suc = true;
        for(int i = 0; i < 26; ++i) {
            if(has[i] % 2) {
                suc = false;
                break;
            }
        } 


        if(suc == false) {
            printf("No\n");
            continue;
        }

        vector<pair<int, int > > result;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == t[i]) continue;
            else {
                int tag = 0;
                for(int j = i + 1; j <= n; ++j) {
                    if(s[j] == s[i]) {
                        tag = j; break;
                    }
                    if(t[j] == s[i]) {
                        tag = -j;  break;
                    }
                }
                if(tag > 0) {
                    swap(s[tag], t[i]);
                    result.push_back(make_pair(tag, i));
                } else {
                    tag *= -1;
                    swap(s[tag], t[tag]);
                    swap(s[tag], t[i]);
                    result.push_back(make_pair(tag, tag));
                    result.push_back(make_pair(tag, i));
                }

            }
        }

        // for(int i = 1; i <= n; ++i) { assert(s[i] == t[i]); }

        printf("Yes\n");
        printf("%d\n", (int) result.size());
        for(int i = 0, len = result.size(); i < len; ++i) {
            printf("%d %d\n", result[i].first, result[i].second);
        }

    }
    return 0;
}