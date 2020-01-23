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

const int N = 1e5 + 5;
int isPrime[N]; 
int Prime[N];
int primeTot;

int main() {
    int T;
    scanf("%d", &T);

    primeTot = 0;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }

    while(T --) {
        int n;
        scanf("%d", &n);

        vector<pair<int, int> > vc;
        int sum = 0;
        for(int i = 1; i <= primeTot; ++i) {
            if(1ll * Prime[i] * Prime[i] > n) break;
            if(n % Prime[i] == 0) {
                int cnt = 0;
                while(n % Prime[i] == 0) {
                    n /= Prime[i];
                    cnt ++;
                }
                sum += cnt;
                vc.push_back({Prime[i], cnt});
            }
        }
        if(n != 1) {
            vc.push_back({n, 1});
            sum ++;
        }



        if(sum < 3) printf("NO\n");
        else if(sum == 3) {
            if(vc.size() == 3) {
                printf("YES\n");
                printf("%d %d %d\n", vc[0].first, vc[1].first, vc[2].first);
            }
            else printf("NO\n");
        } else {
            vector<int> tmp;
            for(auto item : vc) {
                for(int j = 0; j < item.second; ++j) {
                    tmp.push_back(item.first);
                }
            }

            int a = tmp[0]; int b = tmp[1] * tmp[2]; int c = 1;
            for(int i = 3; i < sum; ++i) {
                c *= tmp[i];
            }
            if(b == c) { b /= tmp[2]; c *= tmp[2]; }

            if(a == b || b == c || a == c) printf("NO\n");
            else {
                printf("YES\n");
                printf("%d %d %d\n", a, b, c);
            }
        }


    }
    return 0;
}