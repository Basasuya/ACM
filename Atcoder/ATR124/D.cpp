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
    int N, K;
    while(~scanf("%d %d", &N, &K)) {
        scanf("%s",seq);
        vector<pair<int, int> > feet;
        pair<int, int> unit = make_pair(-1, -1);
        for(int i = 0, len = strlen(seq); i < len; ++i) {
            if(seq[i] == '0') {
                if(unit.first == -1) unit.first = i;
                unit.second = i;
            } else {
                if(unit.first != -1) feet.push_back(unit);
                unit = make_pair(-1, -1);
            }
        }
        if(unit.first != -1) feet.push_back(unit);

        int result = -1;
        for(int i = 0, len = max(1, (int)feet.size() - K + 1) ; i < len; ++i) {
            int start = i;
            int end = min((int)feet.size() - 1, i + K - 1);
            int from = (start == 0) ? -1 : feet[start - 1].second;
            int to = (end == feet.size() - 1) ? (N - 1) : (feet[end + 1].first - 1);
            result = max(result, to - from);
        }
        printf("%d\n", result);
    }
    return 0;
}