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
#define mp make_pair
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

// typedef long long ll;
const int Maxn = 100000;

struct Node {
	int t;
	int id;
};
bool cmp(Node lhs, Node rhs) {return lhs.t == rhs.t ? lhs.id < rhs.id : lhs.t < rhs.t;}

int N, P;
Node A[Maxn + 5];
queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;
ll ans[Maxn + 5];

int main() {
#ifdef LOACL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d %d", &N, &P);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i].t);
		A[i].id = i;
	}
	sort(A + 1, A + N + 1, cmp);
	ll now = 0;
	int last = N + 1;
	for(int i = 1; i <= N;) {
        // assert(q1.size() <= 1);
        debug(A[i].t, A[i].id, last, now);
		if(!q1.empty()) {
			int id = q1.front();
			q1.pop();
            debug("pop p1 ", id);
			ans[id] = now + P;
			now += P, last = id;
		} else if(A[i].t <= now) {
			if(q1.empty() && A[i].id < last) {
                debug("push p1 choose1: ", A[i].id);
				q1.push(A[i].id);
			} else {
                debug("push p2: ", A[i].id);
                q2.push(A[i].id);
            }
			i++;
		} else {
			if(!q2.empty()) {
				int id = q2.top();
				q2.pop();
                debug("pop p2 ", id);
				ans[id] = now + P;
				now += P, last = id;
			} else now = A[i].t, last = N + 1;
		}
	}
	while(!q1.empty()) {
		int id = q1.front();
        debug("pop p1 ", id);
		q1.pop(), ans[id] = now + P;
		now += P;
	}
	while(!q2.empty()) {
		int id = q2.top();
        debug("pop p2 ", id);
		q2.pop(), ans[id] = now + P;
		now += P;
	}
	for(int i = 1; i <= N; i++)
		printf("%lld ", ans[i]);
    printf("\n");
	return 0;
}
