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
int n;
map<int, int> Ledge;
struct Node{
    int l, r;
} E[MAXN];
int ans[MAXN];
struct Pode{
    int p, id, ty;
};

bool cmp(Node &A, Node &B) {
    if(A.l != B.l) return A.l < B.l;
    else return A.r > B.r;
}

bool cmp2(Pode &A, Pode &B) {
    return A.p < B.p;
}

int getLength() {
    int end = -INF;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(end < E[i].l) {
            ans ++;
            Ledge[E[i].l] = 0;
        }
        end = max(end, E[i].r);
    }
    return ans;
}

int init() {
    int cnt=0;
    int L,R=-INF;
    for(int i=0;i<n;i++)
    {
        if(E[i].l>R)
        {
            if(R!=-INF)
                Ledge[L]=0;
            cnt++;
            L=E[i].l, R=E[i].r;
        }
        else
            R=max(R,E[i].r);
    }
    Ledge[L]=0;
    return cnt;
}

int main() {
    int T;
    int cnt = 0;
    scanf("%d", &T);
    int caseT = T;
    while(T --) {
        ++cnt;
        Ledge.clear();
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &E[i].l, &E[i].r);
            ans[i] = 0;
        }

        sort(E, E + n, cmp);

        int result = init();
        debug(result);

        vector<Pode> vc;
        for(int i = 0; i < n; ++i) {
            vc.push_back({E[i].l, i, 1});
            vc.push_back({E[i].r, i, -1});
        }

        sort(vc.begin(), vc.end(), cmp2);
        
        vector<vector<int> > group;
        vector<int> tmp; tmp.clear();
        for(int i = 0, len = vc.size(); i < len; ++i) {
            if(i == 0) tmp.push_back(i);
            else if(vc[i].p == vc[i-1].p) tmp.push_back(i);
            else {
                group.push_back(tmp);
                tmp.clear();
                tmp.push_back(i);
            }
        }
        group.push_back(tmp);
        debug(group);

        set<int> st;
        for(auto item_array : group) {
            vector<int> open;
            vector<int> close;
            for(auto item : item_array) {
                if(vc[item].ty == 1) open.push_back(item);
                else close.push_back(item);
            }
            debug("hhh", st, open, close);
            if( ( (int)st.size() == 1 ) &&  ( (int)open.size() > 0) ) {
                ans[*st.begin()] ++;
            }
            for(auto item : open) {
                st.insert(vc[item].id);
            }
            for(auto item : close) {
                st.erase(vc[item].id);
            }

            debug(st);
        }

        for(int i = 0; i < n; ++i) {
            debug(ans[i]);
            // maxx = max(ans[i], maxx);
        }

        for(int i = 0; i < n; ++i) {
            if(Ledge.count(E[i].l)) {
                Ledge[E[i].l] ++;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(Ledge.count(E[i].l) && Ledge[E[i].l] == 1) {
                ans[i] --;
            }
        }

        int maxx = -INF;
        for(int i = 0; i < n; ++i) {
            debug(ans[i]);
            maxx = max(ans[i], maxx);
        }
        // if(caseT == 10000) {
        //     if(cnt != 332) continue;
        //     printf("%d\n", n);
        //     for(int i = 0; i < n; ++i) {
        //         printf("%d %d\n", E[i].l, E[i].r);
        //     }
        // }
        // else 
        printf("%d\n", maxx + result);
    }
    return 0;
}

/*

10000
4
-2 -2
-1 2
-1 1
2 2
4
-3 -1
-2 4
-1 0
-4 1

*/