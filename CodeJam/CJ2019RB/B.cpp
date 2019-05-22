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


int man[105];
vector<int> st[25];
int main() {
    int T;
    srand((unsigned)time(NULL));
    scanf("%d", &T);
    while(T --) {
        
        memset(man, -1, sizeof(man));
        vector<pair<int, int> > vc;
        
        for(int i = 1; i <= 20; ++i) {
            int round; scanf("%d", &round);
            printf("%d 0\n", i); fflush(stdout);
            int n; scanf("%d", &n);
            for(int j = 0; j < n; ++j) {
                int tt; scanf("%d", &tt);
                if(man[tt] < 0) man[tt] = i;
            }
        }
        for(int i = 1; i <= 20; ++i) st[i].clear();
        for(int i = 1; i <= 100; ++i) {
            if(man[i] != -1) st[man[i]].push_back(i);
            else {
                int tt = rand() % 20 + 1;
                st[tt].push_back(i);
            }
        }
        vc.clear();
        for(int i = 1; i <= 20; ++i) {
            vc.push_back({st[i].size(), i});
        }
        sort(vc.begin(), vc.end());
        int choose = *st[vc[19].second].begin();
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }
        choose = *(st[vc[19].second].begin() ++);
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }

        for(int i = 1; i <= 20; ++i) {
            int round; scanf("%d", &round);
            printf("%d 0\n", i); fflush(stdout);
            int n; scanf("%d", &n);
            for(int j = 0; j < n; ++j) {
                int tt; scanf("%d", &tt);
                if(man[tt] < 0) man[tt] = i;
            }
        }
        for(int i = 1; i <= 20; ++i) st[i].clear();
        for(int i = 1; i <= 100; ++i) {
            if(man[i] != -1) st[man[i]].push_back(i);
            else {
                int tt = rand() % 20 + 1;
                st[tt].push_back(i);
            }
        }
        vc.clear();
        for(int i = 1; i <= 20; ++i) {
            vc.push_back({st[i].size(), i});
        }
        sort(vc.begin(), vc.end());
        choose = *st[vc[19].second].begin();
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }
        choose = *(st[vc[19].second].begin() ++);
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }


        for(int i = 1; i <= 20; ++i) {
            int round; scanf("%d", &round);
            printf("%d 0\n", i); fflush(stdout);
            int n; scanf("%d", &n);
            for(int j = 0; j < n; ++j) {
                int tt; scanf("%d", &tt);
                if(man[tt] < 0) man[tt] = i;
            }
        }
        for(int i = 1; i <= 20; ++i) st[i].clear();
        for(int i = 1; i <= 100; ++i) {
            if(man[i] != -1) st[man[i]].push_back(i);
            else {
                int tt = rand() % 20 + 1;
                st[tt].push_back(i);
            }
        }
        vc.clear();
        for(int i = 1; i <= 20; ++i) {
            vc.push_back({st[i].size(), i});
        }
        sort(vc.begin(), vc.end());
        choose = *st[vc[19].second].begin();
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }
        choose = *(st[vc[19].second].begin() ++);
        for(int i = 1; i <= 5; ++i) {
            int round; scanf("%d", &round);
            printf("%d %d\n", vc[i].second, choose); fflush(stdout);
        }


        for(int i = 1; i <= 9; ++i) {
            int round; scanf("%d", &round);
            printf("%d 0\n", i); fflush(stdout);
            int n; scanf("%d", &n);
            for(int j = 0; j < n; ++j) {
                int tt; scanf("%d", &tt);
                if(man[tt] < 0) man[tt] = i;
            }
        }

        // for(int i = 1; i <= 4; ++i) {
        //     int round; scanf("%d", &round);
        //     printf("%d 0\n", i); fflush(stdout);
        //     int n; scanf("%d", &n);
        //     for(int j = 0; j < n; ++j) {
        //         int tt; scanf("%d", &tt);
        //         if(man[tt] < 0) man[tt] = i;
        //     }
        // }
        
        for(int i = 1; i <= 20; ++i) st[i].clear();
        for(int i = 1; i <= 100; ++i) {
            if(man[i] != -1) st[man[i]].push_back(i);
            else {
                int tt = rand() % 20 + 1;
                st[tt].push_back(i);
            }
        }

        vc.clear();
        for(int i = 1; i <= 20; ++i) {
            vc.push_back({st[i].size(), i});
        }
        sort(vc.begin(), vc.end());
        choose = vc[0].second;

        int round; scanf("%d", &round); 
        printf("%d 100\n", choose); fflush(stdout);
    }
    return 0;
}