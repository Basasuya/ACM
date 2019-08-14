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

const int MAXN = 1e5 + 5;

int n;
int A[MAXN];
int has[MAXN];
int B[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        memset(has, 0, sizeof(has));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
            has[max(1, i - A[i])] ++;
            has[min(n + 1, i + A[i] + 1)] --;
        }
        for(int i = 1; i <= n; ++i) {
            has[i] += has[i-1];
        }
        // for(int i = 1; i <= n; ++i) {
        //     printf("%d\n", has[i]);
        // }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &B[i]);
        } 
        sort(has + 1, has + n + 1);
        sort(B + 1, B + n + 1);
        bool flag = true;
        for(int i = 1; i <= n; ++i) {
            if(B[i] != has[i]) {
                flag = false;
                break;
            } 
        } 
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}