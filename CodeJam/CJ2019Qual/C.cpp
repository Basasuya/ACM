#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <iomanip>
using namespace std;
const int N = 7005;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
typedef long long ll;


ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
ll seq[105];
ll prime[105];
ll tag[105];
vector<ll> num;
int main() {
    
    // while(1) {
    //     ll a, b;
    //     scanf("%lld %lld", &a, &b);
    //     printf("%lld\n", gcd(a, b));
    // }
    int _;
    scanf("%d", &_);
    for(int cas = 1; cas <= _; ++cas) {
        memset(tag, 0, sizeof(tag));
        num.clear();
        int n, l;
        scanf("%d %d", &n, &l);
        
        for(int i = 0; i < l; ++i) {
            scanf("%lld", &seq[i]);
        }

        for(int i = 1; i < l; ++i) {
            if(seq[i] == seq[i-1]) {
                continue;
            }
            tag[i] = 1;
            prime[i] = gcd(seq[i], seq[i-1]);
        }
        int pos = -1;
        for(int i = 1; i < l; ++i) {
            if(tag[i] == 1) {
                pos = i;
            }
        }
        
        for(int i = pos - 1; i >= 0; --i) {
            prime[i] = seq[i] / prime[i + 1];
        }
        for(int i = pos + 1; i <= l; ++i) {
            prime[i] = seq[i-1] / prime[i-1];
        }

        // prime[0] = seq[0] / prime[1];
        // prime[l] = seq[l - 1] / prime[l-1];

        for(int i = 0; i <= l; ++i) {
            num.push_back(prime[i]);
        }
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        
        // assert(num.size() == 26);
        // printf("%d\n", (int)num.size());
        // for(int i = 0, len = num.size(); i < len; ++i) printf("%lld ", num[i]); printf("\n");
  

        printf("Case #%d: ", cas);

        for(int i = 0; i <= l; ++i) {
            int tt = lower_bound(num.begin(), num.end(), prime[i]) - num.begin();
            printf("%c", tt + 'A');
        } printf("\n");
    
    }
    return 0;
}

/*
2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543

  


Output 
 
Case #1: CJQUIZKNOWBEVYOFDPFLUXALGORITHMS
Case #2: SUBDERMATOGLYPHICFJKNQVWXZ




*/
