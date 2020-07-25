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

const int MAXN = 3e5 + 5;
int A[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        auto overlap = [](pair<int, int> A, pair<int, int> B) -> bool { if(A.second < B.first || B.second < A.first) return false; return true; };
        int n, K, L;
        scanf("%d %d %d", &n, &K, &L);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        pair<int, int> range = {-1, -1};
        bool sucess = true;
        for(int i = 0; i < n && sucess; ++i) {
            int tmp = L - A[i];
            if(tmp < 0) {
                sucess = false; break;
            } else {
                tmp = min(tmp, K);
                if(tmp == K) {
                    range = {-1, -1};
                } else {
                    if(range == make_pair(-1, -1)) {
                        range = {-tmp, tmp};
                    } else {
                        range.first += 1; range.second += 1;
                        if(!overlap(range, {-tmp, tmp})) {
                            sucess = false; break;
                        }
                        range = make_pair(max(range.first, -tmp), min(range.second, tmp));
                    }
                }
            }
            // debug(range);

        }

        printf("%s\n", sucess ? "YES" : "NO");
    }
    return 0;
}

/*
7
2 1 1
1 0
5 2 3
1 2 3 2 2
4 3 4
0 2 4 3
2 3 5
3 0
7 2 3
3 0 2 1 3 0 1
7 1 4
4 4 3 0 2 4 2
5 2 3
1 2 3 2 2


*/