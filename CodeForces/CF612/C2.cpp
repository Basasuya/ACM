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

int p[105];
int has[105];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int odd = (n + 1) / 2; int even = n / 2;
        int oddNow = 0, evenNow = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            if(p[i] == 0) continue;
            if(p[i] % 2 == 0) evenNow ++;
            else oddNow ++;
        }

        if(n == 1) {
            printf("0\n"); continue;
        }
        if(oddNow + evenNow == 0) {
            printf("1\n"); continue;
        }

        int cnt = 0; int pre = -1;
        vector<int> E[2];
        for(int i = 0; i < n; ++i) {
            if(i && p[i] != 0 && p[i-1] != 0) ans += ( (p[i] % 2) != (p[i-1] % 2) );
            
            if(p[i] == 0) cnt ++;
            else {
                if(cnt) {
                    if(pre == -1) E[p[i] % 2].push_back(-cnt);
                    else if(pre != p[i] % 2) ans ++;
                    else E[p[i] % 2].push_back(cnt);
                }

                cnt = 0;
                pre = p[i] % 2;
            }
        }
        if(cnt) E[pre % 2].push_back(-cnt);

        

        int count[2];
        count[1] = odd - oddNow;
        count[0] = even - evenNow;
        
        sort(E[0].begin(), E[0].end());
        sort(E[1].begin(), E[1].end());

        debug(E[0], E[1], count[0], count[1]);

        for(int i = 0; i < 2; ++i) {
            int neg = 0;
            int siz = E[i].size();
            if(siz == 0) continue;
            for(int j = 0, len = siz; j < len; ++j) {
                if(E[i][j] < 0) {
                    // E[i].push_back(E[i][j]);
                    neg ++;
                }
                else break;
            }   

            int partAns = INF;

            for(int j = 0; j < 1<<neg; ++j) {
                int countTmp = count[i];
                int t1 = 0;
                for(int k = 0; k < neg; ++k) {
                    if( (j >> k) & 1 ) E[i][k] = abs(E[i][k]);
                    else { E[i][k] = -abs(E[i][k]); t1 ++; }
                }

                int cnt = 0;
                debug(E[i], countTmp);
                while(cnt < E[i].size() && countTmp >= E[i][cnt]) {
                    if(E[i][cnt] > 0) countTmp -= E[i][cnt];
                    cnt ++;
                }
                partAns = min(partAns, t1 + 2 * ( (int)E[i].size() - cnt) );
            }

            
            ans += partAns;
        }

        

        printf("%d\n", ans);
    }
    return 0;
}