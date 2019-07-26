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


char mp[4][10];

int has[10][3];
int main() {
    memset(has, 0, sizeof(has));
    for(int i = 0; i < 3; ++i) {
        scanf("%s", mp[i]);
        if(mp[i][1] == 'm') {
            has[mp[i][0] - '0'][0] ++;
        } else if(mp[i][1] == 'p') {
            has[mp[i][0] - '0'][1] ++;
        } else {
            has[mp[i][0] - '0'][2] ++;
        }
    }

    int result = 1;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(has[j][i] == 1 && has[j + 1][i] == 1 && has[j + 2][i] == 1) {
                result = max(result, 3);
            }
            if( (has[j][i] > 0) + (has[j + 1][i] > 0) + (has[j + 2][i] > 0) == 2) {
                result = max(result, 2);
            }
        }
    }

    for(int j = 0; j < 10; ++j) {
        int tmp = max(max(has[j][0], has[j][1]),has[j][2]);
        result = max(result, tmp);
    }

    printf("%d\n", 3 - result);




    return 0;
}