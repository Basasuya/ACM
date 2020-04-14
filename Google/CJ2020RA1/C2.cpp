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
#define all(a) a.begin(), a.last()
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


struct Node{
    int u, d, l, r;
    int val;
    Node() {
        u = d = l = r = -1; val = 0;
    }
};
vector<Node> mp;
int R, C;

int getId(int x, int y) { return x * (C + 2) + y; }

void erase(int x) {
   mp[mp[x].l].r = mp[x].r;
   mp[mp[x].r].l = mp[x].l;
   mp[mp[x].u].d = mp[x].d;
   mp[mp[x].d].u = mp[x].u;
   mp[x].val = 0;
}


vector<int> update(vector<int> &choosList, ll &ans, ll &origin) {
    // debug(origin);
    
    vector<int> needErase;
    vector<int> newList, _newList;
    ans += origin;
    for(int i = 0, len = choosList.size(); i < len; ++i) {
        int x = choosList[i];
        int neiNum = 0; int neiVal = 0; 
        if(mp[mp[x].r].val != 0) { neiNum ++; neiVal += mp[mp[x].r].val; }
        if(mp[mp[x].l].val != 0) { neiNum ++; neiVal += mp[mp[x].l].val; }
        if(mp[mp[x].u].val != 0) { neiNum ++; neiVal += mp[mp[x].u].val; }
        if(mp[mp[x].d].val != 0) { neiNum ++; neiVal += mp[mp[x].d].val; }
        
        // debug(x / (C + 2), x % (C + 2), neiVal, neiNum, mp[x].val);
        if(neiVal > mp[x].val * neiNum) { 
            // debug("erase", x / (C + 2), x % (C + 2));
            origin -= mp[x].val; 
            needErase.push_back(x);
            
        }
    }
    
    for(auto x : needErase) {
        assert(mp[x].r != -1); assert(mp[x].l != -1); assert(mp[x].u != -1); assert(mp[x].d != -1);
        if(mp[mp[x].r].val != 0) { _newList.push_back(mp[x].r); }
        if(mp[mp[x].l].val != 0) { _newList.push_back(mp[x].l); }
        if(mp[mp[x].u].val != 0) { _newList.push_back(mp[x].u); }
        if(mp[mp[x].d].val != 0) { _newList.push_back(mp[x].d); }
        erase(x);
    }

    for(auto it : _newList) {
        if(mp[it].val != 0) newList.push_back(it);
    }
    sort(newList.begin(), newList.end());
    newList.erase(unique(newList.begin(), newList.end()), newList.end());
    
    // for(int i = 0, len = newList.size(); i < len; ++i) printf("%d %d: ", newList[i] / (C + 2), newList[i] % (C + 2)); printf("\n");

    return newList;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        mp.clear();
        scanf("%d %d", &R, &C);
        mp.resize( (R + 5) * (C + 5), Node());

        ll origin = 0;
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                scanf("%d", &mp[getId(i , j)].val);
                origin += mp[getId(i , j)].val;
            }
        }

        for(int i = 1; i <= R; ++i) {
            mp[getId(i , 1)].l = getId(i, 0);
            for(int j = 1; j <= C; ++j) {
                mp[getId(i , j - 1)].r = getId(i, j);
                mp[getId(i , j + 1)].l = getId(i, j);
            }
            mp[getId(i , C)].r = getId(i, C + 1);
        }
        
        for(int i = 1; i <= C; ++i) {
            mp[getId(1 , i)].u = getId(0, i);
            for(int j = 1; j <= R; ++j) {
                mp[getId(j - 1, i)].d = getId(j, i);
                mp[getId(j + 1, i)].u = getId(j, i);
            }
            mp[getId(R, i)].d = getId(R + 1, i);
        }
        
        vector<int> choosList;
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                choosList.push_back(getId(i, j));
            }
        }

        

        ll ans = 0;
        while(1) {
            choosList = update(choosList, ans, origin);
            if(choosList.size() == 0) break;
        }

        printf("Case #%d: %lld\n", cas, ans);

    }
    return 0;
}

/*


4
1 1
15
3 3
1 1 1
1 2 1
1 1 1
1 3
3 1 2
1 3
1 2 3


3 3
1 100 1
1 2 2
1000 1 1
1 3
1 1
*/