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

const int N = 400005;
int isPrime[N]; 
int Prime[N];
int primeTot;
int main() {
    primeTot = 0;
    isPrime[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!isPrime[i]) {
            Prime[++primeTot] = i;
        }
        for(int j = 2*i; j < N; j += i) {
            isPrime[j] = 1;
        }
    }
    int n;
    while(~scanf("%d", &n)) {
        int two = 0; int one = 0;
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            if(x % 2 == 0) two ++;
            else one ++;
        }

        vector<int> result;
        if(one >= 1 && two >= 1) {
            result.push_back(2);
            result.push_back(1);
            for(int i = 0; i < two - 1; ++i) result.push_back(2);
            for(int i = 0; i < one - 1; ++i) result.push_back(1);
        } else {
            for(int i = 0; i < two; ++i) result.push_back(2);
            for(int i = 0; i < one; ++i) result.push_back(1);
        }


        for(int i = 0, len = result.size(); i < len; ++i) {
            if(i) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}