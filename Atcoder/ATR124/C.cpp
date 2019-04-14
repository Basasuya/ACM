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
#include <string>
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

const int N = 1e5 + 5;
char seq[N];
int main() {
    while(~scanf("%s", seq)) {
        int ans1 = 0, ans2 = 0;
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            char c = i % 2 ? '0' : '1';
            if(seq[i] == c)
                ans1 ++;
            else ans2 ++;
        }

        printf("%d\n", min(ans1, ans2));
    }
    return 0;
}