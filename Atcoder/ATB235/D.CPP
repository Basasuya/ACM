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

int ten[100] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int transfer(int x) {
    int cnt = 0; int first_number = 0; int tmp = x; int second_number = 0;

    while(tmp) {
        cnt ++;
        first_number = tmp % 10;
        tmp /= 10;
    }

    if ( (x - first_number * ten[cnt]) / ten[cnt - 1] == 0 ) return -1;

    return (x - first_number * ten[cnt]) * 10 + first_number;
}

int main() {
    int a, N;
    while(~scanf("%d %d", &a, &N)) {
        map<int, int> mp;
        queue<pair<int, int>> Q;
        Q.push({N, 0});
        mp[N] = 1;

        int ans = -1;

        while(!Q.empty()) {
            auto& tt = Q.front(); Q.pop();
            
            debug(tt);

            int new_number;
            if (tt.first > 10) {
                new_number = transfer(tt.first);
                if (new_number != -1 && mp.find(new_number) == mp.end()) {
                    mp[new_number] = 1;
                    Q.push({new_number, tt.second + 1});
                    if (new_number == 1) {
                        ans = tt.second + 1; break;
                    }
                }
            }
            
            if (tt.first % a == 0) {
                new_number = tt.first / a;
                if (mp.find(new_number) == mp.end()) {
                    mp[new_number] = 1;
                    Q.push({new_number, tt.second + 1});
                    if (new_number == 1) {
                        ans = tt.second + 1; break;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}