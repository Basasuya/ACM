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
    int fr, to, nx, dis, cost;
}E[N << 1];

int head[N]; int tot = 0; 

void add(int fr, int to, int wei, int cost) {
    E[tot].to = to; E[tot].nx = head[fr]; E[tot].dis = wei; E[tot].cost = cost; head[fr] = tot ++;
}

vector<ll> dis_list_one;
vector<ll> dis_list_two;

ll ans = 0;

int dfs(int x, int pre, int dis, int cost) {
    int sons = 0;
    int leafs = 0;
    for(int i = head[x]; ~i; i = E[i].nx) {
        int to = E[i].to;
        if(to == pre) continue;
        leafs += dfs(to, x, E[i].dis, E[i].cost);
        sons ++;
    }

    if(sons == 0) leafs = 1;

    debug(x, dis, leafs, sons);
    
    int tmp = dis;
    ans += 1ll * dis * leafs;
    while(tmp) {
        if(cost == 1) dis_list_one.push_back( 1ll * (tmp - tmp / 2) * leafs) ;
        else if(cost == 2) dis_list_two.push_back( 1ll * (tmp - tmp / 2) * leafs) ;
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
        dis_list_one.clear();
        dis_list_two.clear();

        for(int i = 1; i < n; ++i) {
            int fr, to, wei, cost; 
            scanf("%d %d %d %d", &fr, &to, &wei, &cost);
            add(fr, to, wei, cost);
            add(to, fr, wei, cost);
        }

        dfs(1, 1, 0, 0);

        sort(dis_list_one.begin(), dis_list_one.end(), [](ll x, ll y) {return x > y; });
        sort(dis_list_two.begin(), dis_list_two.end(), [](ll x, ll y) {return x > y; });
        
        int result = INF;
        debug(ans);
        if(ans <= S) {
            printf("0\n");
            continue;
        }
        
        for(int i = 1, len = dis_list_one.size(); i < len; ++i) {
            dis_list_one[i] += dis_list_one[i - 1];
        }

        for(int i = 1, len = dis_list_two.size(); i < len; ++i) {
            dis_list_two[i] += dis_list_two[i - 1];
        }

        for(int i = 0, len = dis_list_one.size(); i < len; ++i) {
            ll tt = ans - dis_list_one[i] - S;
            if(tt <= 0) {
                result = min(result, i + 1);
                break;
            }

            int pos = lower_bound(dis_list_two.begin(), dis_list_two.end(), tt) - dis_list_two.begin();

            if(pos != dis_list_two.size()) {
                result = min(result, i + 1 + 2 * (pos + 1));
            }
        }

        int pos = lower_bound(dis_list_two.begin(), dis_list_two.end(), ans - S) - dis_list_two.begin();

        if(pos != dis_list_two.size()) {
            result = min(result, 2 * (pos + 1));
        }

        printf("%d\n", result);
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