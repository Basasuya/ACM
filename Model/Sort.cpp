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

void updateDown(vector<int> &vc, int pos, int end) {
    int dad = pos;
    int son = dad * 2 + 1;
    while(son <= end) {
        if(son + 1 <= end && vc[son] < vc[son + 1]) son ++;
        if(vc[dad] > vc[son])
            return;
        else {
            swap(vc[dad], vc[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void updateUp(vector<int> &vc, int pos, int end) {
    int son = pos;
    int dad = (son - 1) / 2;
    while(son > 0) {
        int anotherSon = (dad * 2 + 1 == son) ?  dad * 2 + 2 : dad * 2 + 1;
        if(anotherSon <= end && vc[son] <= vc[anotherSon]) return;
        else if(vc[son] > vc[dad]) {
            swap(vc[son], vc[dad]);
            son = dad;
            dad = (son - 1) / 2;
        } else return;
    } 
}

vector<int> HeapSort(vector<int> &vc) {
    vector<int> ans = vc;
    int n = ans.size();


    for(int i = n / 2 - 1; i >= 0; --i) {
        updateDown(ans, i, n - 1);
    }

    for(int i = n - 1; i > 0; --i) {
        swap(ans[0], ans[i]);
        updateDown(ans, 0, i - 1);
    }
    return ans;
}




void quicksort(vector<int> &vc, int l, int r) {
    if(l >= r) return;

    int choose = rand() % (r - l + 1) + l;
    swap(vc[l], vc[choose]);

    int flag = l + 1;
    for(int i = l + 1; i <= r; ++i) {
        if(vc[i] <= vc[l]) {
            swap(vc[flag], vc[i]);
            flag ++;
        }
    }
    swap(vc[l], vc[flag - 1]);

    quicksort(vc, l, flag - 2); quicksort(vc, flag, r);
}

int main() {
    vector<int> vc = {1, 6, 5, 3, 4, 2, 8, 5, 100};
    
    // debug(HeapSort(vc));


    quicksort(vc, 0, vc.size() - 1);
    debug(vc);
}