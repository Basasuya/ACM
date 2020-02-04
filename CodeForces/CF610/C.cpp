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

int A[MAXN], T[MAXN];

int main() {
    int cas;
    scanf("%d", &cas);
    for(int CAS = 1; CAS <= cas; ++CAS) {
        int n, time, a, b;
        scanf("%d %d %d %d", &n, &time, &a, &b);
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
        for(int i = 0; i < n; ++i) scanf("%d", &T[i]);
        int allty[2] = {0, 0};
        int ty[2] = {0, 0};
        for(int i = 0; i < n; ++i) {
            allty[A[i]] ++;
        }

        vector<int> id;
        for(int i = 0; i < n; ++i) id.push_back(i);
        auto cmp = [&] (int x, int y) { return T[x] < T[y]; };
        sort(id.begin(), id.end(), cmp);
        auto get = [&] (int easy, int hard, int easyAll, int hardAll, int t) {
            int ans = easy + hard;
            easyAll -= easy;
            hardAll -= hard;
            ll need = 1ll * easy * a + 1ll * hard * b;
            // debug(need);
            if(need > t) return 0;
            if(need + 1ll * easyAll * a >= t) {
                ans += (t - need) / a;
                return ans;
            }
            ans += easyAll;
            need += 1ll * easyAll * a;
            ans += min(1ll * hardAll, (t - need) / b);
            return ans;
        };
        
        int ans = 0;
        int easy = 0; int hard = 0;
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                ans = max(get(ty[0], ty[1], allty[0], allty[1], T[id[i]] - 1), ans);   
            } else if(T[id[i]] != T[id[i-1]]){
                ans = max(get(ty[0], ty[1], allty[0], allty[1], T[id[i]] - 1), ans);
            }
            ty[A[id[i]]] ++;
            // debug(ans, i);
        } 

        ans = max(get(ty[0], ty[1], allty[0], allty[1], time), ans);
        // if(CAS == 39) {
        //     printf("hhhh\n");
        //     printf("%d %d %d %d\n", n, time, a, b);
        //     for(int i = 0; i < n; ++i) printf("%d ", A[i]); printf("\n");
        //     for(int i = 0; i < n; ++i) printf("%d ", T[i]); printf("\n");
        //     printf("hhhhh\n");
        // }
        printf("%d\n", ans);
    }
    return 0;
}