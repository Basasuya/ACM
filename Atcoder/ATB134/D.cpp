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

const int MAXN = 2e5 + 5;
int a[MAXN];
int b[MAXN];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        // memset(b, 0, sizeof(b))
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }

        for(int i = n; i >= 1; --i) {
            int sum = 0;
            for(int j = 2 * i; j <= n; j += i) {
                sum += b[j];
            }
            sum %= 2;
            b[i] = sum ^ a[i];
        }
        
        vector<int> result;

        for(int i = 1; i <= n; ++i) {
            if(b[i]) {
                result.push_back(i);
            }
        }

        printf("%d\n", (int)result.size());
        if(!result.empty()) {
            for(int i = 0, len = result.size(); i < len; ++i) {
                if(i) printf(" ");
                printf("%d", result[i]);
            }
            printf("\n");
        }


    }
    return 0;
}