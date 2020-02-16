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
const int DEG = 20;
int fa[N][DEG];
int deg[N];

struct Node{
    int to, nx;
}E[N << 1];
int head[N]; int tot = 0; 
void add(int fr, int to) {
    E[tot].to = to; E[tot].nx = head[fr]; head[fr] = tot ++;
}

void bfs(int root) {  
	queue<int>que;
	deg[root] = 0;
	fa[root][0] = root;
	que.push(root);
	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
        // printf("%d\n", tmp);
		for (int i = 1; i < DEG; i++){  
			fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
		}
		for (int i = head[tmp]; ~i; i = E[i].nx) {
			int v = E[i].to;
			if (v == fa[tmp][0]) continue;
			deg[v] = deg[tmp] + 1;
			fa[v][0] = tmp;
			que.push(v);
		}
	}
}

int lca(int u, int v) {
	if (deg[u] > deg[v]) swap(u, v);   
	int hu = deg[u], hv = deg[v];
	int tu = u, tv = v;
	for (int det = hv - hu, i = 0; det; det >>= 1, i++)   
	if (det & 1){
		tv = fa[tv][i];
	}
	if (tu == tv) return tu;  
	for (int i = DEG - 1; i >= 0; i--) {
		if (fa[tu][i] == fa[tv][i])
			continue;
		tu = fa[tu][i];
		tv = fa[tv][i];
	}
	if (fa[tu][0] == fa[tv][0]){    
		return fa[tu][0];
	} else return -1;
}

// bool isIn(int x, int y, int fa, int target) {
//     int t1 = lca(x, target);
//     int t2 = lca(y, target);
//     if( (t1 == target && t2 == fa) || (t1 == fa && t2 == target) ) return true;
//     else return false;
// };

int getDis(int x, int y) {
    int tt = lca(x, y);
    return deg[x] + deg[y] - deg[tt] * 2;
}


// bool solve(int x, int y, int a, int b, int k) {
//     int fa = lca(x, y);
//     int loopLen = deg[x] + deg[y] - deg[fa] * 2 + 1;
    

//     int fa2 = lca(a, b);

//     int dis = deg[a] + deg[b] - deg[fa2] * 2;
    
//     bool ain = isIn(x, y, fa, a);
//     bool bin = isIn(x, y, fa, b);

//     debug(loopLen, fa, fa2, dis, ain, bin);

//     if(ain && bin) {
//         int dis2 = loopLen - dis;
//         if( (k - dis >= 0) && (k - dis) % loopLen == 0 ) return true;
//         if( (k - dis2 >= 0) && (k - dis2) % loopLen == 0 ) return true;
//         return false;
//     } else if(ain || bin){
//         if(ain) { swap(a, b); }
        
//         if(deg[lca(a, x)] > deg[lca(a, y)]) swap(x, y);

//         int dis2 = getDis(a, x);

//         int dis3 = dis - dis2;

//         int dis4 = dis2 + loopLen - dis3;
//         if( (k - dis >= 0) && (k - dis) % loopLen == 0 ) return true;
//         if( (k - dis4 >= 0) && (k - dis4) % loopLen == 0 ) return true;
//         return false;
//     } else {
//         bool fain = isIn(a, b, fa2, fa);
//         // bool yin = isIn(a, b, fa2, y);
//         if(fain) {
//             if( (k - dis >= 0) && (k - dis) % loopLen == 0 ) return true;
//             return false;
//         } else {
//             if(k == dis) return true; 
//             else return false;
//         }
//     }

// };


bool solve(int x, int y, int a, int b, int k) {
    auto ok = [&](int dis) {
        if(k >= dis && (k - dis) % 2 == 0) return true;
        else return false;
    };

    if( ok(getDis(a, b)) || ok(getDis(a, x) + 1 + getDis(y, b)) || ok(getDis(a, y) + 1 + getDis(x, b)) ) return true;
    else return false;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(head, -1, sizeof(head)); tot = 0;

        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }

        bfs(1);

        int q;
        scanf("%d", &q);
        while(q --) {
            int x, y, a, b, k;
            scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);
            printf("%s\n", solve(x, y, a, b, k) ? "YES" : "NO");
        }
    }
    return 0;
}

/*


5
1 2
2 3
3 4
4 5
5
1 3 1 2 2
1 4 1 3 2
1 4 1 3 3
4 2 3 3 9
5 2 3 3 9


*/