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

const int lim = 1000*1000 + 5;
int nbElem, nbSub;
vector<int> subset[lim];
int side[lim];
int isIn[lim][2];
string ini;
int rep = 0;

int drepr[lim]; 
int dsz[lim];
int cnt[lim][2];

int dfind(int x)
{
    if (drepr[x] != x) drepr[x] = dfind(drepr[x]);
    return drepr[x];
}

void add(int cc, int s0, int s1)
{
    cc = dfind(cc);
    rep -= min(cnt[cc][0], cnt[cc][1]);
    cnt[cc][0] = min(lim, cnt[cc][0] + s0);
    cnt[cc][1] = min(lim, cnt[cc][1] + s1);
    rep += min(cnt[cc][0], cnt[cc][1]);
}

void dmerge(int a, int b)
{
    a = dfind(a); b = dfind(b);
    if (a == b) return;
    if (dsz[a] < dsz[b]) swap(a,b);
    add(a, cnt[b][0], cnt[b][1]);
    add(b, -cnt[b][0], -cnt[b][1]);
    dsz[a] += dsz[b];
    drepr[b] = a;
}

void dfs(int nod)
{
    cnt[nod][side[nod]] = 1;
    for (int elem : subset[nod]) {
	    if (isIn[elem][1] == -1) continue;
	    int oth = isIn[elem][0] + isIn[elem][1] - nod;
        debug(nod, oth, side[nod], side[oth]);
	    if (side[oth] == -1) {
		    side[oth] = side[nod] ^ (ini[elem] == '0');
		    dfs(oth);
	    }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> nbElem >> nbSub;
    cin >> ini;
    fill(side,side+lim,-1);
    iota(drepr,drepr+lim,0);
    fill_n(&isIn[0][0], 2*lim, -1);

    for (int sub = 0; sub < nbSub; ++sub) {
	    int st; cin >> st;
	    subset[sub].resize(st);
	    for (int pos = 0; pos < st; ++pos) {
		    int elem; cin >> elem; --elem;
		    subset[sub][pos] = elem;
		    if (isIn[elem][0] == -1) isIn[elem][0] = sub;
		    else isIn[elem][1] = sub;
	    }
    }

    for (int sub = 0; sub < nbSub; ++sub) {
	    if (side[sub] == -1) {
		    side[sub] = 0;
		    dfs(sub);
	    }
    }

    printf("side: "); for(int sub = 0; sub < nbSub; ++sub) { printf("%d ", side[sub]); } printf("\n");


    for (int elem = 0; elem < nbElem; ++elem) {
	    int n0 = isIn[elem][0], n1 = isIn[elem][1];
	    if (n0 != -1 && n1 == -1) {
		    int destroy = side[n0] ^ (ini[elem] == '0');
            debug(destroy, elem, n0, n1);
		    if (destroy == 1) add(n0, 0, lim);
		    else add(n0, lim, 0);	
	    } else if (n0 != -1) {
		    dmerge(n0, n1);
	    }
	    cout << rep << "\n";
    }
}


/*


7 3
0011100
3
1 4 6
3
3 4 7
2
2 3

*/