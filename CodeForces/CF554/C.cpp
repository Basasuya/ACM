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

ll a, b;
ll result = 1e18; ll answer;
ll gcd(ll x, ll y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

void solve(ll x) {
    ll tt = (a / x + (a % x != 0)) * x;
    // printf("%lld %lld\n", x, tt);
    ll tmp = (tt + (b - a)) * tt / gcd((tt + (b - a)), tt);
    if(tmp < result) {
        result = tmp;
        answer = tt - a;
    }
}

int main() {
    
    while(~scanf("%lld %lld", &a, &b)) {
        result = 1e18;
        if(a > b) swap(a, b);
        if(a == b) {
            printf("0\n");
            continue;
        }

        ll tt = b - a;
        for(ll i = 1; i <= sqrt(tt); ++i) {
            if(tt % i == 0) {
                solve(i);
                if(i * i != tt) solve(tt / i);
            }
        }


        printf("%lld\n", answer);
    }
    return 0;
}
/*

3431515 2135142
*/