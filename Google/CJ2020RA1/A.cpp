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

char seq[55][105];

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", seq[i]);
        }

        vector<string> front, last;
        string mid_result;
        for(int i = 0; i < n; ++i) {
            int len = strlen(seq[i]);
            vector<string> split;
            string tmp;
            if(seq[i][0] == '*') split.push_back("");
            for(int j = 0; j < len; ++j) {
                // cout << seq[i][j] << endl;
                if(seq[i][j] == '*') { 
                    if((int)tmp.size() != 0) split.push_back(tmp);
                    tmp.clear();
                } else tmp += seq[i][j];
            }
            if((int)tmp.size() != 0) split.push_back(tmp);
            // debug(split);
            if(seq[i][len - 1] == '*') split.push_back("");

            front.push_back(split[0]); last.push_back(split.back());
            if(split.size() > 2) {
                for(int j = 1, split_len = split.size(); j < split_len - 1; ++j) {
                    mid_result += split[j];
                }
            } 
        }

        auto cmp = [](string &A, string &B) { return A.size() < B.size(); };
        sort(front.begin(), front.end(), cmp);
        sort(last.begin(), last.end(), cmp);

        // debug(front, last, mid_result);

        bool suc = true;

        for(int i = 0, len = front.size(); i < len - 1 && suc; ++i) {
            string &now = front[i]; string &tem = front.back();
            for(int j = 0, len_now = now.size(); j < len_now && suc; ++j) {
                if(now[j] != tem[j]) { suc = false; }
            }
        }

        // debug(suc);

        for(int i = 0, len = last.size(); i < len - 1 && suc; ++i) {
            string &now = last[i]; string &tem = last.back(); int len_tem = tem.size();
            for(int j = 0, len_now = now.size(); j < len_now && suc; ++j) {
                if(now[j] != tem[len_tem + j - len_now]) { 
                    // debug(now, tem, j); 
                    suc = false; 
                }
            }
        }

        string result = front.back() + mid_result + last.back();

        printf("Case #%d: ", cas);
        if(suc == false) printf("*\n");
        else printf("%s\n", result.c_str());
    }
    return 0;
}

/*


2
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ


*/