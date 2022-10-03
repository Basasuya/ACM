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

int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        vector<string> vc;
        int n;
        scanf("%d", &n);

        bool tag = false;

        for(int i = 0; i < n; ++i) {
            char tmp[5];
            scanf("%s", tmp);
            vc.push_back(tmp);
            
            if (strlen(tmp) == 1) {
                tag = true;
            } else if (strlen(tmp) == 2 && tmp[0] == tmp[1]) {
                tag = true;
            } else if (strlen(tmp) == 3 && tmp[0] == tmp[2]) {
                tag = true;
            }
        }

        if (tag == true) {
            printf("YES\n"); continue;
        }

        map<string, int> mp;
        for(int i = 0; i < n && !tag; ++i) {
            debug(i);
            int str_len = vc[i].length();
            string first_two, last_two;
            first_two.clear(); first_two += vc[i][1]; first_two += vc[i][0]; 
            last_two.clear(); last_two += vc[i][str_len - 2]; last_two += vc[i][str_len - 1]; 
            
            if (mp.find(last_two) != mp.end()) {
                tag = true; break;
            }
            
            if(str_len == 2) mp[first_two] = 1;
        }

        mp.clear();
        for(int i = n - 1; i >= 0 && !tag; --i) {
            debug(i);
            int str_len = vc[i].length();
            string first_two, last_two;
            first_two.clear(); first_two += vc[i][1]; first_two += vc[i][0]; 
            last_two.clear(); last_two += vc[i][0]; last_two += vc[i][1]; 
            
            if (mp.find(last_two) != mp.end()) {
                tag = true; break;
            }
            
            if(str_len == 2) mp[first_two] = 1;
        }   
        
        mp.clear();
        for(int i = 0; i < n && !tag; ++i) {
            // debug(i);
            int str_len = vc[i].length();
            if (str_len != 3) continue;

            string first_two;
            first_two.clear(); first_two += vc[i][2]; first_two += vc[i][1]; first_two += vc[i][0]; 
            
            if (mp.find(vc[i]) != mp.end()) {
                tag = true; break;
            }
            
            mp[first_two] = 1;
        }


        if (tag == true) {
            printf("YES\n");
        } else printf("NO\n");
    }
    return 0;
}