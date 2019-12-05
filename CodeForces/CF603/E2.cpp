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


struct MyStack {
    int cnt = 0;
    int allOpens = 0;
    stack<int> s;
    stack<int> minValue;
    stack<int> maxValue;

    void push(int x) {
        s.push(x);
        cnt += x;
        if (x == 1) {
            allOpens += 1;
        }
        minValue.push((minValue.size() ? min(minValue.top(), cnt) : cnt));
        maxValue.push((maxValue.size() ? max(maxValue.top(), cnt) : cnt));
        // debug(s.top, minValue.top, maxValue.top)
    }

    void pop() {
        if (s.size() == 0) {
            return;
        }
        cnt -= s.top();
        if (s.top() == 1) {
            allOpens -= 1;
        }
        s.pop();
        minValue.pop();
        maxValue.pop();
    }

    int top() {
        return s.top();
    }

    bool isCorrect() {
        return (minValue.size() == 0 || minValue.top() >= 0);
    }

    int depth() {
        return (maxValue.size() ? maxValue.top() : 0);
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    MyStack left, right;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        right.push(0);
    }
    left.push(0);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (pos != 0) {
                pos--;
                right.push(-left.top());
                left.pop();
            }
        } else if (s[i] == 'R') {
            pos++;
            left.push(-right.top());
            right.pop();
        } else if (s[i] == '(') {
            left.pop();
            left.push(1);
        } else if (s[i] == ')') {
            left.pop();
            left.push(-1);
        } else {
            left.pop();
            left.push(0);
        }
        if (left.isCorrect() && right.isCorrect() && left.cnt == right.cnt) {
            cout << max({left.depth(), right.depth(), left.cnt}) << " ";
        } else {
            cout << "-1 ";
        }
    }
}

/*

8
(R(R(LLL



*/