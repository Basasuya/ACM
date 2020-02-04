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

void solve(int num) {
    // int num = 3;
    map<int, vector<int> > mp;
    for(int i = 0; i < 1<<num; ++i) {
        int tt = bitCount(i);
        mp[tt].push_back(i);
    }
    
    auto bit = [&](int x) {
        string ans;
        for(int i = num - 1; i >= 0; --i) {
            ans += ( (x >> i) & 1 ) + '0';
        }
        return ans;
    };

    // for(auto& item : mp) {
    //     vector<int> & vc = item.second;
    //     for(int i = 0, len = vc.size(); i < len; ++i) {
    //         printf("%s ", bit(vc[i]).c_str());
    //     }
    //     printf("\n");
    // }

    int cnt = 0;

    for(auto& item : mp) {
        vector<int> & vc = item.second;
        for(int i = 0, len = vc.size(); i < len; ++i) {
            // int tt = vc[i];
            bool suc = true;
            // debug("hhhhh", bit(vc[i]));
                
            for(int j = 0, len2 = vc.size(); j < len2 && suc; ++j) {
                if(i == j) continue;
                // debug(i, j, vc[j]);

                bool ok = false;
                for(int k = 1; k < num && !ok; ++k) {
                    int t1 = vc[i] >> k; int t2 = vc[i] & ( (1 << k) - 1);
                    int _t1 = vc[j] >> k; int _t2 = vc[j] & ( (1 << k) - 1);
                    // debug(k, bit(vc[i]), bit(t1), bit(t2), bit(vc[j]), bit(_t1), bit(_t2));
                    if(bitCount(_t1) == bitCount(t1) && bitCount(t2)== bitCount(_t2) ) {
                        ok = true;
                        break;
                    }
                }
                if(ok == false) {
                    suc = false;
                    break;
                } 
            }
            
            if(suc == true) {
                printf("succcess ! %s\n", bit(vc[i]).c_str());
                cnt ++;
            }
        }
    }
    
    if(num >= 3) {
        int tt = 2 * ( ( 1<<(num -2) ));
        debug(cnt,  tt);
    }
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        solve(n);
    }
    return 0;
}