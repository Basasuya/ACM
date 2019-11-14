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

const int MAXN = 75005;
vector<int> graph[MAXN];
vector<int> group[MAXN];
int dfn[MAXN], low[MAXN];
int dcnt;
int col[MAXN + 5], ccnt;
bool vis[MAXN + 5];
int stk[MAXN + 5], tp;
vector<pair<int, int>> dp[32768];

void Tarjan_scc(int u) {
	dfn[u] = ++dcnt, low[u] = dcnt, vis[u] = true;
	stk[++tp] = u;
	for(int i = 0; i < (int)graph[u].size(); i++) {
		int v = graph[u][i];
		if(!dfn[v]) {
			Tarjan_scc(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) low[u] = min(low[u], low[v]);
	}
	if(dfn[u] == low[u]) {
		++ccnt;
		while(true) {
			col[stk[tp]] = ccnt;
			vis[stk[tp]] = false;
			if(stk[tp--] == u)
				break;
		}
	}
}


int main() {
    int k;
    while(~scanf("%d", &k)) {
        tp = -1; ccnt = 0; dcnt = 0;
        for(int i = 0; i < MAXN; ++i) {
            dfn[i] = 0;
            graph[i].clear();
            group[i].clear();
        }

        vector<ll> sum;
        vector<pair<int, int> > vc;
        map<ll, pair<int, int> > mp;

        int tot = 0;
        ll allSum = 0;
        for(int i = 0; i < k; ++i) {
            int x; scanf("%d", &x);
            ll tmpSum = 0;
            for(int j = 0; j < x; ++j) {
                int y; scanf("%d", &y);
                vc.push_back(make_pair(y, i));
                mp[y] = make_pair(tot, i);
                tot ++;
                tmpSum += y;
            }
            sum.push_back(tmpSum);
            allSum += tmpSum;
        }
        // debug(allSum);

        if(allSum % k) {
            printf("No\n");
            continue;
        } 

        allSum /= k;
        set<int> selfCircle;
        set<pair<int, int>> hasEdge;

        // debug(allSum);
        for(int i = 0, len = vc.size(); i < len; ++i) {
            ll searchNum = allSum - sum[vc[i].second] + vc[i].first;
            if(mp.find(searchNum) == mp.end()) continue;
            else if( mp[searchNum].second == vc[i].second && mp[searchNum].first != i) {
                // solve specfial condition
                continue;
            } else if(mp[searchNum].first == i) {
                // debug(i);
                selfCircle.insert(i);
            }

            graph[i].push_back(mp[searchNum].first);
            hasEdge.insert(make_pair(i, mp[searchNum].first));

            debug(i, mp[searchNum].first);
        }

       
        for(int i = 0; i < tot; ++i) {
            if(!dfn[i]) Tarjan_scc(i);
        } 

        for(int i = 0; i < tot; ++i) {
            // printf("%d ", col[i]);
            group[col[i]].push_back(i);
        }
        // printf("\n");

        for(int i = 1; i <= ccnt; ++i) {
            // debug(i, group[i].size());
            if(group[i].size() == 1 && selfCircle.count(group[i][0])) {
                int id = group[i][0];
                vector<pair<int, int> > tmpPair;
                tmpPair.push_back(make_pair(vc[id].first, vc[id].second + 1));
                dp[1<<vc[id].second] = tmpPair;
                // debug(dp[1<<vc[id].second]);
            }
            else if(group[i].size() > 1) {
                vector<pair<int, int> > tmpPair;
                int tmp = 0;
                int len = group[i].size();
                bool suc = true;
                for(int j = 0; j < len; ++j) {
                    int to = group[i][j];
                    if(tmp & (1<<vc[to].second)) { suc = false; break; }
                    tmp |= 1<<vc[to].second;
                }
                if(suc == false) {
                    continue;
                }
                
                for(int j = 0; j < len; ++j) {
                    for(int k = 0; k < len; ++k) {
                        int fr = group[i][j]; int to = group[i][k];
                        if(hasEdge.count(make_pair(fr, to))) {
                            tmpPair.push_back(make_pair(vc[to].first, vc[fr].second + 1));
                        }
                    }
                }

                dp[tmp] = tmpPair;
                // debug(dp[tmp], tmp);
            }
        }

        for(int i = 0; i < (1<<k); ++i) {
            for (int s=(i-1)&i; s; s=(s-1)&i) {
                int t = i ^ s;
                if(dp[s].size() > 0 && dp[t].size() > 0) {
                    dp[i] = dp[s];
                    dp[i].insert(dp[i].end(), dp[t].begin(), dp[t].end());
                    break;
                }
            }
        }

        auto cmp = [&](pair<int, int> &A, pair<int, int> &B) {
            return mp[A.first].second < mp[B.first].second;
        };

        int end = (1<<k) - 1;
        if(dp[end].size() > 0 ) {
            printf("Yes\n");
            // debug(dp[end]);
            sort(dp[end].begin(), dp[end].end(), cmp);
            for(int i = 0; i < k; ++i) {
                printf("%d %d\n", dp[end][i].first,  dp[end][i].second);
            }
        } else printf("No\n");
        
    }
    return 0;
}