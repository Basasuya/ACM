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

const int N = 1e5 + 5;
struct Node{
    int fr, to, nx, dis;
}E[N << 1];

int head[N]; int tot = 0; 

void add(int fr, int to, int wei) {
    E[tot].to = to; E[tot].nx = head[fr]; E[tot].dis = wei; head[fr] = tot ++;
}

vector<ll> dis_list;
ll ans = 0;

int dfs(int x, int pre, int dis) {
    int sons = 0;
    int leafs = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        leafs += dfs(to, x, E[i].dis);
        sons ++;
    }

    if(sons == 0) leafs = 1;

    debug(x, dis, leafs, sons);
    
    int tmp = dis;
    ans += 1ll * dis * leafs;
    while(tmp) {
        dis_list.push_back( 1ll * (tmp - tmp / 2) * leafs) ;
        tmp /= 2;
    }

    return leafs;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        int n; ll S;
        scanf("%d %lld", &n, &S);
        for(int i = 0; i <= n; ++i) {
            head[i] = -1;
        }
        ans = 0;
        tot = 0;
        dis_list.clear();

        for(int i = 1; i < n; ++i) {
            int fr, to, wei; 
            scanf("%d %d %d", &fr, &to, &wei);
            add(fr, to, wei);
            add(to, fr, wei);
        }

        dfs(1, 1, 0);

        sort(dis_list.begin(), dis_list.end(), [](ll x, ll y) { return x > y; });
        
        int cnt = 0;
        
        debug(ans);
        if(ans <= S) {
            printf("0\n");
            continue;
        }

        for(int i = 0, len = dis_list.size(); i < len; ++i) {
            debug(dis_list[i]);
            ans -= dis_list[i];
            cnt ++;
            if(ans <= S) {
                break;
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}

/*

100
5 50
1 3 100
1 5 10
2 3 123
5 4 55

*/