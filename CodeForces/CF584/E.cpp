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

int A[15][2005];
int solve(int x, int y) {
    int ans = -1;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int tmp = 0;
            for(int l = 0; l < 4; ++l) {
                int t1 = A[(l + i) % 4][x];
                int t2 = A[(l + j) % 4][y];
                tmp += max(t1, t2);
            }
            ans = max(tmp, ans);
        }
    }
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        

        if(n <= 3) {
            vector<int> vc;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    vc.push_back(A[i][j]);
                }
            }
            auto cmp = [](int a, int b) { return a > b; };
            sort(vc.begin(), vc.end(), cmp);
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                ans += vc[i];
            }
            printf("%d\n", ans);
        } else if(n == 4){

            vector<tuple<int, int, int> > vc;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    vc.emplace_back(A[i][j], i, j);
                }
            }
            auto cmp = [](tuple<int, int, int> a, tuple<int, int, int> b) { return get<0>(a) > get<0>(b); };
            sort(vc.begin(), vc.end(), cmp);
            int ans = 0;
            map<int, int> mp;
            for(int i = 0; i < 4; ++i) {
                ans += get<0>(vc[i]);
                mp[get<2>(vc[i])] ^= 1<<get<1>(vc[i]);
            }

            bool special = false;
            debug(mp);
            if(mp.size() == 2) {
                int tag1 = 0, tag2 = 0;
                for(auto it : mp) {
                    if(it.second == 3 || it.second == 6 || it.second == 12 || it.second == 9) tag1 = 1;
                    else if(it.second == 5 || it.second == 10) tag2 = 1;
                }

                if(tag1 && tag2) special = true;
            }
            debug(special);

            if(special) {
                if(mp.find(get<2>(vc[4])) == mp.end()) {
                    ans += get<0>(vc[4]) - get<0>(vc[3]);
                } else {
                    // assert(0);
                    int ans1 = -1; int ans2 = -1;
                    for(int i = 5; i < n; ++i) {
                        if(mp.find(get<2>(vc[i])) == mp.end()) {
                            ans1 = ans + get<0>(vc[i]) - get<0>(vc[3]);
                            break;
                        }
                    }

                    vector<int> tt;
                    for(auto it : mp) { tt.push_back(it.first); }
                    ans2 = solve(tt[0], tt[1]);
                    ans = max(ans1, ans2);
                }
            }

            printf("%d\n", ans);

        } else {
            assert(0);
        }

    }
    return 0;
}

/*

200
2 3
2 5 7
4 2 4
3 6
4 1 5 2 10 4
8 6 6 4 9 10
5 4 9 5 8 7
4 3
2 5 7
4 2 4
5 10 10
12 12 12
4 3
2 5 7
4 11 4
12 10 10
12 11 9
*/