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

char S[65][65];

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int r, c;
        scanf("%d %d", &r, &c);

        for(int i = 1; i <= r; ++i) {
            scanf("%s", S[i] + 1);
        }

        int L = INF, R = -1, D = -1, U = INF;
        int _L = INF, _R = -1, _D = -1, _U = INF;
        bool findP = false; bool findA = false;
        for(int i = 1; i <= r; ++i) {
            // int cnt = 0;
            for(int j = 1; j <= c; ++j) {
                if(S[i][j] == 'P') {
                    _L = min(_L, j);
                    _R = max(_R, j);
                    _U = min(_U, i);
                    _D = max(_D, i);
                    findP = true;
                } else {
                    L = min(L, j);
                    R = max(R, j);
                    U = min(U, i);
                    D = max(D, i);
                    findA = true;
                }
            }
        }   

        // debug(L, R, U, D);
        // debug(_L, _R, _U, _D);

        

        bool canTwo = false;
        for(int turn = 0; turn < 2 && !canTwo; turn ++) {
            int st, ed, step;

            if(turn == 0) {
                st = 1; ed = r; step = 1;
            } else {
                st = r; ed = 1; step = -1;
            }

            debug(st, ed, step);
            pair<int, int> range = make_pair(INF, -1);
            for(int i = st; !canTwo; i += step) {
                if(i == st) {
                    int cnt = 0;
                    for(int j = 1; j <= c; ++j) {
                        if(S[i][j] == 'P') {
                            range.first = min(range.first, j);
                            range.second = max(range.second, j);
                            cnt ++;
                        }
                    }
                    if(cnt == 0 || S[i][1] == 'A' || S[i][c] == 'A') {
                        canTwo = true; break;
                    }
                } else {
                    int cnt = 0;
                    for(int j = 1; j <= c; ++j) {
                        if(S[i][j] == 'A') {
                            if(j >= range.first && j <= range.second) {
                                cnt ++;
                            }
                        }
                    }
                    if(cnt == range.second - range.first + 1) {
                        canTwo = true; break;
                    }
                }

                if(i == ed) break;
            }
        }

        for(int turn = 0; turn < 2 && !canTwo; turn ++) {
            int st, ed, step;

            if(turn == 0) {
                st = 1; ed = c; step = 1;
            } else {
                st = c; ed = 1; step = -1;
            }
            pair<int, int> range = make_pair(INF, -1);

            debug(st, ed, step);
            for(int i = st; i <= ed && !canTwo; i += step) {
                if(i == st) {
                    int cnt = 0;
                    for(int j = 1; j <= r; ++j) {
                        if(S[j][i] == 'P') {
                            range.first = min(range.first, j);
                            range.second = max(range.second, j);
                            cnt ++;
                        }
                    }
                    if(cnt == 0 || S[1][i] == 'A' || S[r][i] == 'A') {
                        canTwo = true; break;
                    }
                } else {
                    int cnt = 0;
                    for(int j = 1; j <= r; ++j) {
                        if(S[j][i] == 'A') {
                            if(j >= range.first && j <= range.second) {
                                cnt ++;
                            }
                        }
                    }
                    if(cnt == range.second - range.first + 1) {
                        canTwo = true; break;
                    }
                }

                if(i == ed) break;
            }
        }

        if(findP == false) printf("0\n");
        else if(findA == false) printf("MORTAL\n");
        else if(L >= 2 && R <= c-1 && U >= 2 && D <= r-1) printf("4\n");
        else if(_L != 1 || _R != c || _U != 1 || _D != r) printf("1\n");
        else if(canTwo) printf("2\n");
        else printf("3\n");

    }
    return 0;
}


/*

4 4
AAAA
AAAA
AAAA
AAAA

4 4
AAAA
APAA
AAAA
AAAA


4 4
PAAA
PAAA
PPAP
PPAP

1 4
AAAA


4 4
PAAA
PAAA
PPAP
PPAP

4 4
PPPP
PAAP
PPAP
PPP

*/