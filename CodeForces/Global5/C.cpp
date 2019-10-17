#include <iostream>
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

const int MAXN = 50005;
struct Node{
    int arr[3];
    int tag;
    Node() {}
    Node(const Node &A) {
        arr[0] = A.arr[0];
        arr[1] = A.arr[1];
        arr[2] = A.arr[2];
        tag = A.tag;
        // debug("hhh");
    }
};
vector<pair<int, int> > ans;
int cmp(Node &A, Node &B) {
    if(A.arr[0] != B.arr[0]) return A.arr[0] < B.arr[0];
    else if(A.arr[1] != B.arr[1]) return A.arr[1] < B.arr[1];
    else return A.arr[2] < B.arr[2];
} 

vector<Node> origin; 
int solve(vector<Node> & vc, int step) {
    

    vector<Node> tmp;
    vector<int> result;
    tmp.push_back(vc[0]);
    for(int i = 1, len  = vc.size(); i < len; ++i) {
        if(vc[i].arr[step] == vc[i-1].arr[step]) {
            tmp.push_back(vc[i]);
        } else {
            if(tmp.size() == 1) result.push_back(tmp[0].tag);
            else {
                // if(tmp.size() % 2) {
                //     result.push_back(tmp[tmp.size() - 1].tag);
                //     tmp.pop_back();
                // }
                int tag = solve(tmp, step + 1);
                if(tag != -1) result.push_back(tag);
            }
            tmp.clear();
            tmp.push_back(vc[i]);
        }
    }

    if(tmp.size() == 1) result.push_back(tmp[0].tag);
    else {
        int tag = solve(tmp, step + 1);
        if(tag != -1) result.push_back(tag);
    }

    for(int i = 0, len = result.size(); i + 1 < len; i += 2) {
        ans.push_back(mp(result[i], result[i + 1]));
    }
    if(result.size() % 2) return result[result.size() - 1];
    else return -1;
}

// int has[MAXN];
// bool inn(int x, int y, int z, vector<Node> &vc) {
//     if(y == x || y == z) return false;
//     else {
//         bool suc = true;
//         for(int i = 0; i < 3; ++i) {
//             int t1 = vc[x - 1].arr[i]; int t2 = vc[y - 1].arr[i]; int t3 = vc[z - 1].arr[i];
//             if(t1 > t3) swap(t1, t3);
//             if(t1 <= t2 && t2 <= t3);
//             else {
//                 suc = false; break;
//             }
//         }
//         return suc;
//     }
// } 
int main() {
    int n;
    while(~scanf("%d", &n)) {
        ans.clear();
        vector<Node> vc;
        
        origin.clear();
        // memset(has, 0, sizeof(has));
        
        for(int i = 0; i < n; ++i) {
            Node tmp;
            scanf("%d %d %d", &tmp.arr[0], &tmp.arr[1], &tmp.arr[2]);
            tmp.tag = i + 1;
            vc.push_back(tmp);
            origin.push_back(tmp);
        }

        sort(vc.begin(), vc.end(), cmp);

        solve(vc, 0);

        for(int i = 0, len = ans.size(); i < len; ++i) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        //     for(int j = 1; j <= n; ++j) {
        //         if(has[j] == 0 && inn(ans[i].first, j, ans[i].second, origin)) {
        //             debug("false", j); break;
        //         }
        //     }
        //     has[ans[i].first] = 1;  has[ans[i].second] = 1; 
        }
    }
    return 0;
}