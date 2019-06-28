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

const long long ten10 = 1e10;
const long long ten12 = 1e12;

void solve(long long x, set<pair<ll, ll> >& st) {
    debug(st);
    auto it = st.upper_bound(make_pair(x, ten12)); --it;
    // printf("%lld %lld\n", it->first, it->second);
    // exit(0);


    
    ll t1 = it->first;
    ll t2 = it->second;
    st.erase(it);
    {
        ll start = t1; ll end = x - 1;
        if(start <= end) st.insert(make_pair(start, end));
    }
    {
        ll start = x + ten10; ll end = t2;
        if(start <= end) st.insert(make_pair(start, end));
    }
    
}

int main() {
    int T, W;
    
    
    scanf("%d %d", &T, &W); 
    // printf("%lld\n", ten12);
    for(int cas = 1; cas <= T; ++cas) {
        set<pair<ll, ll> > st;
        st.insert(make_pair(1ll, ten12));

        while(1) {
            ll x; scanf("%lld", &x);
            
            // if(x == -1) exit(0);
            if(x < 0) break;
            solve(x, st);
            // int result = 0;
            vector<pair<ll, ll> > vc;
            for(auto it: st) {
                ll tmp = (it.second - it.first + 1) / ten10;
                if(tmp > 0) vc.push_back(make_pair(it.second - it.first + 1, it.first));
                // result += tmp;
            }

            sort(vc.begin(), vc.end());
            ll t1 = vc[vc.size() - 1].first; ll t2 = vc[vc.size() - 1].second;
            if(t1 >= ten10 * 3) {
                printf("%lld\n", t2 + ten10 * 2); fflush(stdout);
                solve(t2 + ten10 * 2, st);
            } else if(t1 > ten10 * 2) {
                printf("%lld\n", t2 + ten10 - 1); fflush(stdout);
                solve(t2 + ten10 - 1, st);
            } else {
                if(vc.size() % 2 == 0 || t1 == ten10) {
                    printf("%lld\n", t2); fflush(stdout);
                    solve(t2, st);
                } else {
                    printf("%lld\n", t2 + 1); fflush(stdout);
                    solve(t2 + 1, st);
                }
            }


            // printf("hhh\n");

            // bool ok = true;
            // if(result % 2 == 0) {
            //     for(auto it = st.begin(); it != st.end(); ++it) {
            //         // printf("t1: %lld %lld\n", it->first, it->second);
            //         ll tmp = (it->second - it->first + 1) / ten10;
            //         if(tmp > 1) {
                        
            //             printf("%lld\n", it->first + ten10 - 1); fflush(stdout);
            //             solve(it->first + ten10 - 1, st);
            //             ok = false;
            //             break;
            //         } 
            //     }
            // }

            // if(ok == true) {
            //     for(auto it: st) {
            //         // printf("t2: %lld %lld\n", it.first, it.second);
            //         ll tmp = (it.second - it.first + 1) / ten10;
            //         if(tmp > 0) {
                        
            //             printf("%lld\n", it.first); fflush(stdout);
            //             solve(it.first, st);
            //             ok = true;
            //             break;
            //         } 
            //     }
            // }
            // printf("hhh\n");


            
        }

        // printf("Case #%d: %d\n", cas, );
    }
    return 0;
}