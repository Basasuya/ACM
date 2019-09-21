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

const int MAXN = 2e5 + 5;
char seq[MAXN];
char choose[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        scanf("%s", seq);

        bool suc = false;
        for(int j = 0; j <= 9; ++j) {
            string t1,  t2;
            bool tag = false;
            t1.clear(); t2.clear();
            for(int i = 0; i < n; ++i) {
                if(seq[i] - '0' < j) {
                    t1 += seq[i];
                    choose[i] = '1';
                } else if(seq[i] - '0' == j) {
                    if(tag == true) {
                        t1 += seq[i];
                        choose[i] = '1';
                    } else {
                        t2 += seq[i];
                        choose[i] = '2';
                    }
                }
                else {
                    tag = true;
                    t2 += seq[i];
                    choose[i] = '2';
                }
            }

            bool flag = true;
            // cout << t1 << ' ' << t2 << endl;
            t1 = t1 + t2;
            
            for(int i = 1; i < n; ++i) {
                if(t1[i] < t1[i-1]) {
                    flag = false;  break;
                }
            }
            if(flag == true) {
                suc = true;
                break;
            }
        }
        if(suc == false) {
            printf("-\n");
            continue;
        }

        choose[n] = 0;
        printf("%s\n", choose);

        // for(int i = 0; i < n; ++i) {
        //     if(choose[i] == '1') printf("%c", seq[i]);
        // } printf("\n");

        // for(int i = 0; i < n; ++i) {
        //     if(choose[i] == '2') printf("%c", seq[i]);
        // } printf("\n");

    }
    return 0;
}

/*


5
12
040425524644
1
0
9
123456789
2
98
3
987


*/