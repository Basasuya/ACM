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

void add(vector<pair<int, int> >& vc, int pre, int target, int times) {
    // debug(pre, target, vc);
    int dir = 0;
    if( times % 2 == 0) dir = 0; else dir = 1;
    int preX = -1, preY = 0;
    if(vc.size() != 0) {
        preX = vc.back().first; preY = vc.back().second;
    }


    int needFloor = target - pre - 1;
    if(needFloor == 0) {
        vc.push_back(dir ? MP(preX + 1, preY + 1) : MP(preX + 1, preY));
        for(int i = 0; i < target; ++i) {
            vc.push_back(dir ? MP(vc.back().first, vc.back().second - 1) : MP(vc.back().first, vc.back().second + 1));
        }
    } else {
        vc.push_back(dir ? MP(preX + 1, preY + 1) : MP(preX + 1, preY));
        int count = 2;
        for(int i = 0; i < needFloor - 1; ++i) {
            int tmp_count = count - 1; int now_dir = (i & 1) ^ (needFloor & 1) ^ dir;
            vc.push_back(now_dir ? MP(vc.back().first + 1, vc.back().second + 1) : MP(vc.back().first + 1, vc.back().second));
            while(tmp_count --) {
                vc.push_back(now_dir ? MP(vc.back().first, vc.back().second - 1) : MP(vc.back().first, vc.back().second + 1));
            }   
            count ++;
        }
        vc.push_back(dir ? MP(vc.back().first + 1, vc.back().second) : MP(vc.back().first + 1, vc.back().second + 1));
        for(int i = 0; i < target - count + 1; ++i) {
            vc.push_back(dir ? MP(vc.back().first, vc.back().second - 1) : MP(vc.back().first, vc.back().second + 1));
        }
    }

}



int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);

        vector<pair<int, int> > vc;

        int floor = -1; int cnt = 0; int times = 0;
        while(n) {
            if(n & 1) {
                add(vc, floor, cnt, times);
                times ++;
                floor = cnt;
            }
            cnt ++;
            n /= 2;
        }
        assert((int)vc.size() < 500);
        printf("Case #%d: \n", cas);
        for(int i = 0, len = vc.size(); i < len; ++i) {
            printf("%d %d\n", vc[i].first + 1, vc[i].second + 1);
        }
    }
    return 0;
}