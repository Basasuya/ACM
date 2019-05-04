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

int judge(int x) {
    int tmp = x;
    int cnt = 0; int cntOne = 0;
    while(tmp) {
        if(tmp % 2) cntOne ++;
        cnt ++;
        tmp /= 2;
    }
    if(cnt == cntOne) return -100;
    else return cnt;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int x;
    while(~scanf("%d", &x)) {
        vector<int> result;
        int tmp = judge(x);
        if(tmp == -100) {
            printf("0\n");
            continue;
        }

        int answer = 0;
        while(1) {
            // printf("%d\n", tmp);
            result.push_back(tmp);
            x ^= (1 << tmp) - 1;
            answer ++;
            tmp = judge(x);
            
            if(tmp == -100) break;

            x = x + 1;
            answer ++;
            tmp = judge(x);
            if(tmp == -100) break;
        }
        assert(answer < 40);
        printf("%d\n", answer);
        for(int i = 0, len = result.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}