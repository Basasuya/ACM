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

const int MAXN = 1e5 + 5;

struct Node{
    int id;
    int sa, ea, sb, eb;
    Node(int a=0, int b=0, int c=0, int d=0, int e=0):id(a), sa(b), ea(c), sb(d), eb(e){};
}lec[MAXN];

int cmp1(const Node &A, const Node &B) {
    if(A.sa != B.sa) return A.sa < B.sa;
    else return A.ea < B.ea;
}

int cmp2(const Node &A, const Node &B) {
    if(A.sb != B.sb) return A.sb < B.sb;
    else return A.eb < B.eb;
}

int tree[MAXN << 2];
int treesize;
vector<int> treePre;
int get(int x) { 
    debug("get", x);
    int tt = lower_bound(treePre.begin(), treePre.end(), x) - treePre.begin(); 
    return tt + 1; 
}
int sum(int x) {
    if(x > treesize) x = treesize;
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= x & -x;
    }
    return ans;
}
void add(int x, int d) {
    debug(x, d);
    while(x <= treesize) {
        tree[x] += d;
        x += x & -x;
    }
}



int main() {
    int n;
    while(~scanf("%d", &n)) {
        treePre.clear();
        for(int i = 0; i < n; ++i) {
            lec[i].id = i;
            scanf("%d %d %d %d", &lec[i].sa, &lec[i].ea, &lec[i].sb, &lec[i].eb);

            treePre.push_back(lec[i].sa);
            treePre.push_back(lec[i].sb);
            treePre.push_back(lec[i].ea + 1);
            treePre.push_back(lec[i].eb + 1);
        }

        sort(treePre.begin(), treePre.end());
        treePre.erase(unique(treePre.begin(), treePre.end()), treePre.end());
        treesize = treePre.size() + 5;
        
        

        bool suc = false;
        set<int> st; 
        // set<int> st2; 


        sort(lec, lec + n, cmp1);
        int point = n;
        for(int i = 0; i <= treesize; ++i) tree[i] = 0;
        
        for(int i = n-1; i >= 0 && !suc; --i) {
            int tt = lower_bound(lec, lec + n, Node(0,lec[i].ea + 1,0,0,0), cmp1) - lec;
            debug(tt, lec[i].sa, lec[i].ea);
            while(point > tt) {
                point --;
                debug("insert ", lec[point].sb);
                st.insert(lec[point].sb);
                st.insert(lec[point].eb);
                add(get(lec[point].sb), 1);
                add(get(lec[point].eb + 1), -1);
            }

            auto tt2 = st.lower_bound(lec[i].sb);
            if(tt2 != st.end()) debug("yingyingying");
            if(tt2 != st.end() && ( (*tt2) <= lec[i].eb || sum(get(lec[i].sb)) > 0) ) suc = true;
        }

        sort(lec, lec + n, cmp2);
        point = n;
        st.clear();
        for(int i = 0; i <= treesize; ++i) tree[i] = 0;
        for(int i = n-1; i >= 0 && !suc; --i) {
            int tt = lower_bound(lec, lec + n, Node(0,0,0,lec[i].eb + 1,0), cmp2) - lec;

            while(point > tt) {
                point --;
                st.insert(lec[point].sa);
                st.insert(lec[point].ea);
                add(get(lec[point].sa), 1);
                add(get(lec[point].ea + 1), -1);
            }

            auto tt2 = st.lower_bound(lec[i].sa);
            if(tt2 != st.end() && ( (*tt2) <= lec[i].ea || sum(get(lec[i].sa)) > 0) ) suc = true;
        }



        printf("%s\n", suc ? "NO" : "YES");
    }
    return 0;
}


/*

2
1 2 2 3
4 5 1 2
2
1 2 2 3
4 5 2 5
*/