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

const int MAXN = 2e5 + 5;
int A[MAXN];
int nx[MAXN];
int pr[MAXN];

int output_number = 0;
int caseT = 0;

void output_ans(int n) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (A[i]) {
            ans ++;
        }
    }
    printf("%d\n", ans);
    output_number ++;
    // if (output_number == 380) {
    //     exit(caseT);
    // }
    for(int i = 0, cnt = 0; i < n; ++i) {
        if (A[i]) {
            if (cnt) printf(" ");
            printf("%d", i + 1);
            cnt ++;
            output_number ++;
            // if (output_number == 380) {
            //     exit(caseT);
            // }
        }
    }
    
    
    
    printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    int old_T = T;
    
    while(T --) {
        caseT ++;
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            nx[i] = i + 1;
            pr[i] = i - 1;
        }
        nx[n - 1] = 0;
        pr[0] = n - 1;

        // if(old_T == 10000) {
        //     // if (caseT == 188) {
        //     //     for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");
        //     // }
        //     continue;
        // }
        
        if(n == 2) {
            while(true) {
                for(int i = 1; i < n; ++i) {
                    A[i] = max(0, A[i] - A[i - 1]);
                }
                A[0] = max(0, A[0] - A[n - 1]);
                
                if (A[0] == 0 || A[1] == 0) {
                    break;
                }
            }

            output_ans(n);
            continue;
        } else if (n == 3) {
            while(true) {
                for(int i = 1; i < n; ++i) {
                    A[i] = max(0, A[i] - A[i - 1]);
                }
                A[0] = max(0, A[0] - A[n - 1]);
                
                if (A[0] == 0 || A[1] == 0 || A[2] == 0) {
                    break;
                }
            }

            for(int i = 0; i < n; ++i) {
                int pre_index = (i - 1 + n) % n;
                int pre2_index = (i - 2 + n) % n;
                if (A[pre_index] != 0 && A[i] == 0 && A[pre2_index] != 0) {
                    A[pre_index] = 0;
                }
            }

            // for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");
            output_ans(n);
            continue;
        }

        set<int> st;
        int start_pos = 1;
        while(true) {
            for(int i = 1; i < n;) {
                A[i] = max(0, A[i] - A[i - 1]);
                if(A[i] == 0) {
                    nx[pr[i]] = nx[i];
                    pr[nx[i]] = pr[i];
                }
                i = nx[i];
            }
            if (i)
            A[0] = max(0, A[0] - A[n - 1]);
            
            bool finish = true;
            for(int i = 0; i < n; ++i) {
                int pre = A[(i - 1 + n) % n];
                int pre2 = A[(i - 2 + n) % n];
                int pre3 = A[(i - 3 + n) % n];
                if (pre != 0 && A[i] != 0 && pre2 != 0 && pre3 != 0) {
                    finish = false;
                    break;
                }
            }
            if (finish) {
                break;
            }
        }

        // for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");

        for(int i = 0; i < n; ++i) {
            int pre_index = (i - 1 + n) % n;
            int pre2_index = (i - 2 + n) % n;
            int pre3_index = (i - 3 + n) % n;
            if (A[pre_index] != 0 && A[i] != 0 && A[pre2_index] != 0) {
                if (i == 1) {
                    A[1] = max(A[1] - A[0], 0);
                }

                int turn = (A[pre_index] - 1) / A[pre2_index];
                debug(turn);
                A[i] = max(1ll * 0, 1ll * A[i] - 1ll * turn * A[pre_index] + 1ll * turn * (turn + 1) / 2 * A[pre2_index]);
                A[pre_index] = 0;

            } else if (A[pre_index] != 0 && A[i] == 0 && A[pre2_index] != 0 && A[pre3_index] == 0) {
                A[pre_index] = 0;
            }
        }

        // for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");

        output_ans(n);
    }
    return 0;
}


/*

4 2
5 3
6 4
7 5
8 6

*/